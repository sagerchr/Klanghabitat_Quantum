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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Comunication);
};
