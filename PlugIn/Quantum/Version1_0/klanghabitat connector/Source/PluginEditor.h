/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUI Classes/OSCListBoxClass.h"
#include "GUI Classes/WaveForm.h"
#include "GUI Classes/ConnectedAnimation.h"
//==============================================================================
/**
*/
class KlanghabitatConnectorAudioProcessorEditor  : public AudioProcessorEditor, public OSCReceiver::Listener<OSCReceiver::MessageLoopCallback>, public Timer
{
public:
    KlanghabitatConnectorAudioProcessorEditor (KlanghabitatConnectorAudioProcessor&);
    
    
    ~KlanghabitatConnectorAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void oscMessageReceived (const OSCMessage& message)override;
    void timerCallback() override;
    void connectButtonClicked();
    void connectTarget();
    void disconnectTarget();
    
    void MSButtonClicked();
    void MS_SignalButtonClicked();
    void LeftBypassButtonClicked();
    void RightBypassButtonClicked();
    void ListenMidButtonClicked();
    void ListenSideButtonClicked();
    
    
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    KlanghabitatConnectorAudioProcessor& processor;
    
    OSCLogListBox OSCBoxDeviceInfo;
    OSCLogListBox OSCBoxDownStream;

    
    OSCReceiver oscReceiver;
    OSCReceiver oscStreamer;
    
    OSCSender sender;
    
    String Device_IPAdress;
    String TargetIP;
    
    
    Label Device_Incoming_Message{ {}, "" };
    
    Waveform waveform_left;
    Waveform waveform_right;
    
    Slider Attack, Release, Ratio, Threshold, InGain, OutGain;
    Label AttackLabel, ReleaseLabel, RatioLabel, ThresholdLabel, InGainLabel, OutGainLabel;
    
    ComboBox deviceList {"select the dedicated device"};
    TextButton connectButton   {};
    
    TextButton MSButton           {};
    TextButton MS_SignalButton    {};
    TextButton LeftBypassButton   {};
    TextButton RightBypassButton  {};
    TextButton ListenMidButton    {};
    TextButton ListenSideButton   {};
    
    
    Label stringToTarget;
    Label Watchdog;
    
    Array<String> deviceListArray;
    Array<IPAddress> allIpAdresses;
    Array<String> myIPAdressesArray;
    
    ConnectionAnimation animation;
    
    bool listen;
    bool connected;
    
    bool MS_STERO_IN = 0;
    bool MS_STERO_OUT = 0;
    bool L_BYPASS = 0;
    bool R_BYPASS = 0;
    bool MID = 0;
    bool SIDE = 0;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KlanghabitatConnectorAudioProcessorEditor)
};



