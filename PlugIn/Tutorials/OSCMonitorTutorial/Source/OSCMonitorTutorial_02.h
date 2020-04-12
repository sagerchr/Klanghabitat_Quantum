/*
  ==============================================================================

   This file is part of the JUCE tutorials.
   Copyright (c) 2017 - ROLI Ltd.

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:             OSCMonitorTutorial
 version:          2.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Monitors incoming OSC messages.

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics, juce_osc
 exporters:        xcode_mac, vs2017, linux_make

 type:             Component
 mainClass:        MainContentComponent

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/


#pragma once

//==============================================================================
class OSCLogListBox    : public ListBox,
                         private ListBoxModel,
                         private AsyncUpdater
{
public:
    //==============================================================================
    OSCLogListBox()
    {
        setModel (this);
    }

    //==============================================================================
    int getNumRows() override
    {
        return oscLogList.size();
    }

    //==============================================================================
    void paintListBoxItem (int row, Graphics& g, int width, int height, bool rowIsSelected) override
    {
        ignoreUnused (rowIsSelected);

        if (isPositiveAndBelow (row, oscLogList.size()))
        {
            g.setColour (Colours::white);

            g.drawText (oscLogList[row],
                        Rectangle<int> (width, height).reduced (4, 0),
                        Justification::centredLeft, true);
        }
    }

    //==============================================================================
    void addOSCMessage (const OSCMessage& message, int level = 0)
    {
        oscLogList.add (getIndentationString (level)
                        + "- osc message, address = '"
                        + message.getAddressPattern().toString()
                        + "', "
                        + String (message.size())
                        + " argument(s)");
        
        
        if (! message.isEmpty())
        {
            for (auto* arg = message.begin(); arg != message.end(); ++arg)
                addOSCMessageArgument (*arg, level + 1);
        }

        triggerAsyncUpdate();
    }

    //==============================================================================
    void addOSCBundle (const OSCBundle& bundle, int level = 0)
    {
        OSCTimeTag timeTag = bundle.getTimeTag();

        oscLogList.add (getIndentationString (level)
                        + "- osc bundle, time tag = "
                        + timeTag.toTime().toString (true, true, true, true));

        for (auto* element = bundle.begin(); element != bundle.end(); ++element)
        {
            if (element->isMessage())
                addOSCMessage (element->getMessage(), level + 1);
            else if (element->isBundle())
                addOSCBundle (element->getBundle(), level + 1);
        }

        triggerAsyncUpdate();
    }

    //==============================================================================
    void addOSCMessageArgument (const OSCArgument& arg, int level)
    {
        String typeAsString;
        String valueAsString;

        if (arg.isFloat32())
        {
            typeAsString = "float32";
            valueAsString = String (arg.getFloat32());
        }
        else if (arg.isInt32())
        {
            typeAsString = "int32";
            valueAsString = String (arg.getInt32());
        }
        else if (arg.isString())
        {
            typeAsString = "string";
            valueAsString = arg.getString();
        }
        else if (arg.isBlob())
        {
            typeAsString = "blob";
            auto& blob = arg.getBlob();
            valueAsString = String::fromUTF8 ((const char*) blob.getData(), (int) blob.getSize());
        }
        else
        {
            typeAsString = "(unknown)";
        }

        oscLogList.add (getIndentationString (level + 1) + "- " + typeAsString.paddedRight(' ', 12) + valueAsString);
}

    //==============================================================================
    void addInvalidOSCPacket (const char* /* data */, int dataSize)
    {
        oscLogList.add ("- (" + String(dataSize) + "bytes with invalid format)");
    }

    //==============================================================================
    void clear()
    {
        oscLogList.clear();
        triggerAsyncUpdate();
    }

    //==============================================================================
    void handleAsyncUpdate() override
    {
        updateContent();
        scrollToEnsureRowIsOnscreen (oscLogList.size() - 1);
        repaint();
    }

private:
    //==============================================================================
    String getIndentationString (int level)
    {
        return String().paddedRight (' ', 2 * level);
    }

    //==============================================================================
    StringArray oscLogList;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OSCLogListBox)
};

//==============================================================================
class MainContentComponent   : public Component,
                               private OSCReceiver::Listener<OSCReceiver::MessageLoopCallback>
{
public:

    //==============================================================================
    MainContentComponent()
    {
        portNumberLabel.setBounds (10, 18, 130, 25);
        addAndMakeVisible (portNumberLabel);
        
        
        portNumberField.setEditable (true, true, true);
        portNumberField.setBounds (140, 18, 50, 25);
        addAndMakeVisible (portNumberField);
        portNumberField.onTextChange= [this] { portNumberFieldVvalueChanged(); };
        
        sendButton.setBounds (380, 18, 60, 25);
        addAndMakeVisible (sendButton);
        sendButton.onClick = [this] { sendButtonClicked(); };
        
        connectButton.setBounds (200, 18, 100, 25);
        addAndMakeVisible (connectButton);
        connectButton.onClick = [this] { connectButtonClicked(); };
        

        clearButton.setBounds (310, 18, 60, 25);
        addAndMakeVisible (clearButton);
        clearButton.onClick = [this] { clearButtonClicked(); };

        connectionStatusLabel.setBounds (450, 18, 240, 25);
        updateConnectionStatusLabel();
        addAndMakeVisible (connectionStatusLabel);

        oscLogListBox.setBounds (0, 60, 700, 940);
        addAndMakeVisible (oscLogListBox);

        oscReceiver.addListener (this);
        oscReceiver.registerFormatErrorHandler ([this] (const char* data, int dataSize)
                                                {
                                                    oscLogListBox.addInvalidOSCPacket (data, dataSize);
                                                });

        setSize (700, 1000);
    }

private:
    //==============================================================================
    Label portNumberLabel    { {}, "UDP Port Number: " };
    Label portNumberField    { {}, "9010" };
    TextButton connectButton { "open port" };
    TextButton clearButton   { "Clear" };
    TextButton sendButton   { "send" };
    Label connectionStatusLabel;

    OSCLogListBox oscLogListBox;
    OSCReceiver oscReceiver;

    OSCSender sender;
    
    int currentPortNumber = -1;

    //==============================================================================
    void connectButtonClicked()
    {
        if (! isConnected())
            connect();
        else
            disconnect();

        updateConnectionStatusLabel();
        
        
        sender.connect ("192.168.001.205", 9010);
    }

    void sendButtonClicked()
    {
        auto IpAdress = juce::IPAddress::getLocalAddress().toString();
        sender.send ("/connection", (String) IpAdress);
    }
    
    
    
    
    
    //==============================================================================
    void clearButtonClicked()
    {
        oscLogListBox.clear();
    }

    
    void portNumberFieldVvalueChanged()
    {
        oscLogListBox.clear();
    }

    //==============================================================================
    void oscMessageReceived (const OSCMessage& message) override
    {
        oscLogListBox.addOSCMessage (message);
    }

    void oscBundleReceived (const OSCBundle& bundle) override
    {
        oscLogListBox.addOSCBundle (bundle);
    }

    //==============================================================================
    void connect()
    {
        auto portToConnect = portNumberField.getText().getIntValue();

        if (! isValidOscPort (portToConnect))
        {
            handleInvalidPortNumberEntered();
            return;
        }

        if (oscReceiver.connect (portToConnect))
        {
            currentPortNumber = portToConnect;
            connectButton.setButtonText ("Disconnect");
        }
        else
        {
            handleConnectError (portToConnect);
        }
    }

    //==============================================================================
    void disconnect()
    {
        if (oscReceiver.disconnect())
        {
            currentPortNumber = -1;
            connectButton.setButtonText ("Connect");
        }
        else
        {
            handleDisconnectError();
        }
    }

    //==============================================================================
    void handleConnectError (int failedPort)
    {
        AlertWindow::showMessageBoxAsync (AlertWindow::WarningIcon,
                                          "OSC Connection error",
                                          "Error: could not connect to port " + String (failedPort),
                                          "OK");
    }

    //==============================================================================
    void handleDisconnectError()
    {
        AlertWindow::showMessageBoxAsync (AlertWindow::WarningIcon,
                                          "Unknown error",
                                          "An unknown error occured while trying to disconnect from UDP port.",
                                          "OK");
    }

    //==============================================================================
    void handleInvalidPortNumberEntered()
    {
        AlertWindow::showMessageBoxAsync (AlertWindow::WarningIcon,
                                          "Invalid port number",
                                          "Error: you have entered an invalid UDP port number.",
                                          "OK");
    }

    //==============================================================================
    bool isConnected() const
    {
        return currentPortNumber != -1;
    }

    //==============================================================================
    bool isValidOscPort (int port) const
    {
        return port > 0 && port < 65536;
    }

    //==============================================================================
    void updateConnectionStatusLabel()
    {
        String text = "Status: ";

        if (isConnected())
            text += "opend UDP port " + String (currentPortNumber);
        else
            text += "close port";

        auto textColour = isConnected() ? Colours::green : Colours::red;

        connectionStatusLabel.setText (text, dontSendNotification);
        connectionStatusLabel.setFont (Font (15.00f, Font::bold));
        connectionStatusLabel.setColour (Label::textColourId, textColour);
        connectionStatusLabel.setJustificationType (Justification::centredRight);
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
