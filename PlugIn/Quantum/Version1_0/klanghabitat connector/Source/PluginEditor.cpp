/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KlanghabitatConnectorAudioProcessorEditor::KlanghabitatConnectorAudioProcessorEditor (KlanghabitatConnectorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    
    
    //This instance is used for establishing the connection to target. It listens on port 9010
    oscReceiver.addListener(this);
    oscReceiver.connect (9010); //connect here the Reciver on startup so it will listen to the incumming DeviceInfo from Target
    
    //This instance is used for communicatiing with the target It listens on port 9002
    oscStreamer.addListener(this);
    oscStreamer.connect (9002); //connect here the Reciver on startup so it will listen to the incumming Downstream from Target
    
    waveform_left.setBounds (550, 50, 1010, 100);
    addAndMakeVisible (waveform_left);
    
    waveform_right.setBounds (550, 160, 1010, 100);
    addAndMakeVisible (waveform_right);
    
    Device_Incoming_Message.setBounds (10, 10, 130, 25);
    addAndMakeVisible(Device_Incoming_Message);
    
    OSCBoxDeviceInfo.setBounds(10, 50, 500, 210 );
    addAndMakeVisible (OSCBoxDeviceInfo);
    
    OSCBoxDownStream.setBounds(10, 280, 500, 200 );
    addAndMakeVisible (OSCBoxDownStream);
 
       
    Attack.setBounds(550, 300, 120, 120);
    Attack.setRange(0.1,30, 0.1f);
    Attack.setTextValueSuffix (" ms");
    Attack.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    Attack.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    addAndMakeVisible (Attack);
    AttackLabel.setText ("attack", dontSendNotification);
    AttackLabel.attachToComponent (&Attack, false);
    Attack.setColour (Slider::thumbColourId, Colours::orange);
    Attack.setColour (Slider::rotarySliderFillColourId, Colours::darkorange);
    AttackLabel.setJustificationType(Justification::horizontallyCentred);
    
    Release.setBounds(670, 300, 120, 120);
    Release.setRange(0.1,30, 0.1f);
    Release.setTextValueSuffix (" ms");
    Release.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    Release.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    addAndMakeVisible (Release);
    ReleaseLabel.setText ("release", dontSendNotification);
    ReleaseLabel.attachToComponent (&Release, false);
    Release.setColour (Slider::thumbColourId, Colours::orange);
    Release.setColour (Slider::rotarySliderFillColourId, Colours::darkorange);
    ReleaseLabel.setJustificationType(Justification::horizontallyCentred);
    
    Ratio.setBounds(790, 300, 120, 120);
    Ratio.setRange(0.1,30, 0.1f);
    Ratio.setTextValueSuffix (" ");
    Ratio.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    Ratio.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    addAndMakeVisible (Ratio);
    RatioLabel.setText ("ratio", dontSendNotification);
    RatioLabel.attachToComponent (&Ratio, false);
    Ratio.setColour (Slider::thumbColourId, Colours::orange);
    Ratio.setColour (Slider::rotarySliderFillColourId, Colours::darkorange);
    RatioLabel.setJustificationType(Justification::horizontallyCentred);
    
    Threshold.setBounds(910, 300, 120, 120);
    Threshold.setRange(0.1,30, 0.1f);
    Threshold.setTextValueSuffix (" dB");
    Threshold.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    Threshold.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    addAndMakeVisible (Threshold);
    ThresholdLabel.setText ("threshold", dontSendNotification);
    ThresholdLabel.attachToComponent (&Threshold, false);
    Threshold.setColour (Slider::thumbColourId, Colours::orange);
    Threshold.setColour (Slider::rotarySliderFillColourId, Colours::darkorange);
    ThresholdLabel.setJustificationType(Justification::horizontallyCentred);

    InGain.setBounds(1030, 300, 120, 120);
    InGain.setRange(0.1,30, 0.1f);
    InGain.setTextValueSuffix (" dB");
    InGain.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    InGain.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    addAndMakeVisible (InGain);
    InGainLabel.setText ("input gain", dontSendNotification);
    InGainLabel.attachToComponent (&InGain, false);
    InGain.setColour (Slider::thumbColourId, Colours::orange);
    InGain.setColour (Slider::rotarySliderFillColourId, Colours::darkorange);
    InGainLabel.setJustificationType(Justification::horizontallyCentred);
    
    OutGain.setBounds(1150, 300, 120, 120);
    OutGain.setRange(0.1,30, 0.1f);
    OutGain.setTextValueSuffix (" dB");
    OutGain.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    OutGain.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
    addAndMakeVisible (OutGain);
    OutGainLabel.setText ("output gain", dontSendNotification);
    OutGainLabel.attachToComponent (&OutGain, false);
    OutGain.setColour (Slider::thumbColourId, Colours::orange);
    OutGain.setColour (Slider::rotarySliderFillColourId, Colours::darkorange);
    OutGainLabel.setJustificationType(Justification::horizontallyCentred);
    
    
    MSButton.setBounds(550, 400, 120, 30);
    addAndMakeVisible (MSButton);
    MSButton.onClick = [this] { KlanghabitatConnectorAudioProcessorEditor::MSButtonClicked(); };
    MSButton.setButtonText ("MS/STERO IN (K5)");
    
    MS_SignalButton.setBounds(670, 400, 120, 30);
    addAndMakeVisible (MS_SignalButton);
    MS_SignalButton.onClick = [this] { KlanghabitatConnectorAudioProcessorEditor::MS_SignalButtonClicked(); };
    MS_SignalButton.setButtonText ("MS/STERO OUT (K6)");
    
    LeftBypassButton.setBounds(790, 400, 120, 30);
    addAndMakeVisible (LeftBypassButton);
    LeftBypassButton.onClick = [this] { KlanghabitatConnectorAudioProcessorEditor::LeftBypassButtonClicked(); };
    LeftBypassButton.setButtonText ("L BYPASS");
    
    RightBypassButton.setBounds(910, 400, 120, 30);
    addAndMakeVisible (RightBypassButton);
    RightBypassButton.onClick = [this] { KlanghabitatConnectorAudioProcessorEditor::RightBypassButtonClicked(); };
    RightBypassButton.setButtonText ("R BYPASS");
    
    ListenMidButton.setBounds(1030, 400, 120, 30);
    addAndMakeVisible (ListenMidButton);
    ListenMidButton.onClick = [this] { KlanghabitatConnectorAudioProcessorEditor::ListenMidButtonClicked(); };
    ListenMidButton.setButtonText ("MID (K8)");
    
    ListenSideButton.setBounds(1150, 400, 120, 30);
    addAndMakeVisible (ListenSideButton);
    ListenSideButton.onClick = [this] { KlanghabitatConnectorAudioProcessorEditor::ListenSideButtonClicked(); };
    ListenSideButton.setButtonText ("SIDE (K7)");
    
    
    
    

    //#######################Connection########################################################
    deviceList.setBounds(550,10,290,25);
    addAndMakeVisible(deviceList);
        
    connectButton.setBounds(850, 10, 200, 25);
    addAndMakeVisible(connectButton);
    connectButton.onClick = [this] { KlanghabitatConnectorAudioProcessorEditor::connectButtonClicked(); };
    connectButton.setButtonText ("connect to target");
    connectButton.setColour (TextButton::textColourOffId, Colours::darkorange);
    
    animation.setBounds (1055, 10, 50, 50);
    addAndMakeVisible(animation);
    animation.changeColour(Colours::orange);
    //#########################################################################################
    
    
    
    stringToTarget.setBounds(520, 460, 500, 25);
    addAndMakeVisible(stringToTarget);
    
    Watchdog.setBounds(620, 460, 500, 25);
    addAndMakeVisible(Watchdog);
    

    
    listen = false;
    
    startTimer(1000);
    
    setResizable (true, true);
    setSize (1600, 500);
}

KlanghabitatConnectorAudioProcessorEditor::~KlanghabitatConnectorAudioProcessorEditor()
{
    disconnectTarget();
    oscReceiver.disconnect();
}

//==============================================================================

void KlanghabitatConnectorAudioProcessorEditor::paint (Graphics& g)
{

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void KlanghabitatConnectorAudioProcessorEditor::resized()
{

}

void KlanghabitatConnectorAudioProcessorEditor::timerCallback() 
      {
          OSCBoxDownStream.clear();
          if(!listen){
             oscReceiver.connect (9010); //connect here the Reciver so it will listen to the incumming DeviceInfo from Target
             listen = true;
          }
          else{
              oscReceiver.disconnect();
              listen = false;
          }
      }

void KlanghabitatConnectorAudioProcessorEditor::connectButtonClicked(){

    if(!connected){
        connectTarget(); //connect to the selected target in the list
        connectButton.setButtonText ("target connected");
        animation.changeColour(Colours::green);
        connectButton.setColour (TextButton::textColourOffId, Colours::green);
        connected = true;
        deviceList.setEnabled(false);
    }
    else {
        disconnectTarget(); //Disconnect from the current connected target
        connectButton.setButtonText ("connect to target");
        animation.changeColour(Colours::darkorange);
        connectButton.setColour (TextButton::textColourOffId, Colours::darkorange);
        connected = false;
        deviceList.setEnabled(true);
    }
}


void KlanghabitatConnectorAudioProcessorEditor::connectTarget(){
    
    String myIPAdress;
    String IPAddressTarget = (String)(deviceList.getItemText(deviceList.getSelectedId()-1).substring(0, 15));
    
    allIpAdresses = juce::IPAddress::getAllAddresses();
        //**********************Finding the all Ethernet adresses used by this mashine*******************//
        for (int i=0; i< allIpAdresses.size(); i++){
            myIPAdressesArray[i] = allIpAdresses[i].toString();
        }
       
        //******************Finding the correct Ethernet adapter and connect with this*******************//
        for(int i=0; i< allIpAdresses.size(); i++){
           
            if (IPAddressTarget.substring(0,4) == allIpAdresses[i].toString().substring(0, 4)){
                myIPAdress = allIpAdresses[i].toString();
                TargetIP = IPAddressTarget;
                sender.connect (IPAddressTarget, 9011);
                sender.send ("/connection", myIPAdress);//sending "/connection" + IPAdress will start target to send downstream
                break;
            }
        }
    sender.disconnect();
}

void KlanghabitatConnectorAudioProcessorEditor::disconnectTarget(){
    
    String myIPAdress;
    String IPAddressTarget = (String)(deviceList.getItemText(deviceList.getSelectedId()-1).substring(0, 15));
    
    sender.connect (IPAddressTarget, 9011);
    sender.send ("/Disconnection", myIPAdress); //sending "/Disconnection" + IPAdress will stop target to send downstream
    sender.disconnect();
}



void KlanghabitatConnectorAudioProcessorEditor::oscMessageReceived (const OSCMessage& message){
    if (message.getAddressPattern().toString() == "/klanghabitat/DeviceInfo"){
         OSCBoxDeviceInfo.addOSCMessage (message);
        for (auto* arg = message.begin(); arg != message.end(); ++arg)
            KlanghabitatConnectorAudioProcessorEditor::Device_IPAdress = arg->getString().substring(0, 31);

        bool exist = false;
        
        for (int i = 0; i<deviceListArray.size(); i++){
            if (Device_IPAdress == deviceListArray.getUnchecked(i)){
                exist = true;
            }
        }
         
        if(!exist){
           deviceListArray.add(Device_IPAdress);
            deviceList.addItem (deviceListArray.getLast(), deviceListArray.size());
        }
        Device_Incoming_Message.setText( deviceListArray.getUnchecked(0), dontSendNotification);
    }
    else{
          OSCBoxDownStream.addOSCMessage (message);
        if (message.getAddressPattern().toString() == "/VALUE/Level/CH1/RMS"){
                for (auto* arg = message.begin(); arg != message.end(); ++arg)
                waveform_left.addSample(arg->getInt32());
        }
        
        if (message.getAddressPattern().toString() == "/VALUE/Level/CH2/RMS"){
                for (auto* arg = message.begin(); arg != message.end(); ++arg)
                waveform_right.addSample(arg->getInt32());
        }

        if (message.getAddressPattern().toString() == "/Watchdog"){
                for (auto* arg = message.begin(); arg != message.end(); ++arg)
                animation.animate();
        }
    }
    
}






//======================Out going event handles================================

void KlanghabitatConnectorAudioProcessorEditor::MSButtonClicked(){
    sender.connect (TargetIP, 9001);
    MS_STERO_IN = !MS_STERO_IN;
    sender.send ("/MotherEngine/Relais/K5", (int)MS_STERO_IN);
    sender.disconnect();
}
void KlanghabitatConnectorAudioProcessorEditor::MS_SignalButtonClicked(){
    sender.connect (TargetIP, 9001);
    MS_STERO_OUT = !MS_STERO_OUT;
    sender.send ("/MotherEngine/Relais/K6", (int)MS_STERO_OUT);
    sender.disconnect();
}
void KlanghabitatConnectorAudioProcessorEditor::LeftBypassButtonClicked(){
    sender.connect (TargetIP, 9001);
    L_BYPASS = !L_BYPASS;
    sender.send ("/MotherEngine/Relais/bypassLeft", (int)L_BYPASS);
    sender.disconnect();
}
void KlanghabitatConnectorAudioProcessorEditor::RightBypassButtonClicked(){
    sender.connect (TargetIP, 9001);
    R_BYPASS = !R_BYPASS;
    sender.send ("/MotherEngine/Relais/bypassRight", (int)R_BYPASS);
    sender.disconnect();
}
void KlanghabitatConnectorAudioProcessorEditor::ListenMidButtonClicked(){
    sender.connect (TargetIP, 9001);
    MID = !MID;
    sender.send ("/MotherEngine/Relais/K8", (int)MID);
    sender.disconnect();
}
void KlanghabitatConnectorAudioProcessorEditor::ListenSideButtonClicked(){
    sender.connect (TargetIP, 9001);
    SIDE = !SIDE;
    sender.send ("/MotherEngine/Relais/K7", (int)SIDE);
    sender.disconnect();
}

