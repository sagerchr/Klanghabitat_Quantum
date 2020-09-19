#include "MainComponent.h"
//==============================================================================
MainComponent::MainComponent()
{
   
    
    addAndMakeVisible (updateButton);
    updateButton.setButtonText ("update from web");
    updateButton.addListener (this);
    
    
    oscReceiver.addListener(this);
    oscReceiver.connect (9010); //connect here the Reciver so it will listen to the incumming DeviceInfo from Target
    
     
    
    addAndMakeVisible(deviceList);
    setSize (600, 400);
   
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll (juce::Colours::white);
    juce::Image Logo = juce::ImageCache::getFromMemory (BinaryData::AURORA_png, BinaryData::AURORA_pngSize);
    g.drawImageAt(Logo, 0,0);
}

void MainComponent::resized()
{
      deviceList.setBounds (10, 150, getWidth() - 20, 30);
    updateButton.setBounds (10, 200, getWidth() - 20, 30);
   
        
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainComponent::filenameComponentChanged (juce::FilenameComponent* fileComponentThatHasChanged)
 {

 }


void MainComponent::finished (juce::URL::DownloadTask* task, bool success)
 {
     
    
 }


void MainComponent::buttonClicked (juce::Button* button)
 {
     if (button == &updateButton)
     {
    //###########################Download Srec Files from Server#########################################//
         
        juce::URL fileUrlDisplaySrec("https://www.klanghabitat.com/firmware/Display.srec");
        juce::File localFileDisplaySrec ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/Display.srec");
        downladDisplaySrec = fileUrlDisplaySrec.downloadToFile(localFileDisplaySrec,"",this, false);

        juce::URL fileUrlMotherEngineSrec("https://www.klanghabitat.com/firmware/MotherEnigine.srec");
        juce::File localFileMotherEngineSrec ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/MotherEnigine.srec");
        downladMotherEngineSrec = fileUrlMotherEngineSrec.downloadToFile(localFileMotherEngineSrec,"",this, false);
          
    //###################################################################################################//
         
     }
 }

void MainComponent::oscMessageReceived (const juce::OSCMessage& message){
    if (message.getAddressPattern().toString() == "/klanghabitat/DeviceInfo"){
        
            for (auto* arg = message.begin(); arg != message.end(); ++arg)
                MainComponent::Device_IPAdress = arg->getString().substring(0, 31);
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
        Device_Incoming_Message.setText( deviceListArray.getUnchecked(0), juce::dontSendNotification);
        }
    }

