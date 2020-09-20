/*
  ==============================================================================

    SrecConverter.h
    Created: 19 Sep 2020 5:26:57pm
    Author:  Christian Sager

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SrecConverter :  public juce::FilenameComponentListener
{
public:
    //==============================================================================
    SrecConverter();
    ~SrecConverter();

    juce::String readFile(juce::File path);
    //==============================================================================
    private:
    //==============================================================================
    // Your private member variables go here...

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SrecConverter);
};
