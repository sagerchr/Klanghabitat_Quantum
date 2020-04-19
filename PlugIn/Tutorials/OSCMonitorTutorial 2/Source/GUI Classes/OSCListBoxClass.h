/*
  ==============================================================================

    ListBoxClass.h
    Created: 18 Apr 2020 12:00:55pm
    Author:  Christian Sager

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OSCLogListBox    : public ListBox,
                         private ListBoxModel,
                         private AsyncUpdater
{
public:
    //===============================================================================================
    OSCLogListBox()
    {
        setModel (this);
    }
    //===============================================================================================
    int getNumRows() override;
    //===============================================================================================
    void paintListBoxItem (int row, Graphics& g, int width, int height, bool rowIsSelected) override;
    //===============================================================================================
    void addOSCMessage (const OSCMessage& message, int level = 0);
    //===============================================================================================
    void addOSCBundle (const OSCBundle& bundle, int level = 0);
    //===============================================================================================
    void addOSCMessageArgument (const OSCArgument& arg, int level);
    //===============================================================================================
    void addInvalidOSCPacket (const char* /* data */, int dataSize);
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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OSCLogListBox)
};
