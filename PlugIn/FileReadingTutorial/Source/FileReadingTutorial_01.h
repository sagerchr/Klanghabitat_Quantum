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

 name:             FileReadingTutorial
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Reads and displays a text file.

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics
 exporters:        xcode_mac, vs2017, linux_make

 type:             Component
 mainClass:        MainContentComponent

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/


#pragma once

//==============================================================================
class MainContentComponent   : public juce::Component,
                               public juce::FilenameComponentListener, public juce::URL::DownloadTask::Listener , public juce::Button::Listener
                              
{
public:
    MainContentComponent()
    {
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

        addAndMakeVisible (updateButton);
        updateButton.setButtonText ("update from web");
        updateButton.addListener (this);
        
        
        textContent.reset (new juce::TextEditor());
        addAndMakeVisible (textContent.get());
        textContent->setMultiLine (true);
        textContent->setReadOnly (true);
        textContent->setCaretVisible (false);

        setSize (600, 400);
        

 
    }

    int count = 0;
    String dataDisplay;
    String dataMotherEngine;
    
    void finished (URL::DownloadTask* task, bool success) override
    {
        count++;
        if(success && count == 2){
            writer();
            count = 0;
        }
        
    
   
    }
String line;
    void writer(){
        
         File pathDisplay ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/Display.srec");
         dataDisplay = pathDisplay.loadFileAsString();
         
         juce::FileInputStream inputStream (pathDisplay);
         //auto line = inputStream.readNextLine();
         //line.append("*",1);
         //auto length = line.length();
        
        
        
        int lineCount = 0;
             while (! inputStream.isExhausted()) 
        {
            auto currentLine = inputStream.readNextLine();
            line.append(currentLine,currentLine.length());
            line.append("*",1);
            line.append("\r\n",2);
            lineCount++;
        }
        
        auto length = line.length();

         File pathMotherEngine ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/MotherEnigine.srec");
         dataMotherEngine = pathMotherEngine.loadFileAsString();
                  
         StreamingSocket *socket = new StreamingSocket();
         socket->bindToPort(7);
         socket->connect("192.168.1.70", 7, 20000);
        
        socket->waitUntilReady(false, -1);
        
         socket->write(line.toUTF8(), 1500000);
         socket->close();
         socket->~StreamingSocket ();
        
        //data.~MemoryBlock();
    }
    
    

    void buttonClicked (juce::Button* button) override
    {
        if (button == &updateButton)
        {
            
             //###########################Download Srec Files from Server#########################################//
             URL fileUrlDisplaySrec("https://www.klanghabitat.com/firmware/Display.srec");
             File localFileDisplaySrec ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/Display.srec");
             downladDisplaySrec = fileUrlDisplaySrec.downloadToFile(localFileDisplaySrec,"",this, false);

             URL fileUrlMotherEngineSrec("https://www.klanghabitat.com/firmware/MotherEnigine.srec");
             File localFileMotherEngineSrec ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/MotherEnigine.srec");
             downladMotherEngineSrec = fileUrlMotherEngineSrec.downloadToFile(localFileMotherEngineSrec,"",this, false);
            //###################################################################################################//
           
        }
    }
    
    
    
    
    
    void resized() override
    {
        updateButton.setBounds (10, 10, getWidth() - 20, 20);
        fileComp->setBounds    (10, 40, getWidth() - 20, 20);
        textContent->setBounds (10, 70, getWidth() - 20, getHeight() - 90);

    }

    void filenameComponentChanged (juce::FilenameComponent* fileComponentThatHasChanged) override
    {
        if (fileComponentThatHasChanged == fileComp.get())
            readFile (fileComp->getCurrentFile());
    }

    void readFile (const juce::File& fileToRead)
    {
        
        if (! fileToRead.existsAsFile()) // [1]
            return;

        auto fileText = fileToRead.loadFileAsString();

        textContent->setText (fileText);
    }

private:
    std::unique_ptr<juce::FilenameComponent>            fileComp;
    std::unique_ptr<juce::TextEditor>                   textContent;
    juce::URL::DownloadTask::Listener* listen1;
    juce::URL::DownloadTask::Listener* listen2;
    std::unique_ptr<juce::URL::DownloadTask> downladDisplaySrec;
    std::unique_ptr<juce::URL::DownloadTask> downladMotherEngineSrec;
    
    
    juce::TextButton updateButton;
    juce::Label timeLabel;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
