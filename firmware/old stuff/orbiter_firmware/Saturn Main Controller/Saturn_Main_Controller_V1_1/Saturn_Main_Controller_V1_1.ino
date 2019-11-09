#include "AH_MCP4922.h"
#include <MIDI.h>
AH_MCP4922 AnalogOutput1(51,52,9,LOW,HIGH);    //define AnalogOutput1 for MEGA_board, select DAC_A, Gain=1x
AH_MCP4922 AnalogOutput2(51,52,9,HIGH,HIGH);
AH_MCP4922 AnalogOutput3(51,52,10,LOW,LOW);    //define AnalogOutput1 for MEGA_board, select DAC_A, Gain=1x
AH_MCP4922 AnalogOutput4(51,52,10,HIGH,LOW);
MIDI_CREATE_DEFAULT_INSTANCE();

String strIN;
int i;
bool blinker = false;
bool test = false;
String StrINHeader;
int POT_IST = 0;
int POT_V = 0;
int midichannel = 1;
String r;
bool runing = false;
int data=0;
bool pot0v = true;
bool pot1v = true;
bool pot2v = true;
bool pot3v = true;
bool pot4v = true;
bool pot5v = false;
bool pot6v = false;
bool pot7v = false;
bool pot8v = false;
bool pot9v = false;

int cc_wert_pot0 = 0;
int cc_wert_pot1 = 0;
int cc_wert_pot2 = 0;
int cc_wert_pot3 = 0;
int cc_wert_pot4 = 0;
int cc_wert_pot5 = 0;
int cc_wert_pot6 = 0;
int cc_wert_pot7 = 0;
int cc_wert_pot8 = 0;
int cc_wert_pot9 = 0;

int lastSoll0 = 0;
int lastSoll1 = 0;
int lastSoll2 = 0;
int lastSoll3 = 0;
int lastSoll4 = 0;
int lastSoll5 = 0;
int lastSoll6 = 0;
int lastSoll7 = 0;
int lastSoll8 = 0;
int lastSoll9 = 0;

int firstbyteIST;
int secondbyteIST;
int thirdbyteIST;
char number;
char numberV;
int  IST_WERT;
String ist = "I";
String vorhanden = "V";

int channel;

bool count = false;

int POT_POS = 0;

bool sending  = false;
bool sending2 = false;

int  data1;
int  data2;
char firstbyteSOLL; //Erstes byte für FADER IST - Wert
char secondbyteSOLL; //Zweites byte für FADER IST - Wert
char thirdbyteSOLL;




void setup() {
   Serial3.begin(57600); //Komunikation zu NANO_POT 

   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(15, INPUT_PULLUP);  
   MIDI.begin(); 
   MIDI.turnThruOff();
   AnalogOutput1.setValue(0);
   AnalogOutput2.setValue(0);

}

/* Variablen für encoderweel1 */

/*****************************/
int MODE = 0;
float Millis = 0;
float Millislast = 0;
void loop() 
{

   Millis= millis() - Millislast; 
   if (Millis > 4)
   {  
     switch (POT_IST) //POT_IST permanent abfragen 
     {
     case 0: {Serial3.write(":P0I\n"); POT_IST = 1;} break;
     case 1: {Serial3.write(":P1I\n"); POT_IST = 2;} break;
     case 2: {Serial3.write(":P2I\n"); POT_IST = 3;} break;
     case 3: {Serial3.write(":P3I\n"); POT_IST = 4;} break;
     case 4: {Serial3.write(":P4I\n"); POT_IST = 0;} break;
     
     }
    
    Millislast= millis();
   } 
     
if (MIDI.read()) {

    channel =   MIDI.getData1();
    data2 =   MIDI.getData2()/2;

    if (channel == 0){lastSoll0 = data2;}
    if (channel == 1){lastSoll1 = data2;}
    if (channel == 2){lastSoll2 = data2;}
    if (channel == 3){lastSoll3 = data2;}
    if (channel == 4){lastSoll4 = data2;}
    if (channel == 5){lastSoll5 = data2;}
    if (channel == 6){lastSoll6 = data2;}
    if (channel == 7){lastSoll7 = data2;}
    if (channel == 8){lastSoll8 = data2;}
    if (channel == 9){lastSoll9 = data2;}

      if (data2<100)
      {
        thirdbyteSOLL = '0';
        if (data2< 10){firstbyteSOLL = '0'; secondbyteSOLL = char(data2+48);}
        if (data2 >= 10 && data2 <20 ){firstbyteSOLL = '1'; secondbyteSOLL = char(data2+38);}
        if (data2 >= 20 && data2 <30 ){firstbyteSOLL = '2'; secondbyteSOLL = char(data2+28);}
        if (data2 >= 30 && data2 <40 ){firstbyteSOLL = '3'; secondbyteSOLL = char(data2+18);}
        if (data2 >= 40 && data2 <50 ){firstbyteSOLL = '4'; secondbyteSOLL = char(data2+8);}
        if (data2 >= 50 && data2 <60 ){firstbyteSOLL = '5'; secondbyteSOLL = char(data2-2);}
        if (data2 >= 60 && data2 <70 ){firstbyteSOLL = '6'; secondbyteSOLL = char(data2-12);}
        if (data2 >= 70 && data2 <80 ){firstbyteSOLL = '7'; secondbyteSOLL = char(data2-22);}
        if (data2 >= 80 && data2 <90 ){firstbyteSOLL = '8'; secondbyteSOLL = char(data2-32);}
        if (data2 >= 90 && data2 <100 ){firstbyteSOLL = '9';secondbyteSOLL = char(data2-42);}
      }
       if (data2 >= 100)
       {
        thirdbyteSOLL = '1';
        if (data2< 110){firstbyteSOLL = '0'; secondbyteSOLL = char(data2-52);}
        if (data2 >= 110 && data2 <120 ){firstbyteSOLL = '1'; secondbyteSOLL = char(data2-62);}
        if (data2 >= 120 && data2 <130 ){firstbyteSOLL = '2'; secondbyteSOLL = char(data2-72);}
        if (data2 >= 130 && data2 <140 ){firstbyteSOLL = '3'; secondbyteSOLL = char(data2-82);}
        if (data2 >= 140 && data2 <150 ){firstbyteSOLL = '4'; secondbyteSOLL = char(data2-92);}
        if (data2 >= 150 && data2 <160 ){firstbyteSOLL = '5'; secondbyteSOLL = char(data2-102);}
        if (data2 >= 160 && data2 <170 ){firstbyteSOLL = '6'; secondbyteSOLL = char(data2-112);}
        if (data2 >= 170 && data2 <180 ){firstbyteSOLL = '7'; secondbyteSOLL = char(data2-122);}
        if (data2 >= 180 && data2 <190 ){firstbyteSOLL = '8'; secondbyteSOLL = char(data2-132);}
        if (data2 >= 190){firstbyteSOLL = '9'; secondbyteSOLL = '0';}
       }
    sending = false;
    if(sending == false)
    {
    Serial3.write(':');
    Serial3.write('P');
    Serial3.write(channel+48);
    Serial3.write('P');
    Serial3.write(firstbyteSOLL); //erstes Datenbyte
    Serial3.write(secondbyteSOLL); //zweites Datenbyte
    Serial3.write(thirdbyteSOLL);
    Serial3.write('\n');
    count = true;
    }
    
}


      
     if(Serial3.available() > 0) 
      {
      strIN = Serial3.readStringUntil('\n');
      StrINHeader = strIN.substring(3,4);   //Header (Komando) isolieren
      }
     
/******************************Wenn Header IST-WERT ist *********************************/
   if (StrINHeader == ist) //auslesen der IST-Wert für POTnumber
     {
     number = strIN.substring(2,3).toInt();
     firstbyteIST  = strIN.substring(4,5).toInt();
     secondbyteIST = strIN.substring(5,6).toInt();
     thirdbyteIST = strIN.substring(6,7).toInt();
     MODE = strIN.substring(7,8).toInt();
     
     if (thirdbyteIST == 0)
     {
     if (firstbyteIST == 0) {IST_WERT = firstbyteIST + secondbyteIST;} //firstbyte = 0
     if (firstbyteIST == 1) {IST_WERT = secondbyteIST +10;} //firstbyte = 1
     if (firstbyteIST == 2) {IST_WERT = secondbyteIST +20;} //firstbyte = 2
     if (firstbyteIST == 3) {IST_WERT = secondbyteIST +30;} //firstbyte = 3 
     if (firstbyteIST == 4) {IST_WERT = secondbyteIST +40;} //firstbyte = 4
     if (firstbyteIST == 5) {IST_WERT = secondbyteIST +50;} //firstbyte = 5
     if (firstbyteIST == 6) {IST_WERT = secondbyteIST +60;} //firstbyte = 6
     if (firstbyteIST == 7) {IST_WERT = secondbyteIST +70;} //firstbyte = 7
     if (firstbyteIST == 8) {IST_WERT = secondbyteIST +80;} //firstbyte = 8
     if (firstbyteIST == 9) {IST_WERT = secondbyteIST +90;} //firstbyte = 9
     }
     if (thirdbyteIST == 1)
     {
     if (firstbyteIST == 0) {IST_WERT = firstbyteIST + secondbyteIST+100;} //firstbyte = 0
     if (firstbyteIST == 1) {IST_WERT = secondbyteIST +110;} //firstbyte = 1
     if (firstbyteIST == 2) {IST_WERT = secondbyteIST +120;} //firstbyte = 2
     if (firstbyteIST == 3) {IST_WERT = secondbyteIST +130;} //firstbyte = 3 
     if (firstbyteIST == 4) {IST_WERT = secondbyteIST +140;} //firstbyte = 4
     if (firstbyteIST == 5) {IST_WERT = secondbyteIST +150;} //firstbyte = 5
     if (firstbyteIST == 6) {IST_WERT = secondbyteIST +160;} //firstbyte = 6
     if (firstbyteIST == 7) {IST_WERT = secondbyteIST +170;} //firstbyte = 7
     if (firstbyteIST == 8) {IST_WERT = secondbyteIST +180;} //firstbyte = 8
     if (firstbyteIST == 9) {IST_WERT = secondbyteIST +190;} //firstbyte = 9
     }

     
        if (number == 0) {if (cc_wert_pot0 != IST_WERT && IST_WERT != lastSoll0) {MIDI.sendControlChange(number,IST_WERT,midichannel);AnalogOutput2.setValue(1*((cc_wert_pot0)+900));} cc_wert_pot0 = IST_WERT;}
        if (number == 1) {if (cc_wert_pot1 != IST_WERT && IST_WERT != lastSoll1) {MIDI.sendControlChange(number,IST_WERT,midichannel);AnalogOutput1.setValue(1*((cc_wert_pot1*20)+1900));} cc_wert_pot1 = IST_WERT;}
        if (number == 2) {if (cc_wert_pot2 != IST_WERT) {MIDI.sendControlChange(number,IST_WERT,midichannel);} cc_wert_pot2 = IST_WERT;}            
        if (number == 3) {if (cc_wert_pot3 != IST_WERT) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot3 = IST_WERT;}
        if (number == 4) {if (cc_wert_pot4 != IST_WERT) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot4 = IST_WERT;}                 
        if (number == 5) {if (cc_wert_pot5 != IST_WERT) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot5 = IST_WERT;}
        if (number == 6) {if (cc_wert_pot6 != IST_WERT) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot6 = IST_WERT;}
        if (number == 7) {if (cc_wert_pot7 != IST_WERT) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot7 = IST_WERT;}
        if (number == 8) {if (cc_wert_pot8 != IST_WERT) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot8 = IST_WERT;}
        if (number == 9) {if (cc_wert_pot9 != IST_WERT) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot9 = IST_WERT;}                                    
         

       StrINHeader = "NULL"; //StrINHeader mit "NULL" beschreiben damit unbekannt

     } 

}


