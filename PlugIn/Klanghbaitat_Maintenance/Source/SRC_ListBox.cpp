/*
  ===============================================================================================

    ListBoxClass.cpp
    Created: 18 Apr 2020 12:00:55pm
    Author:  Christian Sager

  ===============================================================================================
*/
/*
  ===============================================================================================

    ListBoxClass.cpp
    Created: 18 Apr 2020 12:00:55pm
    Author:  Christian Sager

  ===============================================================================================
*/
#include "SRC_ListBox.h"
using namespace juce;
//===============================================================================================

int SRC_ListBox::getNumRows()
{
   return oscLogList.size();
}

//===============================================================================================
void SRC_ListBox::paintListBoxItem (int row, Graphics& g, int width, int height, bool rowIsSelected)

{
    ignoreUnused (rowIsSelected);

    if (isPositiveAndBelow (row, oscLogList.size()))
    {
        g.setColour (Colours::white);

        g.drawText (oscLogList[row],
                    Rectangle<int> (width, height).reduced (2, 0),
                    Justification::centredLeft, true);
    }
}
//===============================================================================================
void SRC_ListBox::addString (juce::String data){

    StringArray StringArray;
    StringArray.addLines (data);

    for (int i=0; i<StringArray.size(); i++)
    {
       oscLogList.add (StringArray[i]);
    }
    triggerAsyncUpdate();
}
//===============================================================================================
void SRC_ListBox::addArray (juce::StringArray StringArray){

    for (int i=0; i<StringArray.size(); i++)
    {
       oscLogList.add (StringArray[i]);
    }
    triggerAsyncUpdate();
}
//===============================================================================================

void SRC_ListBox::clear()
{
    oscLogList.clear();
    triggerAsyncUpdate();
}

//===============================================================================================
void SRC_ListBox::handleAsyncUpdate()
{
    updateContent();
    scrollToEnsureRowIsOnscreen (oscLogList.size() - 1);
    repaint();
}
