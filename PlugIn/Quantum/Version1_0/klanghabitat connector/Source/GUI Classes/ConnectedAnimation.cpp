/*
  ==============================================================================

    ConnectedAnimation.cpp
    Created: 19 Apr 2020 5:33:20pm
    Author:  Christian Sager

  ==============================================================================
*/

#include "ConnectedAnimation.h"


void ConnectionAnimation::paint (Graphics& g){
    //g.setColour (Colours::orange);
    g.setColour (col);
    g.drawEllipse(10+x, 10+y, 4, 4, 4);
}

void ConnectionAnimation::changeColour(Colour color){
    col = color;
}


void ConnectionAnimation::animate(){
    count+=2;
    if (count >= 360){
        count = 0;
    }
    x = 8*sin(3.14/180*count);
    y = 8*cos(3.14/180*count);

    repaint();
}
