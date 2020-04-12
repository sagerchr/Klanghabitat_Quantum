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
 version:          1.0.0
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

        connectButton.setBounds (210, 18, 100, 25);
        addAndMakeVisible (connectButton);
        connectButton.onClick = [this] { connectButtonClicked(); };

        clearButton.setBounds (320, 18, 60, 25);
        addAndMakeVisible (clearButton);
        clearButton.onClick = [this] { clearButtonClicked(); };

        connectionStatusLabel.setBounds (450, 18, 240, 25);
        updateConnectionStatusLabel();
        addAndMakeVisible (connectionStatusLabel);

        setSize (700, 400);
    }

private:
    //==============================================================================
    Label portNumberLabel    { {}, "UDP Port Number: " };
    Label portNumberField    { {}, "9001" };
    TextButton connectButton { "Connect" };
    TextButton clearButton   { "Clear" };
    Label connectionStatusLabel;

    //==============================================================================
    void connectButtonClicked() {}

    //==============================================================================
    void clearButtonClicked() {}

    //==============================================================================
    void oscMessageReceived (const OSCMessage&) override {}
    void oscBundleReceived (const OSCBundle&) override {}

    //==============================================================================
    void connect() {}

    //==============================================================================
    void disconnect() {}

    //==============================================================================
    void handleConnectError (int) {}

    //==============================================================================
    void handleDisconnectError() {}

    //==============================================================================
    void handleInvalidPortNumberEntered() {}

    //==============================================================================
    bool isConnected() const             { return false; }

    //==============================================================================
    bool isValidOscPort (int) const      { return false; }

    //==============================================================================
    void updateConnectionStatusLabel()
    {
        String text = "Status: Disconnected";

        auto textColour = Colours::red;

        connectionStatusLabel.setText (text, dontSendNotification);
        connectionStatusLabel.setFont (Font (15.00f, Font::bold));
        connectionStatusLabel.setColour (Label::textColourId, textColour);
        connectionStatusLabel.setJustificationType (Justification::centredRight);
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
