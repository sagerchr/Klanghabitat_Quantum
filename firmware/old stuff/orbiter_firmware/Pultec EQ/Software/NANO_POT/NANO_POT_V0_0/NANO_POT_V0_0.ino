#include <Encoder.h>
Encoder myEnc(11, 12);
bool   blinker = false;
bool   OK = true;
char   runing;
String strIN;
String StrINHeader;
String ist;
String vorhanden;
String Refstart;
String Refstartbroad;
String Refstate;
String Position;
int sensorValue;

int SollPosition;
char number; //POT number

void setup() {
  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  int pin2 = digitalRead(2);
  int pin3 = digitalRead(3);
  int pin4 = digitalRead(4);
  int pin5 = digitalRead(5);

  if (pin2 == true && pin3 == true && pin4 == true && pin5 == true)  
     {number = '0'; ist = ":P0I"; vorhanden = ":P0V"; Refstart = ":P0R"; Refstartbroad = "*R"; Refstate = ":P0S"; Position = ":P0P";}
  if (pin2 == false && pin3 == true && pin4 == true && pin5 == true) 
     {number = '1'; ist = ":P1I"; vorhanden = ":P1V"; Refstart = ":P1R"; Refstartbroad = "*R"; Refstate = ":P1S"; Position = ":P1P";}
  if (pin2 == true && pin3 == false && pin4 == true && pin5 == true) 
     {number = '2'; ist = ":P2I"; vorhanden = ":P2V"; Refstart = ":P2R"; Refstartbroad = "*R"; Refstate = ":P2S"; Position = ":P2P";}  
  if (pin2 == true && pin3 == true && pin4 == false && pin5 == true) 
     {number = '3'; ist = ":P3I"; vorhanden = ":P3V"; Refstart = ":P3R"; Refstartbroad = "*R"; Refstate = ":P3S"; Position = ":P3P";}
  if (pin2 == true && pin3 == true && pin4 == true && pin5 == true) 
     {number = '4'; ist = ":P4I"; vorhanden = ":P4V"; Refstart = ":P4R"; Refstartbroad = "*R"; Refstate = ":P4S"; Position = ":P4P";}
  if (pin2 == true && pin3 == true && pin4 == true && pin5 == true) 
     {number = '5'; ist = ":P5I"; vorhanden = ":P5V"; Refstart = ":P5R"; Refstartbroad = "*R"; Refstate = ":P5S"; Position = ":P5P";}
  if (pin2 == true && pin3 == true && pin4 == true && pin5 == true) 
     {number = '6'; ist = ":P6I"; vorhanden = ":P6V"; Refstart = ":P6R"; Refstartbroad = "*R"; Refstate = ":P6S"; Position = ":P6P";}
  if (pin2 == true && pin3 == true && pin4 == true && pin5 == true) 
     {number = '7'; ist = ":P7I"; vorhanden = ":P7V"; Refstart = ":P7R"; Refstartbroad = "*R"; Refstate = ":P7S"; Position = ":P7P";}
  if (pin2 == true && pin3 == true && pin4 == true && pin5 == true) 
     {number = '8'; ist = ":P8I"; vorhanden = ":P8V"; Refstart = ":P8R"; Refstartbroad = "*R"; Refstate = ":P8S"; Position = ":P8P";}
  if (pin2 == true && pin3 == true && pin4 == true && pin5 == true) 
     {number = '9'; ist = ":P9I"; vorhanden = ":P9V"; Refstart = ":P9R"; Refstartbroad = "*R"; Refstate = ":P9S"; Position = ":P9P";}

}

char firstbytePos; //Erstes byte für Position
char secondbytePos; //Zweites byte für Position

char firstbyteIST; //Erstes byte für Encoder IST - Wert
char secondbyteIST; //Zweites byte für Encoder IST - Wert

long i = 0; //Zähler für die Wiederholung des Paket sendens
long oldPosition  = 0; //Hilfsvariable für Encoder
int steps = 0; //steps des Encoders

bool Ref; //Reffahrt initiieren


void loop() {

/*********Encoder Asulesen und als 2 byte CHAR vorbereiten************/
long newPosition = myEnc.read()/4;
sensorValue = analogRead(0);
/*
/*******IST-Wert begrenzen (0 bis 40)*********************************/ 
/*if (newPosition>oldPosition)
{steps++; }
if (newPosition<oldPosition)
{steps--; }
if(steps>=40)
{steps=40;}
if(steps<=0)
{steps=0;}    
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    runing = 'R';
    }
*/    
/********CHAR vorbereiten IST-WERT************************************/
/*if (steps< 10){ 
firstbyteIST = '0';
secondbyteIST = char(steps+48);
}
if (steps >= 10 && steps <20 ){ 
firstbyteIST = '1';
secondbyteIST = char(steps+38);
}
if (steps >= 20 && steps <30 ){ 
firstbyteIST = '2';
secondbyteIST = char(steps+28);
}
if (steps >= 30 && steps <40 ){ 
firstbyteIST = '3';
secondbyteIST = char(steps+18);
}
if (steps >= 40){ 
firstbyteIST = '4';
secondbyteIST = '0';
}
*/
/********Serielles Paket auswerten (GesamtString/StringHeader)***************************/
     if(Serial.available() > 0) 
     {
     strIN = Serial.readStringUntil('\n'); //gesamter Input String
     StrINHeader = strIN.substring(0,4);   //nur String Header ausweren
     }
/**********Serielles Paket für vorhanden senden (einfach nur antworten)*******************/
    if (StrINHeader == vorhanden)
        {   
        Serial.write(';'); //Kennung von Poti
        Serial.write('P'); //Komando
        Serial.write(number); //Pot number
        Serial.write('V'); //Befehl
        Serial.write('\n'); //Endzeichen
        StrINHeader = "NULL";
        i++;
        }
/******************************Serielles Paket für IST-WERT senden************************/
    if (StrINHeader == ist)
        {      
        Serial.write(';'); //Kennung von Poti
        Serial.write('P'); //Kommando  
        Serial.write(number); //Pot number
        Serial.write('I'); //Befehl
        Serial.write(firstbyteIST); //erstes Datenbyte
        Serial.write(secondbyteIST); //zweites Datenbyte
        //Serial.write(runing); //aktuell am fahren?
        Serial.write(runing);
        Serial.write('\n'); //Endzeichen
        StrINHeader = "NULL";
        runing = 'S';
        i++;
        }
/*********Serielles Paket für Position senden (spiegeln & SollPosition --> INT)******/      
        if (StrINHeader == Position)
        {    
        /*INT für SollPosition erzeugen*/  
        firstbytePos  = strIN.substring(4,5).toInt();
        secondbytePos = strIN.substring(5,6).toInt();
        if (firstbytePos == 48) {SollPosition = secondbytePos - 48 + 00;} //firstbyteIST = 0
        if (firstbytePos == 49) {SollPosition = secondbytePos - 48 + 10;} //firstbyteIST = 1
        if (firstbytePos == 50) {SollPosition = secondbytePos - 48 + 20;} //firstbyteIST = 2
        if (firstbytePos == 51) {SollPosition = secondbytePos - 48 + 30;} //firstbyteIST = 3
        /*Antwort an Master*/
        Serial.write(';'); //Kennung von Poti
        Serial.write('P'); //Kommando
        Serial.write(number); //Pot number
        Serial.write('P'); //Befehl
        Serial.write(firstbytePos); //erstes Datenbyte
        Serial.write(secondbytePos); //zweites Datenbyte
        Serial.write('*');
        Serial.write('\n'); //Endzeichen
        StrINHeader = "NULL";
        i++;
        }
/******************Refstart empfangen --> Resffahrt initiieren************************/
        if (StrINHeader == Refstart || StrINHeader == Refstartbroad)
        {
          Ref = true;
        }
        if (OK)  {digitalWrite(LED_BUILTIN, blinker);}
        if (!OK) {digitalWrite(LED_BUILTIN, false);}
        if (i>100) {blinker = !blinker; i=0;}
       
}


