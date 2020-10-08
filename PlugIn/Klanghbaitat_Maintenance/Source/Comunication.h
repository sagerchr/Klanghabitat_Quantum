/*
  ==============================================================================

    Comunication.h
    Created: 19 Sep 2020 5:25:51pm
    Author:  Christian Sager

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
class Comunication 
{
public:
    //==============================================================================
    Comunication(){}
    ~Comunication(){}

    void ConnectToBootloader(juce::String IP);
    void restart();
    void disconnect();
    void cleanProgram(juce::String Adress, juce::String length);
    void programStart();
    void program(juce::String Adress, juce::String payload, juce::String length);
    
    
    void restartDisplay(juce::String IP);
    uint8_t pingIntoBootloaderSeriel(juce::String IP);
    void programStartSeriel(juce::String IP);
    void cleanProgramSeriel(juce::String IP,juce::String Adress, juce::String length);
    void programSeriel(juce::String IP,juce::String Adress, juce::String payload, juce::String length);
    void resetDisplay(juce::String IP);
    
    void finish();
    //==============================================================================
    private:
    //==============================================================================
    // Your private member variables go here...
    juce::String Adressinversion(juce::String Adress);
    void reciveClear();

    uint8_t CMD;
    char write[100];
    uint8_t recive[100];
    juce::StreamingSocket *socket = new juce::StreamingSocket();
    juce::StreamingSocket *Dispalysocket = new juce::StreamingSocket();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Comunication);
};
