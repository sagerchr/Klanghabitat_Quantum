#include "MainComponent.h"
#include "SrecConverter.h"

//==============================================================================
MainComponent::MainComponent()
{
    oscReceiver.addListener(this);
    oscReceiver.connect (9010); //connect here the Reciver so it will listen to the incumming DeviceInfo from Target
   
    updateButton.setButtonText ("download frimware and update device");
    updateButton.addListener (this);
    
    progressLabel.setColour (juce::Label::textColourId, juce::Colours::black);
    
    showString.setButtonText ("update device");
    showString.addListener (this);
        
    addAndMakeVisible (SRC_ListBox_Display);
    addAndMakeVisible (SRC_ListBox_MainEngine);
    
    addAndMakeVisible (updateButton);
    addAndMakeVisible(progressBar);
    addAndMakeVisible(deviceList);
    addAndMakeVisible(progressLabel);
    //addAndMakeVisible(showString);
    
    //addAndMakeVisible(DisplayLabel);
    //addAndMakeVisible(MainEngineLabel);

    
    setSize (570, 250);
}

MainComponent::~MainComponent()
{
    Bootloader.disconnect();
}
SrecConverter *DisplaySrec = nullptr;
SrecConverter *MainEngineSrec = nullptr;

juce::URL fileUrlDisplaySrec("https://www.klanghabitat.com/firmware/Display_.srec");
juce::URL fileUrlMotherEngineSrec("https://www.klanghabitat.com/firmware/MotherEnigine_.srec");

const String pathToDisplay = File::getSpecialLocation(File::currentApplicationFile).getChildFile("Display_.srec").getFullPathName();
const String pathToMainEngine = File::getSpecialLocation(File::currentApplicationFile).getChildFile("MotherEngine_.srec").getFullPathName();

juce::File DisplayLocalPath (pathToDisplay);
juce::File MainEngineLocalPath (pathToMainEngine);
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
    
    progressLabel.setBounds(10, 120, getWidth() - 20, 30);
    progressBar.setBounds(10, 150, getWidth() - 20, 30);
    deviceList.setBounds (10, 200, (getWidth()/2) - 20, 30);
    updateButton.setBounds ((getWidth()/2)+10, 200, (getWidth()/2) - 20, 30);
    
    
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
     
     if(percentage >0.9){
            percentage = 0;
        }
   
     actuelTask ="download firmware";
     percentage += 0.01;
     progress = &percentage;
     
     if((percentage)==0.02){
        //juce::String IPAddressTarget = (juce::String)(deviceList.getItemText(deviceList.getSelectedId()-1).substring(0, 15));
         juce::String IPAddressTarget = "192.168.1.70";
         
         juce::String line;
         juce::String adress;
         juce::String payload;
         juce::String length;
         juce::String checksum;
         juce::StringArray StringArray;
         double size;
         
         actuelTask ="reading File";
         MainEngineData = MainEngineSrec->readFile(MainEngineLocalPath);
         DisplayData = DisplaySrec->readFile(DisplayLocalPath);
         
         percentage += 0.01;
          
         actuelTask ="connecting to target: " + IPAddressTarget;
        
         Bootloader.ConnectToBootloader(IPAddressTarget);
         percentage += 0.01;
         Bootloader.programStart();
         actuelTask ="erase program";
         percentage += 0.01;
         Bootloader.cleanProgram("08008000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08010000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08018000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08020000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08028000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08030000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08038000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08038000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08040000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08048000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08050000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgram("08058000", "00008000");
         percentage += 0.01;
         
         percentage = 0.0;
         
         StringArray.addLines (MainEngineData);
         StringArray.size();
         
         size = StringArray.size();
         actuelTask ="programming: ";
        for (int i=1; i<StringArray.size(); i++)
         {
             percentage = i/size;
            
             line = StringArray[i].substring(0, StringArray[i].length());
             length = line.substring(2,4);
             adress = line.substring(4, 12);
             payload = line.substring(12, (length.getHexValue32()*2)+2);
             checksum = line.substring((length.getHexValue32()*2)+2);
             //actuelTask ="programming: " + adress + "  " + payload;
             Bootloader.program(adress, payload, length);
             
         }
         
         actuelTask ="restart MainEngine";
         Bootloader.restart();
         Bootloader.disconnect();
          percentage = 0.0;
         
         
         //##########-----WAIT FOR 2 SECONDS-----############//
         uint64_t count=timerCounter;
         while(timerCounter-count < 200){
             //This makes a wait for 2 secs.
         }
         //##################################################//
         
         actuelTask ="Connecting to Display";
         Bootloader.restartDisplay(IPAddressTarget);
         
         //##########-----WAIT FOR 1 SECOND-----############//
         count=timerCounter;
         while(timerCounter-count < 100){
             //This makes a wait for 1 secs.
         }
         //##################################################//
         
         for (int i=0;i<10;i++){
             
             Bootloader.pingIntoBootloaderSeriel(IPAddressTarget);
             count=timerCounter;
             while(timerCounter-count < 10){
                 //This makes a wait for 0,1 secs.
             }
         }
         percentage = 0.0;
         
         actuelTask ="Display connected";
         
         Bootloader.programStartSeriel(IPAddressTarget);
         
         
         
         actuelTask ="erase program Display";
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08010000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08018000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08020000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08028000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08030000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08038000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08038000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08040000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08048000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08050000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"08058000", "00008000");
         percentage += 0.01;
         Bootloader.cleanProgramSeriel(IPAddressTarget,"0806000", "00008000");
         percentage += 0.01;
         actuelTask ="program Display";
         
         
         
         juce::String line2;
         juce::String adress2;
         juce::String payload2;
         juce::String length2;
         juce::String checksum2;
         juce::StringArray StringArray2;
          
         StringArray2.addLines (DisplayData);
         double size2 = StringArray2.size();
         percentage = 0.0;
         
         actuelTask ="programming Display: " + adress2 + "  " + payload2;
        for (int i=1; i<StringArray2.size(); i++)
         {
             percentage = i/size2;
            
             line2 = StringArray2[i].substring(0, StringArray2[i].length());
             length2 = line2.substring(2,4);
             adress2 = line2.substring(4, 12);
             payload2 = line2.substring(12, (length2.getHexValue32()*2)+2);
             checksum2 = line2.substring((length2.getHexValue32()*2)+2);
             //actuelTask ="programming Display: " + adress2 + "  " + payload2;
             Bootloader.programSeriel(IPAddressTarget,adress2, payload2, length2);
         }
         actuelTask ="restart Display and finish process...";
         Bootloader.resetDisplay(IPAddressTarget);
     }
     
 }


void MainComponent::timerCallback()
{
   
    progressLabel.setText(actuelTask, dontSendNotification);
    timerCounter++;
}




void MainComponent::buttonClicked (juce::Button* button)
 {
     if (button == &updateButton)
     {
         startTimer(10);
         timerCounter = 0;
    //###########################Download Srec Files from Server#########################################//
        downladDisplaySrec = fileUrlDisplaySrec.downloadToFile(DisplayLocalPath,"",this, false);
        downladMotherEngineSrec = fileUrlMotherEngineSrec.downloadToFile(MainEngineLocalPath,"",this, false);
    //###################################################################################################//
     }
     
     if (button == &showString){
             
        
        
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
