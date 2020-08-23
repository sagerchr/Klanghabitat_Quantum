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

 name:             FileReadingTutorial
 version:          2.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Reads and displays a text file.

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics
 exporters:        xcode_mac, vs2017, linux_make

 type:             Component
 mainClass:        MainContentComponent

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/


#pragma once

//==============================================================================
class MainContentComponent   : public juce::Component,
                               public juce::FilenameComponentListener
{
public:
    MainContentComponent()
    {
        fileComp.reset (new juce::FilenameComponent ("fileComp",
                                                     {},                       // current file
                                                     false,                    // can edit file name,
                                                     false,                    // is directory,
                                                     false,                    // is for saving,
                                                     {},                       // browser wildcard suffix,
                                                     {},                       // enforced suffix,
                                                     "Select file to open"));  // text when nothing selected
        addAndMakeVisible (fileComp.get());
        fileComp->addListener (this);

        textContent.reset (new juce::TextEditor());
        addAndMakeVisible (textContent.get());
        textContent->setMultiLine (true);
        textContent->setReadOnly (true);
        textContent->setCaretVisible (false);

        setSize (600, 400);
    }

    void resized() override
    {
        fileComp->setBounds    (10, 10, getWidth() - 20, 20);
        textContent->setBounds (10, 40, getWidth() - 20, getHeight() - 50);
    }

    void filenameComponentChanged (juce::FilenameComponent* fileComponentThatHasChanged) override
    {
        if (fileComponentThatHasChanged == fileComp.get())
            readFile (fileComp->getCurrentFile());
    }

    void readFile (const juce::File& fileToRead)
    {
        if (! fileToRead.existsAsFile())
            return;  // file doesn't exist

        juce::FileInputStream inputStream (fileToRead); // [2]

        if (! inputStream.openedOk())
            return;  // failed to open

        textContent->clear();

        auto normalFont = textContent->getFont();
        auto titleFont  = normalFont.withHeight (normalFont.getHeight() * 1.5f).boldened();
        juce::String asterix ("*");

        while (! inputStream.isExhausted()) // [3]
        {
            auto line = inputStream.readNextLine();

            if (line.startsWith (asterix))
            {
                line = line.removeCharacters (asterix);
                textContent->setFont (titleFont);
            }
            else
            {
                textContent->setFont (normalFont);
            }

            // append the text to the textContent
            textContent->insertTextAtCaret (line + juce::newLine);
        }
    }

private:
    std::unique_ptr<juce::FilenameComponent> fileComp;
    std::unique_ptr<juce::TextEditor>        textContent;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
