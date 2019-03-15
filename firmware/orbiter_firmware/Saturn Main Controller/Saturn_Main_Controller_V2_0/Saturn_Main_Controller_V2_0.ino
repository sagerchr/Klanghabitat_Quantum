//#include "AH_MCP4922.h"
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
const int bSize = 6; //Größe der PotAnswer
byte Buffer[bSize];
int CHANNEL_MIDI = 1;

int CCnumber = 255;
int CCvalue = 255;

void setup() {
   Serial3.begin(57600); //Komunikation zu NANO_POT 
   //Serial2.begin(57600); //Komunikation zu Deubugger
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(15, INPUT_PULLUP);  
   MIDI.begin(); 
   MIDI.turnThruOff(); 
   Buffer [0]= 0xFF; 
   delay(3000); //Verszögerung damit alle Pots gebootet sind
}
/*                       [0]    [1]   [2]   [3]   [4]   [5]   [6]   [7]   [8]   [9]   [10]  [11]
/***********************{Pot,listen, Mode, Val1, Val2, Val3, Val4, Val5, Val6, Val7, Val8, CMD, END}***/ 
byte PotStream0[] =     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream1[] =     {0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream2[] =     {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream3[] =     {0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream4[] =     {0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};

byte PotStream0Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream1Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream2Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream3Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream4Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};

bool SendStream0 = true;
bool SendStream1 = true;
bool SendStream2 = true;
bool SendStream3 = true;
bool SendStream4 = true;

bool timerset0 = true;
float timer0 = 0;
float timer0start = 0;

bool timerset1 = true;
float timer1 = 0;
float timer1start = 0;

bool timerset2 = true;
float timer2 = 0;
float timer2start = 0;

bool timerset3 = true;
float timer3 = 0;
float timer3start = 0;

bool timerset4 = true;
float timer4 = 0;
float timer4start = 0;


float sendwait = 100;

int POT_STREAM = 0;
float Millis = 0;
float Millislast = 0;


void loop() 
{
/*****************MIDI Input aufnehemen und in Potstream übernehmen******************************/

      if(MIDI.read()) 
          {
          CCnumber  =   MIDI.getData1();
          CCvalue   =   MIDI.getData2();

          if (CCnumber >= 00 && CCnumber <= 7 ) {PotStream0[CCnumber+3]  = CCvalue; PotStream0[11] = 0x01; timerset0 =true; timer0start = millis(); SendStream0 = false;}
          if (CCnumber >= 10 && CCnumber <= 17) {PotStream1[CCnumber-7]  = CCvalue; PotStream1[11] = 0x01; timerset1 =true; timer1start = millis(); SendStream1 = false;}
          if (CCnumber >= 20 && CCnumber <= 27) {PotStream2[CCnumber-17] = CCvalue; PotStream2[11] = 0x01; timerset2 =true; timer2start = millis(); SendStream2 = false;}
          if (CCnumber >= 30 && CCnumber <= 37) {PotStream3[CCnumber-27] = CCvalue; PotStream3[11] = 0x01; timerset3 =true; timer3start = millis(); SendStream3 = false;}
          if (CCnumber >= 40 && CCnumber <= 47) {PotStream4[CCnumber-37] = CCvalue; PotStream4[11] = 0x01; timerset4 =true; timer4start = millis(); SendStream4 = false;}    
           } 
/**************************************STREAM senden**********************************************/
   Millis= millis() - Millislast; 
   if (Millis >=5) //Sendeverzögerung
   {  
     switch (POT_STREAM) 
     {
     case 0: {Serial3.write(PotStream0, sizeof(PotStream0)); POT_STREAM = 1;Serial3.flush();} break;
     case 1: {Serial3.write(PotStream1, sizeof(PotStream1)); POT_STREAM = 2;Serial3.flush();} break;
     case 2: {Serial3.write(PotStream2, sizeof(PotStream2)); POT_STREAM = 3;Serial3.flush();} break;
     case 3: {Serial3.write(PotStream3, sizeof(PotStream3)); POT_STREAM = 4;Serial3.flush();} break;
     case 4: {Serial3.write(PotStream4, sizeof(PotStream4)); POT_STREAM = 0;Serial3.flush();} break;
     }
    Millislast= millis();
   }
/***********************Wenn CMD auf 0x01 in einem Stream geht senden unterbinden x ms***********/
if (timerset0 == true) {timer0 = millis() - timer0start;}
if (PotStream0 [11] == 0x01 && timer0 > sendwait) {PotStream0 [11] = 0x00; SendStream0 = true; timerset0 == false;}

if (timerset1 == true) {timer1 = millis() - timer1start;}
if (PotStream1 [11] == 0x01 && timer1 > sendwait) {PotStream1 [11] = 0x00; SendStream1 = true; timerset1 == false;}

if (timerset2 == true) {timer2 = millis() - timer2start;}
if (PotStream2 [11] == 0x01 && timer2 > sendwait) {PotStream2 [11] = 0x00; SendStream2 = true; timerset2 == false;}

if (timerset3 == true) {timer3 = millis() - timer2start;}
if (PotStream3 [11] == 0x01 && timer3 > sendwait) {PotStream2 [11] = 0x00; SendStream3 = true; timerset3 == false;}

if (timerset4 == true) {timer4 = millis() - timer4start;}
if (PotStream4 [11] == 0x01 && timer4 > sendwait) {PotStream4 [11] = 0x00; SendStream4 = true; timerset4 == false;}

   
/*******************************Buffer des Input Streams aufnehmen********************************/
      if(Serial3.available() > 0) 
        {
          Serial3.readBytesUntil(0xFF, Buffer, bSize); 
        }

 
if (Buffer [0] == 0) /*Pot0 Kommunikation*********************************************************/
             {  
              /***************************PotStreamLast merken************************************/
               for (int i = 0; i < 13; i++)
                {
                PotStream0Last [i] = PotStream0 [i];      
                }
              /**********************************************************************************/
                
              /**************************UPDATE POTSREAM*****************************************/    
              PotStream0 [0] = Buffer [0];            //PotNumber
              PotStream0 [1] = Buffer [1];            //Listen des POTS
              PotStream0 [2] = Buffer [2];            //Mode des POTS
              PotStream0 [Buffer [2]+3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
              /**********************************************************************************/ 
              
              /***************************Je nach Mode Wert senden*******************************/
               for (int i = 3; i < 13; i++)
                  {
                   if (PotStream0Last [i] != PotStream0 [i] && SendStream0)  
                    {
                     MIDI.sendControlChange(PotStream0[2]+0,PotStream0[PotStream0[2]+3],CHANNEL_MIDI);
                    }
                  } 
                
              /**********************************************************************************/      
             }      

if (Buffer [0] == 1) /*Pot1 Kommunikation*********************************************************/
             {  
              /***************************PotStreamLast merken************************************/
               for (int i = 0; i < 13; i++)
                {
                PotStream1Last [i] = PotStream1 [i];      
                }
              /**********************************************************************************/
                
              /**************************UPDATE POTSREAM*****************************************/    
              PotStream1 [0] = Buffer [0];            //PotNumber
              PotStream1 [1] = Buffer [1];            //Listen des POTS
              PotStream1 [2] = Buffer [2];            //Mode des POTS
              PotStream1 [Buffer [2]+3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
              /**********************************************************************************/ 
              
              /***************************Je nach Mode Wert senden*******************************/
               for (int i = 3; i < 13; i++)
                  {
                   if (PotStream1Last [i] != PotStream1 [i] && SendStream1)  
                    {
                     MIDI.sendControlChange(PotStream1[2]+10,PotStream1[PotStream1[2]+3],CHANNEL_MIDI);
                    }
                  } 
               
              /**********************************************************************************/      
             }    

if (Buffer [0] == 2) /*Pot2 Kommunikation*********************************************************/
             {  
              /***************************PotStreamLast merken************************************/
               for (int i = 0; i < 13; i++)
                {
                PotStream2Last [i] = PotStream2 [i];      
                }
              /**********************************************************************************/
                
              /**************************UPDATE POTSREAM*****************************************/    
              PotStream2 [0] = Buffer [0];            //PotNumber
              PotStream2 [1] = Buffer [1];            //Listen des POTS
              PotStream2 [2] = Buffer [2];            //Mode des POTS
              PotStream2 [Buffer [2]+3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
              /**********************************************************************************/ 
              
              /***************************Je nach Mode Wert senden*******************************/
               for (int i = 3; i < 13; i++)
                  {
                   if (PotStream2Last [i] != PotStream2 [i] && SendStream2)  
                    {
                     MIDI.sendControlChange(PotStream2[2]+20,PotStream2[PotStream2[2]+3],CHANNEL_MIDI);
                    }
                  } 
                  
              /**********************************************************************************/      
             } 

if (Buffer [0] == 3) /*Pot3 Kommunikation*********************************************************/
             {  
              /***************************PotStreamLast merken************************************/
               for (int i = 0; i < 13; i++)
                {
                PotStream3Last [i] = PotStream3 [i];      
                }
              /**********************************************************************************/
                
              /**************************UPDATE POTSREAM*****************************************/    
              PotStream3 [0] = Buffer [0];            //PotNumber
              PotStream3 [1] = Buffer [1];            //Listen des POTS
              PotStream3 [2] = Buffer [2];            //Mode des POTS
              PotStream3 [Buffer [2]+3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
              /**********************************************************************************/ 
              
              /***************************Je nach Mode Wert senden*******************************/
               for (int i = 3; i < 13; i++)
                  {
                   if (PotStream3Last [i] != PotStream3 [i] && SendStream3)  
                    {
                     MIDI.sendControlChange(PotStream3[2]+30,PotStream3[PotStream3[2]+3],CHANNEL_MIDI);
                    }
                  } 
                  
              /**********************************************************************************/      
             }              

if (Buffer [0] == 4) /*Pot4 Kommunikation*********************************************************/
             {  
              /***************************PotStreamLast merken************************************/
               for (int i = 0; i < 13; i++)
                {
                PotStream4Last [i] = PotStream4 [i];      
                }
              /**********************************************************************************/
                
              /**************************UPDATE POTSREAM*****************************************/    
              PotStream4 [0] = Buffer [0];            //PotNumber
              PotStream4 [1] = Buffer [1];            //Listen des POTS
              PotStream4 [2] = Buffer [2];            //Mode des POTS
              PotStream4 [Buffer [2]+3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
              /**********************************************************************************/ 
              
              /***************************Je nach Mode Wert senden*******************************/
               for (int i = 3; i < 13; i++)
                  {
                   if (PotStream4Last [i] != PotStream4 [i] && SendStream4)  
                    {
                     MIDI.sendControlChange(PotStream4[2]+40,PotStream4[PotStream4[2]+3],CHANNEL_MIDI);
                    }
                  }
           
              /**********************************************************************************/      
             }           


}
