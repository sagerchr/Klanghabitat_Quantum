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
    
    Label Device_Incoming_Message{ {}, "" };
    
    Waveform waveform_left;
    Waveform waveform_right;
    
    Slider Attack, Release, Ratio, Threshold, InGain, OutGain;
    Label AttackLabel, ReleaseLabel, RatioLabel, ThresholdLabel, InGainLabel, OutGainLabel;
    
    ComboBox deviceList {"select the dedicated device"};
    TextButton connectButton   {};
    
    Label stringToTarget;
    Label Watchdog;
    
    Array<String> deviceListArray;
    Array<IPAddress> allIpAdresses;
    Array<String> myIPAdressesArray;
    
    ConnectionAnimation animation;
    
    bool listen;
    bool connected;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KlanghabitatConnectorAudioProcessorEditor)
};



