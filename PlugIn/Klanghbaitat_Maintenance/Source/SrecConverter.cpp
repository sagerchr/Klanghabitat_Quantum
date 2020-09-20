/*
  ==============================================================================

    SrecConverter.cpp
    Created: 19 Sep 2020 5:26:57pm
    Author:  Christian Sager

  ==============================================================================
*/

#include "SrecConverter.h"

juce::String SrecConverter::readFile(juce::File path){
    //juce::File path ("/Users/christiansager/klanghabitat_quantum/PlugIn/download/Display.srec");
    juce::String line;
    juce::String data;
     data = path.loadFileAsString();
     
     juce::FileInputStream inputStream (path);

    int lineCount = 0;
         while (! inputStream.isExhausted())
    {
        auto currentLine = inputStream.readNextLine();
        line.append(currentLine,currentLine.length());
        line.append("*",1);
        line.append("\r\n",2);
        lineCount++;
    }
return line;
   // auto length = line.length();
}

