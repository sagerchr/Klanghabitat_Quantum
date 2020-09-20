/*
  ==============================================================================

    ListBoxClass.h
    Created: 18 Apr 2020 12:00:55pm
    Author:  Christian Sager

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
using namespace juce;
class SRC_ListBox    : public ListBox,
                         private ListBoxModel,
                         private AsyncUpdater
{
public:
    //===============================================================================================
    SRC_ListBox()
    {
        setModel (this);
    }
    //===============================================================================================
    int getNumRows() override;
    //===============================================================================================
    void paintListBoxItem (int row, Graphics& g, int width, int height, bool rowIsSelected) override;
    //===============================================================================================
    void addString (juce::String data);
    //===============================================================================================
    void addArray (juce::StringArray StringArray);
    //===============================================================================================
    void clear();
    //===============================================================================================
    void handleAsyncUpdate() override;
private:
    //===============================================================================================
    String getIndentationString (int level)
    {
        return String().paddedRight (' ', 2 * level);
    }
    //===============================================================================================
    StringArray oscLogList;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SRC_ListBox)
};
