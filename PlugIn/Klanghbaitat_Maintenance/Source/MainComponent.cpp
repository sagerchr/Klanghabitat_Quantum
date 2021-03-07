#include "MainComponent.h"
#include "SrecConverter.h"




//==============================================================================
MainComponent::MainComponent()
{
    oscReceiver.addListener(this);
    oscReceiver.connect (9010); //connect here the Reciver so it will listen to the incumming DeviceInfo from Target
   
    updateButton.setButtonText ("update");
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
    
    
    addAndMakeVisible (webButton);
    addAndMakeVisible (localButton);
    webButton  .onClick = [this] { updateToggleState (&webButton,   "web");   };
    localButton.onClick = [this] { updateToggleState (&localButton, "local"); };
    localButton.setToggleState(true,dontSendNotification);
    
    
    webButton  .setRadioGroupId (SourceButtons);
    localButton.setRadioGroupId (SourceButtons);
    
            fileComp.reset (new juce::FilenameComponent ("fileComp",
                                                     {},                       // current file
                                                     false,                    // can edit file name,
                                                     false,                    // is directory,
                                                     false,                    // is for saving,
                                                     {},                       // browser wildcard suffix,
                                                     {},                       // enforced suffix,
                                                     "Select file to open"));  // text when nothing selected
        addAndMakeVisible (fileComp.get());
        fileComp->addListener (this);
    
    //addAndMakeVisible(showString);
    
    //addAndMakeVisible(DisplayLabel);
    //addAndMakeVisible(MainEngineLabel);

    
    setSize (570, 290);
}




MainComponent::~MainComponent()
{
    Bootloader.disconnect();
    Bootloader.finish();
}
SrecConverter *DisplaySrec = nullptr;
SrecConverter *MainEngineSrec = nullptr;

juce::URL fileUrlDisplaySrec("https://www.klanghabitat.com/firmware/Display_.srec");
juce::URL fileUrlMotherEngineSrec("https://www.klanghabitat.com/firmware/MotherEnigine_.srec");

String pathToDisplay = File::getSpecialLocation(File::commonDocumentsDirectory).getChildFile("Display_.srec").getFullPathName();
String pathToMainEngine = File::getSpecialLocation(File::commonDocumentsDirectory).getChildFile("MotherEngine_.srec").getFullPathName();

juce::File DisplayLocalPath (pathToDisplay);
juce::File MainEngineLocalPath (pathToMainEngine);

juce::File DisplayLocalPath2(pathToDisplay);
juce::File MainEngineLocalPath2(pathToMainEngine);
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
    
    progressLabel.setBounds(10, 225, getWidth() - 20, 30);
    progressBar.setBounds(10, 250, getWidth() - 20, 30);
    deviceList.setBounds (10, 160, 400 , 30);
    updateButton.setBounds (420, 160,  140, 30);
    
    
    showString.setBounds(10, 300, getWidth() - 20, 30);
    
    SRC_ListBox_Display.setColour(juce::Label::textColourId,juce::Colours::black);
    
    DisplayLabel.setColour(juce::Label::textColourId,juce::Colours::black);
    MainEngineLabel.setColour(juce::Label::textColourId,juce::Colours::black);
    DisplayLabel.setBounds(10, 350, 100, 20);
    MainEngineLabel.setBounds(410, 350, 100, 20);
    
    
    webButton.setColour(juce::ToggleButton::textColourId,juce::Colours::black);
    webButton.setColour(juce::ToggleButton::tickColourId,juce::Colours::black);
    webButton.setColour(juce::ToggleButton::tickDisabledColourId,juce::Colours::black);
    webButton.setBounds(10, 130, 150, 20);
    
    localButton.setColour(juce::ToggleButton::textColourId,juce::Colours::black);
    localButton.setColour(juce::ToggleButton::tickColourId,juce::Colours::black);
    localButton.setColour(juce::ToggleButton::tickDisabledColourId,juce::Colours::black);
    localButton.setBounds(150, 130, 150, 20);
    
    
    SRC_ListBox_Display.setBounds(10, 370, 380, 300);
    SRC_ListBox_MainEngine.setBounds(410, 370, 380, 300);
    
    
     fileComp->setBounds    (10, 200, getWidth() - 20, 30);
 
    
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainComponent::filenameComponentChanged (juce::FilenameComponent* fileComponentThatHasChanged)
 {

 }

void MainComponent::updateProcedure(){
    
       juce::String IPAddressTarget = (juce::String)(deviceList.getItemText(deviceList.getSelectedId()-1).substring(0, 15));
    //juce::String IPAddressTarget = "192.168.1.70";
    if(!SourceWeb){
     MainEngineLocalPath2 = "/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/MotherEnigine/Debug/MotherEnigine.srec";
      DisplayLocalPath2 = "/Users/christiansager/klanghabitat_quantum/firmware/firmware quantum/Display/Debug/Display.srec";
        MainEngineData = MainEngineSrec->readFile(MainEngineLocalPath2);
        DisplayData = DisplaySrec->readFile(DisplayLocalPath2);
        
    }
    else{
        MainEngineData = MainEngineSrec->readFile(MainEngineLocalPath);
        DisplayData = DisplaySrec->readFile(DisplayLocalPath);
    }

    
        juce::String line;
        juce::String adress;
        juce::String payload;
        juce::String length;
        juce::String checksum;
        juce::StringArray StringArray;
        double size;
        
        actuelTask ="extracting File";
    
    
    
        
        
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
        actuelTask ="programming MainEngine";
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
        statusDisplay = 0;
        statusDisplayLast = 0;
        actuelTask ="programming Display" + adress2 + "  " + payload2;
       for (int i=1; i<StringArray2.size(); i++)
        {
            percentage = i/size2;
            statusDisplay = i/size2*100;
            
            if(statusDisplay > statusDisplayLast){
                statusDisplayLast = statusDisplay;
                Bootloader.statusDisplay(statusDisplay);
            }
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
    
     if(SourceWeb){
        DisplayLocalPath.deleteFile();
        MainEngineLocalPath.deleteFile();
     }
        
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
         MainComponent::updateProcedure();
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
         if(webButton.getToggleStateValue().getValue()){
             //###########################Download Srec Files from Server#########################################//
                 downladDisplaySrec = fileUrlDisplaySrec.downloadToFile(DisplayLocalPath,"",this, false);
                 downladMotherEngineSrec = fileUrlMotherEngineSrec.downloadToFile(MainEngineLocalPath,"",this, false);
             //###################################################################################################//
             
             SourceWeb = true;
         }else{
            downladDisplaySrec = fileUrlDisplaySrec.downloadToFile(DisplayLocalPath,"",this, false);
            downladMotherEngineSrec = fileUrlMotherEngineSrec.downloadToFile(MainEngineLocalPath,"",this, false);
             

             SourceWeb = false;
             
         }
         

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

void MainComponent::updateToggleState (juce::Button* button, juce::String name)
{
    auto state = button->getToggleState();
    juce::String stateString = state ? "ON" : "OFF";
    
    juce::Logger::outputDebugString (name + " Button changed to " + stateString);
}
