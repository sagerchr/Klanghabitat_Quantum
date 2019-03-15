#include <Encoder.h>

#include <Stepper.h>
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
int sensorValuestart;
int sensorValue1;
int sensorValue2;
int sensorValue3;
int sensorValue4;
int sensorValue5;
int sensorValue6;
int sensorValue7;
int sensorValue8;
int sensorValue9;
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


const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 9, 10);




const int numReadings = 150;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int inputPin = A0;



void setup() {


    for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
    analogReference(EXTERNAL);     
    //delay(1000);
  }
  
  myStepper.setSpeed(200);
  
  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

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
char thirdbyteIST;

long i = 0; //Zähler für die Wiederholung des Paket sendens
long oldPosition  = 0; //Hilfsvariable für Encoder
int steps = 0; //steps des Encoders

bool Ref; //Reffahrt initiieren


void loop() {

/*********Encoder Asulesen und als 2 byte CHAR vorbereiten************/
//long newPosition = myEnc.read()/4;
//sensorValue = analogRead(0);
/*
     switch (count) 
     {
     case 1: {sensorValue1 = analogRead(0); count = 2;} break;
     case 2: {sensorValue2 = analogRead(0); count = 3;} break;
     case 3: {sensorValue3 = analogRead(0); count = 4;} break;
     case 4: {sensorValue4 = analogRead(0); count = 5;} break;
     case 5: {sensorValue5 = analogRead(0); count = 6;} break;
     case 6: {sensorValue6 = analogRead(0); count = 7;} break;
     case 7: {sensorValue7 = analogRead(0); count = 8;} break;
     case 8: {sensorValue8 = analogRead(0); count = 9;} break;
     case 9: {sensorValue9 = analogRead(0); count = 1;} break;
     }
*/
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(0);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
       if (tell > 10)
       {
        sensorValue = average - sensorValuestart ;     
        done = true;
       }
    
    if (tell <= 10)
      {
      sensorValuestart = average;
      tell = tell +1; 
      }


    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;


//firstbyteIST = sensorValue;
//secondbyteIST = char(steps+18); 

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

if (readIndex == 0)
{


//sensorValue  = ((sensorValue1 + sensorValue2 + sensorValue3 + sensorValue4 + sensorValue5 + sensorValue6 + sensorValue7 + sensorValue8 + sensorValue9)/9)- sensorValuestart;


/*
          if (sensorValue == 70)
          {
          digitalWrite (7,HIGH);
          digitalWrite (8,HIGH);
          }
          
if (sensorValue != 70 && readIndex == 0 )
          {

          if (sensorValue >= 70)
          {
          digitalWrite (7, LOW);
          digitalWrite (8, LOW);
          myStepper.step(-1);
          }

            
          if (sensorValue < 70)
          {
          digitalWrite (7, LOW);
          digitalWrite (8, LOW);
          if (70 - sensorValue <= 5){
          myStepper.step(1);
          }
          if (70 - sensorValue >= 20){
          myStepper.step(40);
          }
          if (70 - sensorValue >= 10){
          myStepper.step(20);
          }
          }

    
          if (sensorValue == 70)
          {
          digitalWrite (7,HIGH);
          digitalWrite (8,HIGH);
          }
          }
  */        


if (sensorValue<100)
{
thirdbyteIST = '0';

if (sensorValue< 10){ 
firstbyteIST = '0';
secondbyteIST = char(sensorValue+48);
}
if (sensorValue >= 10 && sensorValue <20 ){ 
firstbyteIST = '1';
secondbyteIST = char(sensorValue+38);
}
if (sensorValue >= 20 && sensorValue <30 ){ 
firstbyteIST = '2';
secondbyteIST = char(sensorValue+28);
}
if (sensorValue >= 30 && sensorValue <40 ){ 
firstbyteIST = '3';
secondbyteIST = char(sensorValue+18);
}
if (sensorValue >= 40 && sensorValue <50 ){ 
firstbyteIST = '4';
secondbyteIST = char(sensorValue+8);
}
if (sensorValue >= 50 && sensorValue <60 ){ 
firstbyteIST = '5';
secondbyteIST = char(sensorValue-2);
}
if (sensorValue >= 60 && sensorValue <70 ){ 
firstbyteIST = '6';
secondbyteIST = char(sensorValue-12);
}
if (sensorValue >= 70 && sensorValue <80 ){ 
firstbyteIST = '7';
secondbyteIST = char(sensorValue-22);
}
if (sensorValue >= 80 && sensorValue <90 ){ 
firstbyteIST = '8';
secondbyteIST = char(sensorValue-32);
}
if (sensorValue >= 90 && sensorValue <100 ){ 
firstbyteIST = '9';
secondbyteIST = char(sensorValue-42);
}
}


if (sensorValue >= 100)
{
thirdbyteIST = '1';

if (sensorValue< 110){ 
firstbyteIST = '0';
secondbyteIST = char(sensorValue-52);
}
if (sensorValue >= 110 && sensorValue <120 ){ 
firstbyteIST = '1';
secondbyteIST = char(sensorValue-62);
}
if (sensorValue >= 120 && sensorValue <130 ){ 
firstbyteIST = '2';
secondbyteIST = char(sensorValue-72);
}
if (sensorValue >= 130 && sensorValue <140 ){ 
firstbyteIST = '3';
secondbyteIST = char(sensorValue-82);
}
if (sensorValue >= 140 && sensorValue <150 ){ 
firstbyteIST = '4';
secondbyteIST = char(sensorValue-92);
}
if (sensorValue >= 150 && sensorValue <160 ){ 
firstbyteIST = '5';
secondbyteIST = char(sensorValue-102);
}
if (sensorValue >= 160 && sensorValue <170 ){ 
firstbyteIST = '6';
secondbyteIST = char(sensorValue-112);
}
if (sensorValue >= 170 && sensorValue <180 ){ 
firstbyteIST = '7';
secondbyteIST = char(sensorValue-122);
}
if (sensorValue >= 180 && sensorValue <190 ){ 
firstbyteIST = '8';
secondbyteIST = char(sensorValue-132);
}
if (sensorValue >= 190){ 
firstbyteIST = '9';
secondbyteIST = '0';}
}

}



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
        if (i>1000) {blinker = !blinker; i=0;}
        
          



          
          if (sensorValue == Zielwert || sensorValue == Zielwert + 1 || sensorValue == Zielwert - 1)
          {
          digitalWrite (7,HIGH);
          digitalWrite (8,HIGH);
          ok = true;
          wait++;
              
              if (wait>10000)
              {
               wait = 0;
               ok = false; 
                switch (toggle) 
                {
                case 0: {Zielwert = 127;  toggle = 1;} break;
                case 1: {Zielwert = 12;  toggle = 2;} break;
                case 2: {Zielwert = 100;  toggle = 3;} break;
                case 3: {Zielwert = 80;  toggle = 4;} break;
                case 4: {Zielwert = 20;  toggle = 5;} break;
                case 5: {Zielwert = 2;  toggle = 0;} break;
               } 
              }            
          }

          
          
          if (sensorValue != Zielwert && done == true && readIndex == 0 && ok == false)
          {
          digitalWrite (7, LOW);
          digitalWrite (8, LOW);

          if (sensorValue - Zielwert >= 10){
          myStepper.step(Zielwert - sensorValue);
          }
          if (sensorValue - Zielwert >= 2 && sensorValue - Zielwert < 10){
          myStepper.step(-3);
          }
          if (sensorValue - Zielwert < 2){
          myStepper.step(-1);
          }
            
          if (sensorValue < Zielwert && done == true && readIndex == 0 && ok == false)
          {
          digitalWrite (7, LOW);
          digitalWrite (8, LOW);

          if (Zielwert - sensorValue >= 10){
          
          myStepper.step(Zielwert - sensorValue);
          }
          if (Zielwert - sensorValue >= 2 && Zielwert - sensorValue <10){
          myStepper.step(3);
          }
          if (Zielwert - sensorValue < 2){
          myStepper.step(1);
          }
          }

    
          if (sensorValue == Zielwert || sensorValue == Zielwert + 1 || sensorValue == Zielwert - 1 )
          {
          digitalWrite (7,HIGH);
          digitalWrite (8,HIGH);
          ok = true;
          }
          }
          
       
}


