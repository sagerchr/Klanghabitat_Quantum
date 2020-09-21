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
    //==============================================================================
    private:
    //==============================================================================
    // Your private member variables go here...

    uint8_t CMD;
    char write[100];
    uint8_t recive[100];
    juce::StreamingSocket *socket = new juce::StreamingSocket();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Comunication);
};
