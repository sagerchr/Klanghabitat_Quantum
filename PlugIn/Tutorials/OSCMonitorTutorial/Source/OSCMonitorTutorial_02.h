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
#include "ListBoxClass.h"


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
                                private Timer,
                               private OSCReceiver::Listener<OSCReceiver::MessageLoopCallback>
                              
{
public:

    //==============================================================================
    MainContentComponent()
    {
        portNumberLabel.setBounds (10, 600, 130, 25);
        addAndMakeVisible (portNumberLabel);
        
        portNumberField.setEditable (true, true, true);
        portNumberField.setBounds (140, 600, 50, 25);
        addAndMakeVisible (portNumberField);
        portNumberField.onTextChange= [this] { portNumberFieldVvalueChanged(); };
        
        
        openPortButton.setBounds (200, 600, 100, 25);
        addAndMakeVisible (openPortButton);
        openPortButton.onClick = [this] { openPortButtonClicked(); };

        clearButton.setBounds (310, 600, 60, 25);
        addAndMakeVisible (clearButton);
        clearButton.onClick = [this] { clearButtonClicked(); };

        connectionStatusLabel.setBounds (10, 620, 240, 25);
        updateConnectionStatusLabel();
        addAndMakeVisible (connectionStatusLabel);

        oscLogListBox.setBounds (10, 40, 355, 100);
        addAndMakeVisible (oscLogListBox);
        
        oscLogListBox2.setBounds (10, 150, 355, 100);
        addAndMakeVisible (oscLogListBox2);
        
        
        
        
        deviceList.setBounds (10, 650, 150, 25);
        addAndMakeVisible (deviceList);
        
        sendButton.setBounds (200, 650, 100, 25);
        addAndMakeVisible (sendButton);
        sendButton.onClick = [this] { sendButtonClicked(); };
        
        
        oscStreamer.addListener(this);
        oscReceiver.addListener (this);
        
        oscReceiver.registerFormatErrorHandler ([this] (const char* data, int dataSize)
                                                {
                                                    oscLogListBox.addInvalidOSCPacket (data, dataSize);
                                                });

        for (int i = 0; i<50; i++){
            FFT_Left[i] = -80.0f;
        }
        
        for (int i = 0; i<300; i++){
           ch1_array[i] = 0;
        }
        
        startTimer(10);
        
        setSize (375, 700);
        
        
        
        
    }

private:
    //==============================================================================
    Label portNumberLabel    { {}, "UDP Port Number: " };
    Label portNumberField    { {}, "9010" };
    TextButton openPortButton { "open port" };
    TextButton clearButton   { "Clear" };
    TextButton sendButton   { "connect" };
    Label connectionStatusLabel;
    ComboBox deviceList {"select the dedicated device"};
       
    OSCLogListBox oscLogListBox;
    OSCLogListBox oscLogListBox2;
    
    
    OSCReceiver oscStreamer;
    OSCReceiver oscReceiver;
   
    
    OSCSender sender;
    
    String Device_IPAdress;
    int CH1=0;
    int CH2=0;
    
    int ch1_array[300];
    
    float FFT_Left[100];
    float FFT_Left_raw[100];

    
    float band0 = 0.0f;
    float band1 = 0.0f;
    float band2 = 0.0f;
    float band3 = 0.0f;
    float band4 = 0.0f;
    float band5 = 0.0f;
    float band6 = 0.0f;
    float band7 = 0.0f;
    float band8 = 0.0f;
    float band9 = 0.0f;
    float band9_untouched = 0.0f;
    int currentPortNumber = -1;
    int k=0;
    //==============================================================================
  
    
    void timerCallback() override
       {
        repaint();
       }
    
    
    
    
    void openPortButtonClicked()
    {
        if (! isConnected()){
            openPort();
            updateConnectionStatusLabel();
            auto IpAllAdress = juce::IPAddress::getAllAddresses();
            int i = 0;
            
            while (IpAllAdress[i].toString() != "0.0.0.0"){
                
                deviceList.addItem (IpAllAdress[i].toString(), i+1);
                i++;
            }
        }
        
        else
        {
            closePort();
            deviceList.clear();
            updateConnectionStatusLabel();

        }
        
        
    }

    void sendButtonClicked()
    {
        sender.connect (Device_IPAdress, 9011);
        auto IpAdress = juce::IPAddress::getLocalAddress().toString();

        IpAdress = deviceList.getItemText(deviceList.getSelectedId()-1);
        sender.send ("/connection", (String) IpAdress);
       //sender.send ("/connection", (String) "192.168.1.44");
        
       oscStreamer.connect(9002);
       sendButton.setButtonText ("disconect");
    }
    
    
    
    
    
    //==============================================================================
    void clearButtonClicked()
    {
        oscLogListBox.clear();
        oscLogListBox2.clear();
    }

    
    void portNumberFieldVvalueChanged()
    {
        oscLogListBox.clear();
    }

    //==============================================================================
    void oscMessageReceived (const OSCMessage& message) override
    {
   
        
        k++;
       
        
        //==========================Get Ip Adress of target========================//
        if (message.getAddressPattern().toString() == "/klanghabitat/DeviceInfo"){
            oscLogListBox.addOSCMessage (message);
            //Device_IPAdress = message.getArguments();
            for (auto* arg = message.begin(); arg != message.end(); ++arg)
                Device_IPAdress = arg->getString().substring(0, 15);
        }
        //=========================================================================//
        else{
            //oscLogListBox2.addOSCMessage (message);
            
            if (message.getAddressPattern().toString() == "/VALUE/Level/CH1/RMS"){
            for (auto* arg = message.begin(); arg != message.end(); ++arg)
                CH1 = arg->getInt32();
                
                for (int i =0; i<300;i++){
                    ch1_array [i] = ch1_array [i+1];
                }
                
                ch1_array [299] = CH1;
            }
            if (message.getAddressPattern().toString() == "/VALUE/Level/CH2/RMS"){
            for (auto* arg = message.begin(); arg != message.end(); ++arg)
                CH2 =  arg->getInt32();
            }
            
            String FFT_Left_Adresses[50] = {"/FFT/LEFT/00","/FFT/LEFT/01","/FFT/LEFT/02","/FFT/LEFT/03","/FFT/LEFT/04","/FFT/LEFT/05","/FFT/LEFT/06","/FFT/LEFT/07","/FFT/LEFT/08","/FFT/LEFT/09",
                "/FFT/LEFT/10","/FFT/LEFT/11","/FFT/LEFT/12","/FFT/LEFT/13","/FFT/LEFT/14","/FFT/LEFT/15","/FFT/LEFT/16","/FFT/LEFT/17","/FFT/LEFT/18","/FFT/LEFT/19",
                "/FFT/LEFT/20","/FFT/LEFT/21","/FFT/LEFT/22","/FFT/LEFT/23","/FFT/LEFT/24","/FFT/LEFT/25","/FFT/LEFT/26","/FFT/LEFT/27","/FFT/LEFT/28","/FFT/LEFT/29",
                "/FFT/LEFT/30","/FFT/LEFT/31","/FFT/LEFT/32","/FFT/LEFT/33","/FFT/LEFT/34","/FFT/LEFT/35","/FFT/LEFT/36","/FFT/LEFT/37","/FFT/LEFT/38","/FFT/LEFT/39",
                "/FFT/LEFT/40","/FFT/LEFT/41","/FFT/LEFT/42","/FFT/LEFT/43","/FFT/LEFT/44","/FFT/LEFT/45","/FFT/LEFT/46","/FFT/LEFT/47","/FFT/LEFT/48","/FFT/LEFT/49",
                };
            
          for (int i=0; i<50; i++){

              if (message.getAddressPattern().toString() == FFT_Left_Adresses[i]){
                         for (auto* arg = message.begin(); arg != message.end(); ++arg)
                             FFT_Left_raw[i] =arg->getFloat32();
                             FFT_Left[i] =  (20 * log10 (FFT_Left_raw[i]/100))-50;
                         }
              
              
          }

        }
            
    }

    
    
    void paint (Graphics& g) override
{
    int yposition=500;
    int middlepoint=400;
    int xPosition = 30;
    
   // g.fillAll (Colours::darkgrey);
    g.setColour (Colours::orange);
 
    g.fillRect (10, 10, CH1, 10);
    g.fillRect (10, 21, CH2, 10);
    
    for(int i = 0; i<50; i++){
        if (FFT_Left[i]<= -100.0){FFT_Left[i]=100.0;}
       g.fillRect (xPosition+10+(6*i), yposition+abs((int)FFT_Left[i]), 4, 100 - abs((int)FFT_Left[i]));
    }
    
     
    for(int i = 0; i<300; i++){
       g.fillRect (i+xPosition, middlepoint - (ch1_array [i]/2), 1,  ch1_array [i]+1);
    }

}
    
    
    
    void oscBundleReceived (const OSCBundle& bundle) override
    {
        oscLogListBox.addOSCBundle (bundle);
    }

    void connectToTarget(){
        
    }
    
    
    
    
    //==============================================================================
    void openPort()
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
            openPortButton.setButtonText ("close port");
        }
        else
        {
            handleConnectError (portToConnect);
        }
    }

    //==============================================================================
    void closePort()
    {
        if (oscReceiver.disconnect())
        {
            oscStreamer.disconnect ();
            currentPortNumber = -1;
            openPortButton.setButtonText ("open port");
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
        connectionStatusLabel.setJustificationType (Justification::centredLeft);
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
