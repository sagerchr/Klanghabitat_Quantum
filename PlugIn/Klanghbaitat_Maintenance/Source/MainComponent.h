#pragma once

#include <JuceHeader.h>
#include "SrecConverter.h"
#include "SRC_ListBox.h"
#include "Comunication.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component,public juce::Button::Listener, public juce::FilenameComponentListener, public juce::URL::DownloadTask::Listener,  public juce::OSCReceiver::Listener<juce::OSCReceiver::MessageLoopCallback>
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked (juce::Button* button) override;
    void finished (juce::URL::DownloadTask* task, bool success) override;
    void filenameComponentChanged (juce::FilenameComponent* fileComponentThatHasChanged) override;
    void oscMessageReceived (const juce::OSCMessage& message) override;
    juce::StringArray parseSrec(juce::String DisplayData);
private:
    //==============================================================================
    // Your private member variables go here...
   
  
    Comunication Bootloader;
    double percentage=0.0;
    double *progress=&percentage;
    juce::URL::DownloadTask::Listener* listen1;
    juce::URL::DownloadTask::Listener* listen2;
    std::unique_ptr<juce::URL::DownloadTask> downladDisplaySrec;
    std::unique_ptr<juce::URL::DownloadTask> downladMotherEngineSrec;    
    juce::TextButton updateButton;
    juce::TextButton showString;
    
    juce::Label timeLabel;
    juce::ProgressBar progressBar{*progress};

    juce::OSCReceiver oscReceiver;
    juce::ComboBox deviceList {"select the dedicated device"};

    SRC_ListBox SRC_ListBox_Display;
    SRC_ListBox SRC_ListBox_MainEngine;
    
    juce::String Device_IPAdress;
    juce::String TargetIP;
    
    juce::Label TextLabel{ {}, "Hello" };
    juce::Label DisplayLabel{ {}, "Display parsed" };
    juce::Label MainEngineLabel{ {}, "MainEngine parsed" };
    
    juce::Array<juce::String> deviceListArray;
    juce::Array<juce::IPAddress> allIpAdresses;
    juce::Array<juce::String> myIPAdressesArray;

    juce::String DisplayData;
    juce::String MainEngineData;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
