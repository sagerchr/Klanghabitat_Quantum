#include "MainComponent.h"
#include "SrecConverter.h"

//==============================================================================
MainComponent::MainComponent()
{
    oscReceiver.addListener(this);
    oscReceiver.connect (9010); //connect here the Reciver so it will listen to the incumming DeviceInfo from Target
   
    updateButton.setButtonText ("update from web");
    updateButton.addListener (this);
    
    showString.setButtonText ("update String");
    showString.addListener (this);
    
    
    addAndMakeVisible (SRC_ListBox_Display);
    addAndMakeVisible (SRC_ListBox_MainEngine);
    
    
    addAndMakeVisible (updateButton);
    addAndMakeVisible(progressBar);
    addAndMakeVisible(deviceList);
    addAndMakeVisible(TextLabel);
    addAndMakeVisible(showString);
    
    addAndMakeVisible(DisplayLabel);
    addAndMakeVisible(MainEngineLabel);

    
    setSize (800, 700);
}

MainComponent::~MainComponent()
{
}
SrecConverter *DisplaySrec = nullptr;
SrecConverter *MainEngineSrec = nullptr;

juce::URL fileUrlDisplaySrec("https://www.klanghabitat.com/firmware/Display_.srec");
juce::URL fileUrlMotherEngineSrec("https://www.klanghabitat.com/firmware/MotherEnigine_.srec");

juce::File DisplayLocalPath ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/Display_.srec");
juce::File MainEngineLocalPath ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/MotherEngine_.srec");
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
    progressBar.setBounds(10, 250, getWidth() - 20, 30);
    showString.setBounds(10, 300, getWidth() - 20, 30);
    
    SRC_ListBox_Display.setColour(juce::Label::textColourId,juce::Colours::black);
    
    DisplayLabel.setColour(juce::Label::textColourId,juce::Colours::black);
    MainEngineLabel.setColour(juce::Label::textColourId,juce::Colours::black);
    DisplayLabel.setBounds(10, 350, 100, 20);
    MainEngineLabel.setBounds(410, 350, 100, 20);
    
    SRC_ListBox_Display.setBounds(10, 370, 380, 300);
    SRC_ListBox_MainEngine.setBounds(410, 370, 380, 300);
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainComponent::filenameComponentChanged (juce::FilenameComponent* fileComponentThatHasChanged)
 {

 }


void MainComponent::finished (juce::URL::DownloadTask* task, bool success)
 {
     percentage += 0.01;
     progress = &percentage;
     
     if((percentage)==0.02){
        
         DisplayData = DisplaySrec->readFile(DisplayLocalPath);
         MainEngineData = MainEngineSrec->readFile(MainEngineLocalPath);
         
     }
     
 }


void MainComponent::buttonClicked (juce::Button* button)
 {
     if (button == &updateButton)
     {
    //###########################Download Srec Files from Server#########################################//
        downladDisplaySrec = fileUrlDisplaySrec.downloadToFile(DisplayLocalPath,"",this, false);
        downladMotherEngineSrec = fileUrlMotherEngineSrec.downloadToFile(MainEngineLocalPath,"",this, false);
    //###################################################################################################//
     }
     
     if (button == &showString){
             
        juce::String IPAddressTarget = (juce::String)(deviceList.getItemText(deviceList.getSelectedId()-1).substring(0, 15));
        
         CallBootloader.ConnectToBootloader(IPAddressTarget);
         CallBootloader.restart();
         CallBootloader.disconnect();
         
        SRC_ListBox_Display.addArray (parseSrec(DisplayData));
        SRC_ListBox_MainEngine.addArray (parseSrec(MainEngineData));
         
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
        //Device_Incoming_Message.setText( deviceListArray.getUnchecked(0), juce::dontSendNotification);
        }
    }

juce::StringArray MainComponent::parseSrec(juce::String data){
    
            juce::StringArray StringArray;
            juce::String line;
            juce::String Adress;
            juce::String Payload;
            juce::String count;
            juce::String checksum;
            juce::StringArray StringArray_manipulated;
            StringArray.addLines (data);
            
             for (int i=0; i<StringArray.size(); i++)
               {
                   line = StringArray[i].substring(0, StringArray[i].length());
                   count = line.substring(2,4);
                   Adress = line.substring(4, 12);
                   Payload = line.substring(12, (count.getHexValue32()*2)+2);
                   checksum = line.substring((count.getHexValue32()*2)+2);
                   
                   StringArray_manipulated.insert(i, count + "*" + Adress + "*" + Payload + "*" + checksum);
               }
    return StringArray_manipulated;
}
