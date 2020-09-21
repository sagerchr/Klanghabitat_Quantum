/*
  ==============================================================================

    Comunication.cpp
    Created: 19 Sep 2020 5:25:51pm
    Author:  Christian Sager

  ==============================================================================
*/

#include "Comunication.h"

void Comunication::ConnectToBootloader(juce::String IP){

    //***********Connect to the device*****//
    socket->bindToPort(7);
    socket->connect(IP, 1000, 20000);
    socket->waitUntilReady(false, -1);
    //#####################################//
    
    //*********Create Message**************//
    for(int i=0; i<100;i++){
        recive[i] = 0x00;
    }
    
    CMD = 0xFF;
     
    write[0] = 0x01;
    write[1] = 0x00;
    write[2] = 0x00;
    write[3] = 0x00;
    write[4] = CMD;
    write[5] = 0x00;
    //#####################################//
    
    
    //*******Dial in to the Bootloader*****//
    socket->write(write, 6);
    socket->close();
    //#####################################//
    
    //***Connect to the strted Bootloader**//
    socket->bindToPort(7);
    socket->connect(IP, 1000, 20000);
    socket->waitUntilReady(false, -1);
    //Write again the CMD for INFO.
    socket->write(write, 6);
    socket->read(recive, 12, true);
    //#####################################//
}


void Comunication::disconnect(){
    socket->close();
    socket->~StreamingSocket();
}

void Comunication::restart(){
    CMD = 0xCF;
    write[0] = 0x12;
    write[1] = 0x00;
    write[2] = 0x00;
    write[3] = 0x00;
    write[4] = CMD;
    socket->write(write, 6);
}
