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

 name:             AudioParameterTutorial
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Explores audio plugin parameters.

 dependencies:     juce_audio_basics, juce_audio_devices, juce_audio_formats,
                   juce_audio_plugin_client, juce_audio_processors,
                   juce_audio_utils, juce_core, juce_data_structures,
                   juce_events, juce_graphics, juce_gui_basics, juce_gui_extra
 exporters:        xcode_mac, vs2017, linux_make

 type:             AudioProcessor
 mainClass:        TutorialProcessor

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/


#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>
#include <string.h>


//==============================================================================
class GenericEditor : public AudioProcessorEditor,
                      private Timer

{
public:
    
bool p = true;
    enum
    {
        paramControlHeight = 310,
        paramLabelWidth    = 20,
        paramSliderWidth   = 5000
    };
    
    int i = 0;
    
	//Establish Serial Connection

    StringPairArray portlist = SerialPort::getSerialPortPaths();
    
    String test1 = portlist.getAllValues()[1];


    StringArray ports = {
        "All available COM Ports...",
        portlist.getAllValues()[0],
        portlist.getAllValues()[1],
        portlist.getAllValues()[2],
        portlist.getAllValues()[3],
        portlist.getAllValues()[4],
        
    };
    
    /*
    SerialPort * pSP;
    
    SerialPortInputStream * pInputStream;
    SerialPortOutputStream * pOutputStream;
    */

    
    SerialPort * pSP = new SerialPort(test1, SerialPortConfig(115200, 8, SerialPortConfig::SERIALPORT_PARITY_NONE, SerialPortConfig::STOPBITS_1, SerialPortConfig::FLOWCONTROL_NONE));
    
    SerialPortInputStream * pInputStream = new SerialPortInputStream(pSP);
    SerialPortOutputStream * pOutputStream = new SerialPortOutputStream(pSP);
 
    
    GenericEditor (AudioProcessor& parent)
    
        : AudioProcessorEditor (parent)
    {
        startTimer(10);
    
        auto& params = parent.getParameters();

        for (auto p : params)
        {
            if (auto* param = dynamic_cast<AudioParameterFloat*> (p))
            {
                
                Slider* aSlider;

              
                paramSliders.add (aSlider = new Slider (param->name));
                aSlider->setRange (param->range.start, param->range.end);
                aSlider->setSliderStyle (Slider:: RotaryHorizontalVerticalDrag);
                aSlider->setValue (*param);
                
                aSlider->setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
                
                aSlider->onValueChange = [this, aSlider] { changeSliderValue (aSlider); };
                aSlider->onDragStart   = [this, aSlider] { startDragChange (aSlider); };
                aSlider->onDragEnd     = [this, aSlider] { endDragChange (aSlider); };
                addAndMakeVisible (aSlider);
                
                Label* aLabel;
                paramLabels.add (aLabel = new Label (param->name, param->name));
                
                addAndMakeVisible (aLabel);
            
            }
        }

        noParameterLabel.setJustificationType (Justification::horizontallyCentred | Justification::verticallyCentred);
        noParameterLabel.setFont (noParameterLabel.getFont().withStyle (Font::italic));

        if (paramSliders.size() == 0)
        {
            addAndMakeVisible (noParameterLabel);
            setSize (10, 30);

        }
        else
        {

            /*setSize (paramSliderWidth + paramLabelWidth,
                     jmax (1000, paramControlHeight * paramSliders.size()));
            */
            setSize (500,360);
            //startTimer (100);

        }        
    }

    ~GenericEditor() {pSP->close();}

    void resized() override
    {
        
        

        getLookAndFeel().setColour (Slider::thumbColourId, Colours::orange);


        paramSliders[0]->setBounds (20 , 5,100,100);
        paramSliders[0]->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 15);
        paramSliders[1]->setBounds (20 ,105,100,100);
        paramSliders[1]->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 15);
        paramSliders[2]->setBounds (20 ,205,100,100);
        paramSliders[2]->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 15);
        paramSliders[3]->setBounds (400, 5,100,100);
        paramSliders[3]->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 15);
        paramSliders[4]->setBounds (400,105,100,100);
        paramSliders[4]->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 15);
        paramSliders[5]->setBounds (400,205,100,100);
        paramSliders[5]->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 15);
        
		//INPUT.setBounds(50,15, 100, 20);
		//addAndMakeVisible(INPUT);
        
        lafBox.addItemList(ports, 1);
        lafBox.setBounds(0, 320, 200, 20);
        lafBox.setAlwaysOnTop(true);
        addAndMakeVisible (lafBox);
        
        Button1.setBounds(200, 100, 100, 30);
        addAndMakeVisible (Button1);
    }

 String stream ="no device connected";

 String value1 = "";
 int IntStream = 0;
    char CharIN[32];
    
    int lastInput = 0;
    int lastOutput = 0;
    
    int out1 = 0;
    int *output = NULL;
    
    void paint (Graphics& g) override //wird immer dann ausgeführt, wenn es zu einer Änderung kommt!
    {
		
		/*******************************  BACKROUND IMAGE Zeichnen****************************************/
        /*
        Image orbiter = ImageCache::getFromMemory (BinaryData::orbiter_png, BinaryData::orbiter_pngSize);
        g.drawImageAt(orbiter, 0,0);
       */
        
        /*************************************************************************************************/
        

        //IntStream = stream.getIntValue();
     
        


        
        
        
        /****************************** IST - Wert von Poti ablesen und an DUE senden *******************/
       
     /*
        val1 = int(paramSliders[0]->getValue());
        output = &val1;
        
        if (lastOutput != val1){
            
            lastOutput = val1;
           pOutputStream->write((int *) output, 1);
        }
    */
        //pOutputStream->write((int *) output, 1);
        /************************************************************************************************/
        
        
        /***************************************  Wert von Extern annehmen  *****************************/

        
        if (lastInput != IntStream){
            
            paramSliders[0]->setValue(IntStream);
            lastInput = IntStream;
        }

        /************************************************************************************************/
        
        
        
        
        /******************************************  Ringe zeichnen  ************************************/
		

        g.drawFittedText (String(stream), getLocalBounds(), Justification::bottomLeft, 1);
        
    }

   
    void changeSliderValue (Slider* slider)
    {
        if (auto* param = getParameterForSlider (slider))
            *param = (float) slider->getValue();

    }

    void startDragChange (Slider* slider)
    {
        if (auto* param = getParameterForSlider (slider))
            param->beginChangeGesture();
    }

    void endDragChange (Slider* slider)
    {
        if (auto* param = getParameterForSlider (slider))
            param->endChangeGesture();
    }
        
        void connect (String path)
        {


        }
    
    
public:
   
	TextButton INPUT;
    
  
    
    ComboBox lafBox;
    
    TextButton Button1  { "connect" };
    uint8_t count=10;
    void timerCallback() override
    {
        
        
        
        
        auto& params = getAudioProcessor()->getParameters();
        
        std::cout << (int)count;
        std::cout << " || ";
        
        for (int i= 0; i<6;i++){
            std::cout << (int) paramSliders[i]->getValue();
            std::cout << " || ";
        }
        
        std::cout << lafBox.getText();
        std::cout << " || ";
        std::cout << Button1.getState();
        std::cout << "\r\n";
        
        if(Button1.getState() == 2){

            
        }
        
        count++;
        if(count>=99){
            count = 10;
        }


       //
        
        
        while (pInputStream->canReadLine()) {
            stream = pInputStream->readNextLine();
            repaint();
        
            for (int i = 0; i < sizeof(stream); i++) {
                CharIN[i] = stream[i];
            }
         
         
            
        }
        
        
        for (auto i = 0; i < params.size(); ++i)
        {
            if (auto* param = dynamic_cast<AudioParameterFloat*> (params[i]))
            {
                /*
                if (i < paramSliders.size())
                    paramSliders[i]->setValue (*param);
                */
            }
        }
    }

    AudioParameterFloat* getParameterForSlider (Slider* slider)
    {
        auto& params = getAudioProcessor()->getParameters();
        return dynamic_cast<AudioParameterFloat*> (params[paramSliders.indexOf (slider)]);
    }

    Label noParameterLabel { "noparam", "No parameters available" };
    OwnedArray<Slider> paramSliders;
    OwnedArray<Label> paramLabels;
};

//==============================================================================
class TutorialProcessor  : public AudioProcessor

{

    
public:
 
    //==============================================================================
    TutorialProcessor()
    {
		

        
        addParameter (Input = new AudioParameterFloat ("Input", // parameterID
                                                      "Input", // parameter name
                                                      0,   // minimum value
                                                      127,   // maximum value
                                                      0)); // default value
        
        addParameter (Attack = new AudioParameterFloat ("Attack", // parameterID
                                                      "Attack", // parameter name
                                                      0.0f,   // minimum value
                                                      127.0f,   // maximum value
                                                      0.0f)); // default value
        
        addParameter (Threshold = new AudioParameterFloat ("Threshold", // parameterID
                                                      "Threshold", // parameter name
                                                      0.0f,   // minimum value
                                                      127.0f,   // maximum value
                                                      0.0f)); // default value
        
        addParameter (Release = new AudioParameterFloat ("Release", // parameterID
                                                      "Release", // parameter name
                                                      0.0f,   // minimum value
                                                      127.0f,   // maximum value
                                                      0.0f)); // default value
        
        addParameter (Output = new AudioParameterFloat ("Output", // parameterID
                                                      "Output", // parameter name
                                                      0,   // minimum value
                                                      127,   // maximum value
                                                      0)); // default value
        
        addParameter (Ratio = new AudioParameterFloat ("Ratio", // parameterID
                                                        "Ratio", // parameter name
                                                        0.0f,   // minimum value
                                                        127.0f,   // maximum value
                                                        0.0f)); // default value
    }

    ~TutorialProcessor() {}
   
    //==============================================================================
    void prepareToPlay (double, int) override {}
    void releaseResources() override {}

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer&) override
    {
        
    }

    //==============================================================================
    AudioProcessorEditor* createEditor() override          { return new GenericEditor (*this); }
    bool hasEditor() const override                        { return true; }

    //==============================================================================
    const String getName() const override                  { return "Quantum"; }
    bool acceptsMidi() const override                      { return false; }
    bool producesMidi() const override                     { return false; }
    double getTailLengthSeconds() const override           { return 0; }

    //==============================================================================
    int getNumPrograms() override                          { return 1; }
    int getCurrentProgram() override                       { return 0; }
    void setCurrentProgram (int) override                  {}
    const String getProgramName (int) override             { return {}; }
    void changeProgramName (int, const String&) override   {}

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override
    {
        std::unique_ptr<XmlElement> xml (new XmlElement ("Quantum"));
        xml->setAttribute ("Input", (double) *Input);
        xml->setAttribute ("Attack", (double) *Attack);
        xml->setAttribute ("Threshold", (double) *Threshold);
        xml->setAttribute ("Release", (double) *Release);
        xml->setAttribute ("Output", (double) *Output);
        xml->setAttribute ("Ratio", (double) *Ratio);
        copyXmlToBinary (*xml, destData);
    }
    
    void setStateInformation (const void* data, int sizeInBytes) override
    {
        std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
        if (xmlState.get() != nullptr)
        {
            if (xmlState->hasTagName ("Quantum"))
            {
                *Input = (float) xmlState->getDoubleAttribute ("Input", 1.0);
                *Attack = (float) xmlState->getDoubleAttribute ("Attack", 1.0);
                *Threshold = (float) xmlState->getDoubleAttribute ("Threshold", 1.0);
                *Release = (float) xmlState->getDoubleAttribute ("Release", 1.0);
                *Output = (float) xmlState->getDoubleAttribute ("Output", 1.0);
                *Ratio = (float) xmlState->getDoubleAttribute ("Ratio", 1.0);
            }
        }
    }
    

private:
    
    //Image orbiter;
    //==============================================================================
    AudioParameterFloat* Input;
    AudioParameterFloat* Attack;
    AudioParameterFloat* Threshold;
    AudioParameterFloat* Release;
    AudioParameterFloat* Output;
    AudioParameterFloat* Ratio;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TutorialProcessor)
};
