#include <MIDI.h>
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
bool pot0v = false;
bool pot1v = false;
bool pot2v = false;
bool pot3v = false;
bool pot4v = false;
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

int firstbyteIST;
char secondbyteIST;
char number;
char numberV;
int  IST_WERT;
String ist = "I";
String vorhanden = "V";

void setup() {
   Serial3.begin(115200); //Komunikation zu NANO_POT 
   Serial2.begin(115200); //Komunikation zu DEBUGGER 
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(15, INPUT_PULLUP);  
   MIDI.begin(); 
   MIDI.turnThruOff();
   delay(1000); //verzögern, damit NANO_POTs gebootet sind. 
}

void loop() 
{

     
     switch (POT_V) //POT_V vorhanden abfragen nur einmalig ausführen. 
     {
     case 0: {Serial3.write(":P0V***\n"); POT_V = 1;} break;
     case 1: {Serial3.write(":P1V***\n"); POT_V = 2;} break;
     case 2: {Serial3.write(":P2V***\n"); POT_V = 3;} break;
     case 3: {Serial3.write(":P3V***\n"); POT_V = 4;} break;
     case 4: {Serial3.write(":P4V***\n"); POT_V = 5;} break;
     case 5: {Serial3.write(":P5V***\n"); POT_V = 6;} break;
     case 6: {Serial3.write(":P6V***\n"); POT_V = 7;} break;
     case 7: {Serial3.write(":P7V***\n"); POT_V = 8;} break;
     case 8: {Serial3.write(":P8V***\n"); POT_V = 9;} break;
     case 9: {Serial3.write(":P9V***\n"); POT_V = 10;} break; //nur einmal durchlaufen daher nächstes CASE nicht vorhanden
     }
   
         
     switch (POT_IST) //POT_IST permanent abfragen (nur wenn vorhanden)
     {
     case 0: {if(pot0v){Serial3.write(":P0I***\n");} POT_IST = 1;} break;
     case 1: {if(pot1v){Serial3.write(":P1I***\n");} POT_IST = 2;} break;
     case 2: {if(pot2v){Serial3.write(":P2I***\n");} POT_IST = 3;} break;
     case 3: {if(pot3v){Serial3.write(":P3I***\n");} POT_IST = 4;} break;
     case 4: {if(pot4v){Serial3.write(":P4I***\n");} POT_IST = 5;} break;
     case 5: {if(pot5v){Serial3.write(":P5I***\n");} POT_IST = 6;} break;
     case 6: {if(pot6v){Serial3.write(":P6I***\n");} POT_IST = 7;} break;
     case 7: {if(pot7v){Serial3.write(":P7I***\n");} POT_IST = 8;} break;
     case 8: {if(pot8v){Serial3.write(":P8I***\n");} POT_IST = 9;} break;
     case 9: {if(pot9v){Serial3.write(":P9I***\n");} POT_IST = 0;} break;
     }

      
     

     
     if(Serial3.available() > 0) 
      {
      strIN = Serial3.readStringUntil('\n');
      StrINHeader = strIN.substring(3,4);   //Header (Komando) isolieren
      }
     

/******************************Wenn Header Vorhanden ist *********************************/
   if (StrINHeader == vorhanden) //feststellen welche POTs angeschlossen sind.
      {
      numberV = strIN.substring(2,3).toInt();  
      Serial2.write(numberV);
      StrINHeader = "NULL"; //StrINHeader mit "NULL" beschreiben damit unbekannt
      if (numberV == 0) {pot0v = true;}
      if (numberV == 1) {pot1v = true;}
      if (numberV == 2) {pot2v = true;}
      if (numberV == 3) {pot3v = true;}
      if (numberV == 4) {pot4v = true;}
      if (numberV == 5) {pot5v = true;} 
      if (numberV == 6) {pot6v = true;}
      if (numberV == 7) {pot7v = true;} 
      if (numberV == 8) {pot8v = true;} 
      if (numberV == 9) {pot9v = true;}     
      }

/******************************Wenn Header IST-WERT ist *********************************/
   if (StrINHeader == ist) //auslesen der IST-Wert für POTnumber
     {
     number = strIN.substring(2,3).toInt();
     firstbyteIST  = strIN.substring(4,5).toInt();
     secondbyteIST = strIN.substring(5,6).toInt();
     r = strIN.substring(6,7);
     if (r == "R") {runing = true;} if (r == "S") {runing = false;}
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
     
        if (number == 0) 
            {if (cc_wert_pot0 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot0 = IST_WERT;}
        if (number == 1) 
            {if (cc_wert_pot1 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot1 = IST_WERT;}
        if (number == 2) 
            {if (cc_wert_pot2 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot2 = IST_WERT;}            
        if (number == 3) 
            {if (cc_wert_pot3 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot3 = IST_WERT;}
        if (number == 4) 
            {if (cc_wert_pot5 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot4 = IST_WERT;}                 
        if (number == 5) 
            {if (cc_wert_pot5 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot5 = IST_WERT;}
        if (number == 6) 
            {if (cc_wert_pot6 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot6 = IST_WERT;}
        if (number == 7) 
            {if (cc_wert_pot7 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot7 = IST_WERT;}
        if (number == 8) 
            {if (cc_wert_pot8 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot8 = IST_WERT;}
        if (number == 9) 
            {if (cc_wert_pot9 != IST_WERT)
                 {MIDI.sendControlChange(number,IST_WERT,midichannel);}
            cc_wert_pot9 = IST_WERT;}                                    
            
       Serial2.write(IST_WERT);
       StrINHeader = "NULL"; //StrINHeader mit "NULL" beschreiben damit unbekannt
     } 
}
    


