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
    Comunication::reciveClear();
    
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


void Comunication::programStart(){
    
    Comunication::reciveClear();
    
    CMD = 0xD2;
     
    write[0] = 0x01;
    write[1] = 0x00;
    write[2] = 0x00;
    write[3] = 0x00;
    write[4] = CMD;
    
    socket->write(write, 5);
    socket->read(recive, 11, true);
}


void Comunication::cleanProgram(juce::String Adress, juce::String length){
    
    Comunication::reciveClear();
    
    juce::String Adresscorrected = Comunication::Adressinversion(Adress);

    CMD = 0xF6;
     
    write[0] = 0x01;
    write[1] = 0x00;
    write[2] = 0x00;
    write[3] = 0x00;
    write[4] = CMD;
    write[5] = 0x00;
    write[6] = 0x00;
    write[7] = 0x00;
    write[8] = Adresscorrected.substring(0,2).getHexValue32();
    write[9] = Adresscorrected.substring(2,4).getHexValue32();
    write[10] = Adresscorrected.substring(4,6).getHexValue32();
    write[11] = Adresscorrected.substring(6,8).getHexValue32();
    
    socket->write(write, 12);
    socket->read(recive, 5, true);
    
    Comunication::reciveClear();
    
    Adresscorrected = Comunication::Adressinversion(length);
    
    CMD = 0xD1;
     
    write[0] = 0x01;
    write[1] = 0x00;
    write[2] = 0x00;
    write[3] = 0x00;
    write[4] = CMD;
    write[5] = 0x00;
    write[6] = 0x00;
    write[7] = 0x00;
    write[8] = Adresscorrected.substring(0,2).getHexValue32();
    write[9] = Adresscorrected.substring(2,4).getHexValue32();
    write[10] = Adresscorrected.substring(4,6).getHexValue32();
    write[11] = Adresscorrected.substring(6,8).getHexValue32();
    
    socket->write(write, 12);
    socket->read(recive, 5, true);
 
}
void Comunication::program(juce::String Adress, juce::String payload, juce::String length){
    Comunication::reciveClear();
    
    juce::String Adresscorrected = Comunication::Adressinversion(Adress);

    CMD = 0xF6;
     
    write[0] = 0x01;
    write[1] = 0x00;
    write[2] = 0x00;
    write[3] = 0x00;
    write[4] = CMD;
    write[5] = 0x00;
    write[6] = 0x00;
    write[7] = 0x00;
    write[8] = Adresscorrected.substring(0,2).getHexValue32();
    write[9] = Adresscorrected.substring(2,4).getHexValue32();
    write[10] = Adresscorrected.substring(4,6).getHexValue32();
    write[11] = Adresscorrected.substring(6,8).getHexValue32();
    
    socket->write(write, 12);
    socket->read(recive, 5, true);
    
    Comunication::reciveClear();
        
    
    
    CMD = 0xD0;
     
    write[0] = 0x01;
    write[1] = 0x00;
    write[2] = 0x00;
    write[3] = 0x00;
    write[4] = CMD;
    write[5] = length.getHexValue32()-5;
    
    
    int lengthHEX;
    int lengthINT;
    
    lengthHEX = length.getHexValue32();
    lengthINT = length.getIntValue();
    int packageLength;
    int p = 0;
    for(int i=0; i<length.getHexValue32();i++){
       
        write[i+6] = payload.substring(p,p+2).getHexValue32();
        packageLength = i+6;
         p=p+2;
    }

    
    socket->write(write, packageLength);
    socket->read(recive, 5, true);
    
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


juce::String Comunication::Adressinversion(juce::String Adress){
    juce::String part1 = Adress.substring(6,8);
    juce::String part2 = Adress.substring(4,6);
    juce::String part3 = Adress.substring(2,4);
    juce::String part4 = Adress.substring(0,2);
    
    return part1+part2+part3+part4;
}

void Comunication::reciveClear(){
    for(int i=0; i<100;i++){
        recive[i] = 0x00;
    }
}

