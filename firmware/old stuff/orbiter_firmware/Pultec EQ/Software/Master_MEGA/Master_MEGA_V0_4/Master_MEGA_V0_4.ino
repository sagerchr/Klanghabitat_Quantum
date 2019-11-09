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

int     data1;
int     data2;
char firstbyteSOLL; //Erstes byte für FADER IST - Wert
char secondbyteSOLL; //Zweites byte für FADER IST - Wert
char thirdbyteSOLL;

int t = 0;

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
     case 1: {if(pot1v){Serial3.write(":P1I***\n");} POT_IST = 0;} break;
     /*case 2: {if(pot2v){Serial3.write(":P2I***\n");} POT_IST = 3;} break;
     case 3: {if(pot3v){Serial3.write(":P3I***\n");} POT_IST = 4;} break;
     case 4: {if(pot4v){Serial3.write(":P4I***\n");} POT_IST = 5;} break;
     case 5: {if(pot5v){Serial3.write(":P5I***\n");} POT_IST = 6;} break;
     case 6: {if(pot6v){Serial3.write(":P6I***\n");} POT_IST = 7;} break;
     case 7: {if(pot7v){Serial3.write(":P7I***\n");} POT_IST = 8;} break;
     case 8: {if(pot8v){Serial3.write(":P8I***\n");} POT_IST = 9;} break;
     case 9: {if(pot9v){Serial3.write(":P9I***\n");} POT_IST = 0;} break;
     */
     }
    
     
if (MIDI.read()) {

    channel =   MIDI.getData1();
    data2 =   MIDI.getData2();

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
     

/******************************Wenn Header Vorhanden ist *********************************/
   if (StrINHeader == vorhanden) //feststellen welche POTs angeschlossen sind.
      {
      numberV = strIN.substring(2,3).toInt();  
      Serial2.write(numberV); //An Debugger senden...
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
     thirdbyteIST = strIN.substring(6,7).toInt();
     r = strIN.substring(7,8);

     if (r == "R") {runing = true;} if (r == "S") {runing = false;}
     
     
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

     
        if (number == 0) {if (cc_wert_pot0 != IST_WERT && IST_WERT != lastSoll0) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot0 = IST_WERT;}
        if (number == 1) {if (cc_wert_pot1 != IST_WERT && IST_WERT != lastSoll1) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot1 = IST_WERT;}
        if (number == 2) {if (cc_wert_pot2 != IST_WERT && IST_WERT != lastSoll2) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot2 = IST_WERT;}            
        if (number == 3) {if (cc_wert_pot3 != IST_WERT && IST_WERT != lastSoll3) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot3 = IST_WERT;}
        if (number == 4) {if (cc_wert_pot4 != IST_WERT && IST_WERT != lastSoll4) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot4 = IST_WERT;}                 
        if (number == 5) {if (cc_wert_pot5 != IST_WERT && IST_WERT != lastSoll5) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot5 = IST_WERT;}
        if (number == 6) {if (cc_wert_pot6 != IST_WERT && IST_WERT != lastSoll6) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot6 = IST_WERT;}
        if (number == 7) {if (cc_wert_pot7 != IST_WERT && IST_WERT != lastSoll7) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot7 = IST_WERT;}
        if (number == 8) {if (cc_wert_pot8 != IST_WERT && IST_WERT != lastSoll8) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot8 = IST_WERT;}
        if (number == 9) {if (cc_wert_pot9 != IST_WERT && IST_WERT != lastSoll9) {MIDI.sendControlChange(number,IST_WERT,midichannel);sending = true; sending2 = true;} cc_wert_pot9 = IST_WERT;}                                    
            
       
       StrINHeader = "NULL"; //StrINHeader mit "NULL" beschreiben damit unbekannt
     } 

if (sending == true and t < 500)
{
if (sending2 == true) {t = 0, sending2 = false;}  
t = t+1;   
digitalWrite(13, HIGH);
}

if (t >= 500)
{
t = 0;   
digitalWrite(13, LOW);
sending = false;
}

 
}
    


