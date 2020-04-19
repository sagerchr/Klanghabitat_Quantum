/*
  ===============================================================================================

    ListBoxClass.cpp
    Created: 18 Apr 2020 12:00:55pm
    Author:  Christian Sager

  ===============================================================================================
*/

#include "OSCListBoxClass.h"
//===============================================================================================

int OSCLogListBox::getNumRows()
{
   return oscLogList.size();
}

//===============================================================================================
void OSCLogListBox::paintListBoxItem (int row, Graphics& g, int width, int height, bool rowIsSelected)

{
    ignoreUnused (rowIsSelected);

    if (isPositiveAndBelow (row, oscLogList.size()))
    {
        g.setColour (Colours::white);

        g.drawText (oscLogList[row],
                    Rectangle<int> (width, height).reduced (4, 0),
                    Justification::centredLeft, true);
    }
}

//===============================================================================================
void OSCLogListBox::addOSCMessage (const OSCMessage& message, int level)
{
    oscLogList.add (getIndentationString (level)
                    + "- osc message, address = '"
                    + message.getAddressPattern().toString()
                    + "', "
                    + String (message.size())
                    + " argument(s)");
    
    
    if (! message.isEmpty())
    {
        for (auto* arg = message.begin(); arg != message.end(); ++arg)
            addOSCMessageArgument (*arg, level + 1);
    }

    triggerAsyncUpdate();
}
//===============================================================================================
void OSCLogListBox::addOSCBundle (const OSCBundle& bundle, int level)
{
    OSCTimeTag timeTag = bundle.getTimeTag();

    oscLogList.add (getIndentationString (level)
                    + "- osc bundle, time tag = "
                    + timeTag.toTime().toString (true, true, true, true));

    for (auto* element = bundle.begin(); element != bundle.end(); ++element)
    {
        if (element->isMessage())
            addOSCMessage (element->getMessage(), level + 1);
        else if (element->isBundle())
            addOSCBundle (element->getBundle(), level + 1);
    }

    triggerAsyncUpdate();
}
//===============================================================================================
    void OSCLogListBox::addOSCMessageArgument (const OSCArgument& arg, int level)
    {
        String typeAsString;
        String valueAsString;

        if (arg.isFloat32())
        {
            typeAsString = "float32";
            valueAsString = String (arg.getFloat32());
        }
        else if (arg.isInt32())
        {
            typeAsString = "int32";
            valueAsString = String (arg.getInt32());
        }
        else if (arg.isString())
        {
            typeAsString = "string";
            valueAsString = arg.getString();
        }
        else if (arg.isBlob())
        {
            typeAsString = "blob";
            auto& blob = arg.getBlob();
            valueAsString = String::fromUTF8 ((const char*) blob.getData(), (int) blob.getSize());
        }
        else
        {
            typeAsString = "(unknown)";
        }

        oscLogList.add (getIndentationString (level + 1) + "- " + typeAsString.paddedRight(' ', 12) + valueAsString);
    }
//===============================================================================================
void OSCLogListBox::addInvalidOSCPacket (const char* /* data */, int dataSize)
{
    oscLogList.add ("- (" + String(dataSize) + "bytes with invalid format)");
}
//===============================================================================================
void OSCLogListBox::clear()
{
    oscLogList.clear();
    triggerAsyncUpdate();
}

//===============================================================================================
void OSCLogListBox::handleAsyncUpdate()
{
    updateContent();
    scrollToEnsureRowIsOnscreen (oscLogList.size() - 1);
    repaint();
}
