/*
  ==============================================================================

    ConnectedAnimation.h
    Created: 19 Apr 2020 5:33:20pm
    Author:  Christian Sager

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class ConnectionAnimation    : public Component

{
public:
    //===============================================================================================
    ConnectionAnimation()
    {
           
    }

    void paint (Graphics& g) override;
    void animate();
    void changeColour(Colour color);
private:
    //===============================================================================================

    //===============================================================================================
    int count;
    int inc;
    float x,y;
    Colour col;
    
};
