#include <Stepper.h>
#include <Encoder.h>

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
int sensorValuestart;
int tell = 0;
bool first = true;
bool done = false;
int count = 1;
int Zielwert = 50;
int SollPosition;
char number; //POT number
bool ok = false;
int toggle = 0;
int wait = 0;
bool refpositionL = false;
bool refpositionR = false;
int pin6 = true;
const int stepsPerRevolution = 200; 
bool once = false;

Stepper myStepper(stepsPerRevolution, 9, 10);
Encoder myEnc(2, 3);

const int numReadings = 150;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int inputPin = A0;



void setup() {

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {readings[thisReading] = 0; analogReference(EXTERNAL);}

  myStepper.setSpeed(200);
  
  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  int pin4 = digitalRead(4);
  int pin5 = digitalRead(5);
  int pin6 = digitalRead(6);


  if (pin4 == true && pin5 == true && pin6 == true)  
     {number = '0'; ist = ":P0I"; vorhanden = ":P0V"; Refstart = ":P0R"; Refstartbroad = "*R"; Refstate = ":P0S"; Position = ":P0P";}
  if (pin4 == false && pin5 == true && pin6 == true) 
     {number = '1'; ist = ":P1I"; vorhanden = ":P1V"; Refstart = ":P1R"; Refstartbroad = "*R"; Refstate = ":P1S"; Position = ":P1P";}
  if (pin4 == true && pin5 == false && pin6 == true) 
     {number = '2'; ist = ":P2I"; vorhanden = ":P2V"; Refstart = ":P2R"; Refstartbroad = "*R"; Refstate = ":P2S"; Position = ":P2P";}  
  if (pin4 == true && pin5 == true && pin6 == false) 
     {number = '3'; ist = ":P3I"; vorhanden = ":P3V"; Refstart = ":P3R"; Refstartbroad = "*R"; Refstate = ":P3S"; Position = ":P3P";}
  if (pin4 == true && pin5 == true && pin6 == true) 
     {number = '4'; ist = ":P4I"; vorhanden = ":P4V"; Refstart = ":P4R"; Refstartbroad = "*R"; Refstate = ":P4S"; Position = ":P4P";}
  if (pin4 == false && pin5 == false && pin6 == false) 
     {number = '5'; ist = ":P5I"; vorhanden = ":P5V"; Refstart = ":P5R"; Refstartbroad = "*R"; Refstate = ":P5S"; Position = ":P5P";}
  if (pin4 == false && pin5 == false && pin6 == false) 
     {number = '6'; ist = ":P6I"; vorhanden = ":P6V"; Refstart = ":P6R"; Refstartbroad = "*R"; Refstate = ":P6S"; Position = ":P6P";}
  if (pin4 == false && pin5 == false && pin6 == false) 
     {number = '7'; ist = ":P7I"; vorhanden = ":P7V"; Refstart = ":P7R"; Refstartbroad = "*R"; Refstate = ":P7S"; Position = ":P7P";}
  if (pin4 == false && pin5 == false && pin6 == false) 
     {number = '8'; ist = ":P8I"; vorhanden = ":P8V"; Refstart = ":P8R"; Refstartbroad = "*R"; Refstate = ":P8S"; Position = ":P8P";}
  if (pin4 == false && pin5 == false && pin6 == false) 
     {number = '9'; ist = ":P9I"; vorhanden = ":P9V"; Refstart = ":P9R"; Refstartbroad = "*R"; Refstate = ":P9S"; Position = ":P9P";}
}

/***********************************END void Setup ()**************************************************************************/
long oldPosition  = -999;

char firstbytePos; //Erstes byte für Position
char secondbytePos; //Zweites byte für Position
char thirdbytePos;

char firstbyteIST; //Erstes byte für Encoder IST - Wert
char secondbyteIST; //Zweites byte für Encoder IST - Wert
char thirdbyteIST;

long i = 0; //Zähler für die Wiederholung des Paket sendens

int steps = 0; //steps des Encoders

bool Ref; //Reffahrt initiieren



void loop() {

/*********Routine um Motor in Refposition zu bringen************/
/*
if (refpositionL == false)
  {
      pin6 = digitalRead(6);   
      if(pin6 == true) //nicht auf Linksanschlag
      {
      digitalWrite (7, LOW);
      digitalWrite (8, LOW);
      myStepper.step(-1);
      }  
      if(pin6 == false)//auf Linksanschlag
      {
      digitalWrite (7, HIGH);
      digitalWrite (8, HIGH);
      refpositionL = true;
      }
   }
*/
  long newPosition = myEnc.read()/17;
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    sensorValue = newPosition;
    if (sensorValue > 127)
    {sensorValue = 127;}    
  }
  
  if(once == false){
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);
  myStepper.step(89);
  once = true;
  }
  if(once == true){
  digitalWrite (7, HIGH);
  digitalWrite (8, HIGH);
  }



/*******************************************CHAR für IST Wert aufbereiten********************************/

      if (sensorValue<100)
      {
        thirdbyteIST = '0';
        if (sensorValue< 10){firstbyteIST = '0'; secondbyteIST = char(sensorValue+48);}
        if (sensorValue >= 10 && sensorValue <20 ){firstbyteIST = '1'; secondbyteIST = char(sensorValue+38);}
        if (sensorValue >= 20 && sensorValue <30 ){firstbyteIST = '2'; secondbyteIST = char(sensorValue+28);}
        if (sensorValue >= 30 && sensorValue <40 ){firstbyteIST = '3'; secondbyteIST = char(sensorValue+18);}
        if (sensorValue >= 40 && sensorValue <50 ){firstbyteIST = '4'; secondbyteIST = char(sensorValue+8);}
        if (sensorValue >= 50 && sensorValue <60 ){firstbyteIST = '5'; secondbyteIST = char(sensorValue-2);}
        if (sensorValue >= 60 && sensorValue <70 ){firstbyteIST = '6'; secondbyteIST = char(sensorValue-12);}
        if (sensorValue >= 70 && sensorValue <80 ){firstbyteIST = '7'; secondbyteIST = char(sensorValue-22);}
        if (sensorValue >= 80 && sensorValue <90 ){firstbyteIST = '8'; secondbyteIST = char(sensorValue-32);}
        if (sensorValue >= 90 && sensorValue <100 ){firstbyteIST = '9';secondbyteIST = char(sensorValue-42);}
      }
       if (sensorValue >= 100)
       {
        thirdbyteIST = '1';
        if (sensorValue< 110){firstbyteIST = '0'; secondbyteIST = char(sensorValue-52);}
        if (sensorValue >= 110 && sensorValue <120 ){firstbyteIST = '1'; secondbyteIST = char(sensorValue-62);}
        if (sensorValue >= 120 && sensorValue <130 ){firstbyteIST = '2'; secondbyteIST = char(sensorValue-72);}
        if (sensorValue >= 130 && sensorValue <140 ){firstbyteIST = '3'; secondbyteIST = char(sensorValue-82);}
        if (sensorValue >= 140 && sensorValue <150 ){firstbyteIST = '4'; secondbyteIST = char(sensorValue-92);}
        if (sensorValue >= 150 && sensorValue <160 ){firstbyteIST = '5'; secondbyteIST = char(sensorValue-102);}
        if (sensorValue >= 160 && sensorValue <170 ){firstbyteIST = '6'; secondbyteIST = char(sensorValue-112);}
        if (sensorValue >= 170 && sensorValue <180 ){firstbyteIST = '7'; secondbyteIST = char(sensorValue-122);}
        if (sensorValue >= 180 && sensorValue <190 ){firstbyteIST = '8'; secondbyteIST = char(sensorValue-132);}
        if (sensorValue >= 190){firstbyteIST = '9'; secondbyteIST = '0';}
       }
    

/********Serielles Paket auswerten (GesamtString/StringHeader)***************************/
    if(Serial.available() > 0) 
        {
        strIN = Serial.readStringUntil('\n'); //gesamter Input String
        StrINHeader = strIN.substring(0,4);   //nur String Header auswerten
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
        Serial.write(thirdbyteIST);
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
        thirdbytePos  = strIN.substring(6,7).toInt();
        
        if (thirdbytePos == 0) //hunderterStelle = 0
        {
         if (firstbytePos == 0) {SollPosition = secondbytePos + 00;} //firstbytePos = 0
         if (firstbytePos == 1) {SollPosition = secondbytePos + 10;} //firstbytePos = 1
         if (firstbytePos == 2) {SollPosition = secondbytePos + 20;} //firstbytePos = 2
         if (firstbytePos == 3) {SollPosition = secondbytePos + 30;} //firstbytePos = 3
         if (firstbytePos == 4) {SollPosition = secondbytePos + 40;} //firstbytePos = 4
         if (firstbytePos == 5) {SollPosition = secondbytePos + 50;} //firstbytePos = 5
         if (firstbytePos == 6) {SollPosition = secondbytePos + 60;} //firstbytePos = 6
         if (firstbytePos == 7) {SollPosition = secondbytePos + 70;} //firstbytePos = 7
         if (firstbytePos == 8) {SollPosition = secondbytePos + 80;} //firstbytePos = 8
         if (firstbytePos == 9) {SollPosition = secondbytePos + 90;} //firstbytePos = 9
        }

        if (thirdbytePos == 1) //hunderterStelle = 1
        {
         if (firstbytePos == 0) {SollPosition = secondbytePos + 100;} //firstbytePos = 0
         if (firstbytePos == 1) {SollPosition = secondbytePos + 110;} //firstbytePos = 1
         if (firstbytePos == 2) {SollPosition = secondbytePos + 120;} //firstbytePos = 2
         if (firstbytePos == 3) {SollPosition = secondbytePos + 130;} //firstbytePos = 3
         if (firstbytePos == 4) {SollPosition = secondbytePos + 140;} //firstbytePos = 4
         if (firstbytePos == 5) {SollPosition = secondbytePos + 150;} //firstbytePos = 5
         if (firstbytePos == 6) {SollPosition = secondbytePos + 160;} //firstbytePos = 6
         if (firstbytePos == 7) {SollPosition = secondbytePos + 170;} //firstbytePos = 7
         if (firstbytePos == 8) {SollPosition = secondbytePos + 180;} //firstbytePos = 8
         if (firstbytePos == 9) {SollPosition = secondbytePos + 190;} //firstbytePos = 9
        }
     
        /*Antwort an Master*/
        //Serial.write(';'); //Kennung von Poti
        //Serial.write('P'); //Kommando
        //Serial.write(number); //Pot number
        //Serial.write('P'); //Befehl
        //Serial.write(firstbytePos); //erstes Datenbyte
        //Serial.write(secondbytePos); //zweites Datenbyte
        //Serial.write(thirdbytePos); //zweites Datenbyte
        //Serial.write('\n'); //Endzeichen
        StrINHeader = "NULL";
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite (7, LOW);
        digitalWrite (8, LOW);
        delay(200);
        myStepper.step((1.4*(SollPosition - sensorValue))); //von SensorValue (2,36*(IST - Position)) x Schritte verfahren
       
        digitalWrite (7, HIGH);
        digitalWrite (8, HIGH);

        
        digitalWrite(LED_BUILTIN, false);
        
        }
/******************Refstart empfangen --> Resffahrt initiieren************************/
        if (StrINHeader == Refstart || StrINHeader == Refstartbroad)
        {
          Ref = true;
        }
/*************************************************************************************/        
          digitalWrite(LED_BUILTIN, false);
          //Serial.write(sensorValue);
}


