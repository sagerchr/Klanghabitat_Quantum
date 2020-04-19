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
#include "GUI Classes/OSCListBoxClass.h"
#include "GUI Classes/WaveForm.h"

//==============================================================================


//==============================================================================
class MainContentComponent   : public Component,
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
                
        wellenform1.setBounds (37, 270, 310, 100);
        addAndMakeVisible (wellenform1);
        
        wellenform2.setBounds (37, 400, 310, 100);
        addAndMakeVisible (wellenform2);

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
    
    Waveform wellenform1;
    Waveform wellenform2;
    
    String Device_IPAdress;
    
    int CH1=0;
    int CH2=0;
    
    int ch1_array[300];
    
    float FFT_Left[100];
    float FFT_Left_raw[100];

    int currentPortNumber = -1;
    int k=0;
    //==============================================================================
  
    
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
            for (auto* arg = message.begin(); arg != message.end(); ++arg)
                Device_IPAdress = arg->getString().substring(0, 15);
        }
        //=========================================================================//
        else{
                       
            if (message.getAddressPattern().toString() == "/VALUE/Level/CH1/RMS"){

                    for (auto* arg = message.begin(); arg != message.end(); ++arg)
                    wellenform1.addSample(arg->getInt32());

            }
            
            if (message.getAddressPattern().toString() == "/VALUE/Level/CH2/RMS"){

                    for (auto* arg = message.begin(); arg != message.end(); ++arg)
                    wellenform2.addSample(arg->getInt32());
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
