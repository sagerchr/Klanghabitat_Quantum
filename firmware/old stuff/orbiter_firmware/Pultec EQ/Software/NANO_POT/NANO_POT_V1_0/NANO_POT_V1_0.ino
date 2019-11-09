#include <Stepper.h>
const int stepsPerRevolution = 200; 

Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13);


char runing;
char number; 

String strIN;
String StrINHeader;
String ist;
String vorhanden;
String Refstart;
String Refstartbroad;
String Refstate;
String Position;




void setup() {


  Serial.begin(115200);

  myStepper.setSpeed(50);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  /*
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(4, INPUT_PULLUP); //Adresse
  pinMode(5, INPUT_PULLUP); //Adresse
  pinMode(6, INPUT_PULLUP); //Adresse
  
  int pin4 = digitalRead(4); //Adresse
  int pin5 = digitalRead(5); //Adresse
  int pin6 = digitalRead(6); //Adresse
  */
  /*
  if (pin4 == true && pin5 == true && pin6 == true)  
     {number = '0'; ist = ":P0I"; vorhanden = ":P0V"; Refstart = ":P0R"; Refstartbroad = "*R"; Refstate = ":P0S"; Position = ":P0P";}
  if (pin4 == false && pin5 == true && pin6 == true) 
    {number = '1'; ist = ":P1I"; vorhanden = ":P1V"; Refstart = ":P1R"; Refstartbroad = "*R"; Refstate = ":P1S"; Position = ":P1P";}
  if (pin4 == false && pin5 == false && pin6 == false) 
    {number = '2'; ist = ":P2I"; vorhanden = ":P2V"; Refstart = ":P2R"; Refstartbroad = "*R"; Refstate = ":P2S"; Position = ":P2P";}  
  if (pin4 == false && pin5 == false && pin6 == false) 
     {number = '3'; ist = ":P3I"; vorhanden = ":P3V"; Refstart = ":P3R"; Refstartbroad = "*R"; Refstate = ":P3S"; Position = ":P3P";}
  if (pin4 == false && pin5 == false && pin6 == false) 
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
*/
number = '0'; ist = ":P0I"; vorhanden = ":P0V"; Refstart = ":P0R"; Refstartbroad = "*R"; Refstate = ":P0S"; Position = ":P0P";
  
  
}

/***********************************END void Setup ()**************************************************************************/


char firstbytePos; //Erstes byte für Position
char secondbytePos; //Zweites byte für Position
char thirdbytePos;

char firstbyteIST; //Erstes byte für Encoder IST - Wert
char secondbyteIST; //Zweites byte für Encoder IST - Wert
char thirdbyteIST;

long i = 0; //Zähler für die Wiederholung des Paket sendens
bool Ref; //Reffahrt initiieren





  int task = 2;
  int t = 0;
  int k = 0;
  bool waiting = true;
  
  int Pos = 0;
  int IST = 0;
  int SOLL = 64;
  int Refleft = 0;
  bool p1 =false;
  bool p2 =false;
  bool p3 =false;
  bool p4 =false;
  bool p5 =false;
  bool p6 =false;
  bool p7 =false;
  bool p8 =false;

  bool mess = true;

  bool block = false;
  int diff = 0;
 
   
void loop() {


/*********Routine um Motor in Refposition zu bringen************/

  
  
  //delayMicroseconds(10); //generelles Timing



/*******************************************CHAR für IST Wert aufbereiten********************************/

      //if (sensorValue<100)
      if (IST<100)
      {
        thirdbyteIST = '0';
        if (IST< 10){firstbyteIST = '0'; secondbyteIST = char(IST+48);}
        if (IST >= 10 && IST <20 ){firstbyteIST = '1'; secondbyteIST = char(IST+38);}
        if (IST >= 20 && IST <30 ){firstbyteIST = '2'; secondbyteIST = char(IST+28);}
        if (IST >= 30 && IST <40 ){firstbyteIST = '3'; secondbyteIST = char(IST+18);}
        if (IST >= 40 && IST <50 ){firstbyteIST = '4'; secondbyteIST = char(IST+8);}
        if (IST >= 50 && IST <60 ){firstbyteIST = '5'; secondbyteIST = char(IST-2);}
        if (IST >= 60 && IST <70 ){firstbyteIST = '6'; secondbyteIST = char(IST-12);}
        if (IST >= 70 && IST <80 ){firstbyteIST = '7'; secondbyteIST = char(IST-22);}
        if (IST >= 80 && IST <90 ){firstbyteIST = '8'; secondbyteIST = char(IST-32);}
        if (IST >= 90 && IST <100 ){firstbyteIST = '9';secondbyteIST = char(IST-42);}
      }
       //if (sensorValue >= 100)
       if (IST >= 100)
       {
        thirdbyteIST = '1';
        if (IST< 110){firstbyteIST = '0'; secondbyteIST = char(IST-52);}
        if (IST >= 110 && IST <120 ){firstbyteIST = '1'; secondbyteIST = char(IST-62);}
        if (IST >= 120 && IST <130 ){firstbyteIST = '2'; secondbyteIST = char(IST-72);}
        if (IST >= 130 && IST <140 ){firstbyteIST = '3'; secondbyteIST = char(IST-82);}
        if (IST >= 140 && IST <150 ){firstbyteIST = '4'; secondbyteIST = char(IST-92);}
        if (IST >= 150 && IST <160 ){firstbyteIST = '5'; secondbyteIST = char(IST-102);}
        if (IST >= 160 && IST <170 ){firstbyteIST = '6'; secondbyteIST = char(IST-112);}
        if (IST >= 170 && IST <180 ){firstbyteIST = '7'; secondbyteIST = char(IST-122);}
        if (IST >= 180 && IST <190 ){firstbyteIST = '8'; secondbyteIST = char(IST-132);}
        if (IST >= 190){firstbyteIST = '9'; secondbyteIST = '0';}
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

/*********Serielles Paket für Position senden (spiegeln & SollPosition --> INT)******/      
        if (StrINHeader == Position)
        //if (StrINHeader == Position && task == 3)
        {    
        /*INT für SollPosition erzeugen*/  
        firstbytePos  = strIN.substring(4,5).toInt();
        secondbytePos = strIN.substring(5,6).toInt();
        thirdbytePos  = strIN.substring(6,7).toInt();
        
        if (thirdbytePos == 0) //hunderterStelle = 0
        {
         if (firstbytePos == 0) {SOLL = secondbytePos + 00;} //firstbytePos = 0
         if (firstbytePos == 1) {SOLL = secondbytePos + 10;} //firstbytePos = 1
         if (firstbytePos == 2) {SOLL = secondbytePos + 20;} //firstbytePos = 2
         if (firstbytePos == 3) {SOLL = secondbytePos + 30;} //firstbytePos = 3
         if (firstbytePos == 4) {SOLL = secondbytePos + 40;} //firstbytePos = 4
         if (firstbytePos == 5) {SOLL = secondbytePos + 50;} //firstbytePos = 5
         if (firstbytePos == 6) {SOLL = secondbytePos + 60;} //firstbytePos = 6
         if (firstbytePos == 7) {SOLL = secondbytePos + 70;} //firstbytePos = 7
         if (firstbytePos == 8) {SOLL = secondbytePos + 80;} //firstbytePos = 8
         if (firstbytePos == 9) {SOLL = secondbytePos + 90;} //firstbytePos = 9
        }
        
        if (thirdbytePos == 1) //hunderterStelle = 1
        {
         if (firstbytePos == 0) {SOLL = secondbytePos + 100;} //firstbytePos = 0
         if (firstbytePos == 1) {SOLL = secondbytePos + 110;} //firstbytePos = 1
         if (firstbytePos == 2) {SOLL = secondbytePos + 120;} //firstbytePos = 2
         if (firstbytePos == 3) {SOLL = secondbytePos + 130;} //firstbytePos = 3
         if (firstbytePos == 4) {SOLL = secondbytePos + 140;} //firstbytePos = 4
         if (firstbytePos == 5) {SOLL = secondbytePos + 150;} //firstbytePos = 5
         if (firstbytePos == 6) {SOLL = secondbytePos + 160;} //firstbytePos = 6
         if (firstbytePos == 7) {SOLL = secondbytePos + 170;} //firstbytePos = 7
         if (firstbytePos == 8) {SOLL = secondbytePos + 180;} //firstbytePos = 8
         if (firstbytePos == 9) {SOLL = secondbytePos + 190;} //firstbytePos = 9
        }
        
        StrINHeader = "NULL";
        task = 2; //Regelung einleiten
        //if (SOLL == 0) {SOLL = 10;}
        }
/********************************************IST Position auslesen****************************************/   
 
        
/******************************Serielles Paket für IST-WERT senden************************/
    if (StrINHeader == ist && waiting == true)
        {  
        //if(sensorValue >= SollPosition +3 || sensorValue <= SollPosition -3)
        //{        
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
        // }
        } 

        
/******************Refstart empfangen --> Resffahrt initiieren************************/
        if (StrINHeader == Refstart || StrINHeader == Refstartbroad)
        {
          Ref = true;
        }
/*************************************************************************************/        
     p1 = digitalRead(2); p2 = digitalRead(3); p3 = digitalRead(4); p4 = digitalRead(5); p5 = digitalRead(6); p6 = digitalRead(7); p7 = digitalRead(8); p8 = digitalRead(9);    
     if(mess) //Position messen ...
      {
  if(!p8 && p7 && p6 && p5 && p4 && p3 && p2 && p1) {Pos = 0;}
  if(!p8 && !p7 && p6 && p5 && p4 && p3 && p2 && p1) {Pos = 1;}
  if(!p8 && !p7 && p6 && p5 && p4 && p3 && p2 && !p1) {Pos = 2;}   
  if(!p8 && !p7 && p6 && p5 && p4 && !p3 && p2 && !p1) {Pos = 3;}
  if(!p8 && !p7 && p6 && p5 && p4 && !p3 && !p2 && !p1) {Pos = 4;}
  if(p8 && !p7 && p6 && p5 && p4 && !p3 && !p2 && !p1) {Pos = 5;}
  if(p8 && !p7 && !p6 && p5 && p4 && !p3 && !p2 && !p1) {Pos = 6;}
  if(!p8 && !p7 && !p6 && p5 && p4 && !p3 && !p2 && !p1) {Pos = 7;}
  if(!p8 && !p7 && !p6 && !p5 && p4 && !p3 && !p2 && !p1) {Pos = 8;}
  if(!p8 && p7 && !p6 && !p5 && p4 && !p3 && !p2 && !p1) {Pos = 9;}
  if(!p8 && p7 && !p6 && !p5 && p4 && !p3 && !p2 && p1) {Pos = 10;}
  if(!p8 && p7 && !p6 && !p5 && p4 && p3 && !p2 && p1) {Pos = 11;}
  if(!p8 && p7 && !p6 && !p5 && p4 && p3 && p2 && p1) {Pos = 12;}
  if(!p8 && !p7 && !p6 && !p5 && p4 && p3 && p2 && p1) {Pos = 13;}
  if(!p8 && !p7 && p6 && !p5 && p4 && p3 && p2 && p1) {Pos = 14;}  
  if(p8 && !p7 && p6 && !p5 && p4 && p3 && p2 && p1) {Pos = 15;}    
  if(p8 && !p7 && p6 && p5 && p4 && p3 && p2 && p1) {Pos = 16;}    
  if(p8 && !p7 && !p6 && p5 && p4 && p3 && p2 && p1) {Pos = 17;}   
  if(!p8 && !p7 && !p6 && p5 && p4 && p3 && p2 && p1) {Pos = 18;}   
  if(!p8 && !p7 && !p6 && p5 && p4 && p3 && !p2 && p1) {Pos = 19;}  
  if(!p8 && !p7 && !p6 && p5 && p4 && p3 && !p2 && !p1) {Pos = 20;} 
  if(!p8 && p7 && !p6 && p5 && p4 && p3 && !p2 && !p1) {Pos = 21;} 
  if(!p8 && p7 && !p6 && !p5 && p4 && p3 && !p2 && !p1) {Pos = 22;}   
  if(!p8 && !p7 && !p6 && !p5 && p4 && p3 && !p2 && !p1) {Pos = 23;} 
  if(!p8 && !p7 && !p6 && !p5 && !p4 && p3 && !p2 && !p1) {Pos = 24;} 
  if(!p8 && !p7 && p6 && !p5 && !p4 && p3 && !p2 && !p1) {Pos = 25;} 
  if(p8 && !p7 && p6 && !p5 && !p4 && p3 && !p2 && !p1) {Pos = 26;} 
  if(p8 && !p7 && p6 && !p5 && !p4 && p3 && p2 && !p1) {Pos = 27;} 
  if(p8 && !p7 && p6 && !p5 && !p4 && p3 && p2 && p1) {Pos = 28;}   
  if(p8 && !p7 && !p6 && !p5 && !p4 && p3 && p2 && p1) {Pos = 29;}  
  if(p8 && !p7 && !p6 && p5 && !p4 && p3 && p2 && p1) {Pos = 30;} 
  if(p8 && p7 && !p6 && p5 && !p4 && p3 && p2 && p1) {Pos = 31;} 
  if(p8 && p7 && !p6 && p5 && p4 && p3 && p2 && p1) {Pos = 32;} 
  if(p8 && p7 && !p6 && !p5 && p4 && p3 && p2 && p1) {Pos = 33;} 
  if(p8 && !p7 && !p6 && !p5 && p4 && p3 && p2 && p1) {Pos = 34;} 
  if(p8 && !p7 && !p6 && !p5 && p4 && p3 && p2 && !p1) {Pos = 35;}
  if(!p8 && !p7 && !p6 && !p5 && p4 && p3 && p2 && !p1) {Pos = 36;}
  if(!p8 && !p7 && p6 && !p5 && p4 && p3 && p2 && !p1) {Pos = 37;}
  if(!p8 && !p7 && p6 && !p5 && !p4 && p3 && p2 && !p1) {Pos = 38;}
  if(!p8 && !p7 && !p6 && !p5 && !p4 && p3 && p2 && !p1) {Pos = 39;}  
  if(!p8 && !p7 && !p6 && !p5 && !p4 && !p3 && p2 && !p1) {Pos = 40;}  
  if(!p8 && !p7 && !p6 && p5 && !p4 && !p3 && p2 && !p1) {Pos = 41;}
  if(!p8 && p7 && !p6 && p5 && !p4 && !p3 && p2 && !p1) {Pos = 42;}
  if(!p8 && p7 && !p6 && p5 && !p4 && !p3 && p2 && !p1) {Pos = 43;}
  if(p8 && p7 && !p6 && p5 && !p4 && !p3 && p2 && p1) {Pos = 44;}
  if(p8 && p7 && !p6 && !p5 && !p4 && !p3 && p2 && p1) {Pos = 45;}
  if(p8 && p7 && !p6 && !p5 && p4 && !p3 && p2 && p1) {Pos = 46;}
  if(p8 && p7 && p6 && !p5 && p4 && !p3 && p2 && p1) {Pos = 47;}
  if(p8 && p7 && p6 && !p5 && p4 && p3 && p2 && p1) {Pos = 48;}
  if(p8 && p7 && p6 && !p5 && !p4 && p3 && p2 && p1) {Pos = 49;}
  if(p8 && p7 && !p6 && !p5 && !p4 && p3 && p2 && p1) {Pos = 50;}
  if(!p8 && p7 && !p6 && !p5 && !p4 && p3 && p2 && p1) {Pos = 51;}
  if(!p8 && !p7 && !p6 && !p5 && !p4 && p3 && p2 && p1) {Pos = 52;}
  if(!p8 && !p7 && !p6 && p5 && !p4 && p3 && p2 && p1) {Pos = 53;}
  if(!p8 && !p7 && !p6 && p5 && !p4 && !p3 && p2 && p1) {Pos = 54;}
  if(!p8 && !p7 && !p6 && !p5 && !p4 && !p3 && p2 && p1) {Pos = 55;}
  if(!p8 && !p7 && !p6 && !p5 && !p4 && !p3 && !p2 && p1) {Pos = 56;}
  if(!p8 && !p7 && !p6 && !p5 && p4 && !p3 && !p2 && p1) {Pos = 57;}
  if(!p8 && !p7 && p6 && !p5 && p4 && !p3 && !p2 && p1) {Pos = 58;}
  if(p8 && !p7 && p6 && !p5 && p4 && !p3 && !p2 && p1) {Pos = 59;}
  if(p8 && p7 && p6 && !p5 && p4 && !p3 && !p2 && p1) {Pos = 60;}
  if(p8 && p7 && p6 && !p5 && !p4 && !p3 && !p2 && p1) {Pos = 61;}
  if(p8 && p7 && p6 && !p5 && !p4 && p3 && !p2 && p1) {Pos = 62;}
  if(p8 && p7 && p6 && p5 && !p4 && p3 && !p2 && p1) {Pos = 63;}
  if(p8 && p7 && p6 && p5 && !p4 && p3 && p2 && p1) {Pos = 64;}     
  if(p8 && p7 && p6 && p5 && !p4 && !p3 && p2 && p1) {Pos = 65;}   
  if(p8 && p7 && p6 && !p5 && !p4 && !p3 && p2 && p1) {Pos = 66;}  
  if(p8 && !p7 && p6 && !p5 && !p4 && !p3 && p2 && p1) {Pos = 67;}
  if(p8 && !p7 && !p6 && !p5 && !p4 && !p3 && p2 && p1) {Pos = 68;}
  if(p8 && !p7 && !p6 && !p5 && p4 && !p3 && p2 && p1) {Pos = 69;}
  if(p8 && !p7 && !p6 && !p5 && p4 && !p3 && !p2 && p1) {Pos = 70;}
  if(p8 && !p7 && !p6 && !p5 && !p4 && !p3 && !p2 && p1) {Pos = 71;}
  if(p8 && !p7 && !p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Pos = 72;}
  if(p8 && !p7 && !p6 && !p5 && !p4 && p3 && !p2 && !p1) {Pos = 73;}
  if(p8 && !p7 && !p6 && p5 && !p4 && p3 && !p2 && !p1) {Pos = 74;}
  if(p8 && p7 && !p6 && p5 && !p4 && p3 && !p2 && !p1) {Pos = 75;}
  if(p8 && p7 && p6 && p5 && !p4 && p3 && !p2 && !p1) {Pos = 76;}
  if(p8 && p7 && p6 && p5 && !p4 && !p3 && !p2 && !p1) {Pos = 77;}
  if(p8 && p7 && p6 && p5 && !p4 && !p3 && p2 && !p1) {Pos = 78;}
  if(p8 && p7 && p6 && p5 && p4 && !p3 && p2 && !p1) {Pos = 79;}
  if(p8 && p7 && p6 && p5 && p4 && !p3 && p2 && p1) {Pos = 80;}
  if(p8 && p7 && p6 && p5 && p4 && !p3 && !p2 && p1) {Pos = 81;}
  if(p8 && p7 && p6 && p5 && !p4 && !p3 && !p2 && p1) {Pos = 82;}
  if(p8 && p7 && !p6 && p5 && !p4 && !p3 && !p2 && p1) {Pos = 83;}
  if(p8 && p7 && !p6 && !p5 && !p4 && !p3 && !p2 && p1) {Pos = 84;}
  if(p8 && p7 && !p6 && !p5 && !p4 && p3 && !p2 && p1) {Pos = 85;}
  if(p8 && p7 && !p6 && !p5 && !p4 && p3 && !p2 && !p1) {Pos = 86;}
  if(p8 && p7 && !p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Pos = 87;}
  if(!p8 && p7 && !p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Pos = 88;}
  if(!p8 && p7 && !p6 && !p5 && !p4 && !p3 && p2 && !p1) {Pos = 89;}
  if(!p8 && p7 && !p6 && !p5 && p4 && !p3 && p2 && !p1) {Pos = 90;}
  if(!p8 && p7 && p6 && !p5 && p4 && !p3 && p2 && !p1) {Pos = 91;}
  if(!p8 && p7 && p6 && p5 && p4 && !p3 && p2 && !p1) {Pos = 92;}
  if(!p8 && p7 && p6 && p5 && p4 && !p3 && !p2 && !p1) {Pos = 93;}
  if(!p8 && p7 && p6 && p5 && p4 && !p3 && !p2 && p1) {Pos = 94;}
  if(!p8 && p7 && p6 && p5 && p4 && p3 && !p2 && p1) {Pos = 95;}
  if(p8 && p7 && p6 && p5 && p4 && p3 && !p2 && p1) {Pos = 96;}
  if(p8 && p7 && p6 && p5 && p4 && p3 && !p2 && !p1) {Pos = 97;}
  if(p8 && p7 && p6 && p5 && p4 && !p3 && !p2 && !p1) {Pos = 98;}
  if(p8 && p7 && p6 && !p5 && p4 && !p3 && !p2 && !p1) {Pos = 99;}
  if(p8 && p7 && p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Pos = 100;}
  if(p8 && p7 && p6 && !p5 && !p4 && !p3 && p2 && !p1) {Pos = 101;}
  if(!p8 && p7 && p6 && !p5 && !p4 && !p3 && p2 && !p1) {Pos = 102;}
  if(!p8 && p7 && p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Pos = 103;}
  if(!p8 && !p7 && p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Pos = 104;}
  if(!p8 && !p7 && p6 && !p5 && !p4 && !p3 && !p2 && p1) {Pos = 105;}
  if(!p8 && !p7 && p6 && !p5 && !p4 && p3 && !p2 && p1) {Pos = 106;}
  if(!p8 && !p7 && p6 && p5 && !p4 && p3 && !p2 && p1) {Pos = 107;}
  if(!p8 && !p7 && p6 && p5 && p4 && p3 && !p2 && p1) {Pos = 108;}
  if(!p8 && !p7 && p6 && p5 && p4 && p3 && !p2 && !p1) {Pos = 109;}
  if(p8 && !p7 && p6 && p5 && p4 && p3 && !p2 && !p1) {Pos = 110;}
  if(p8 && !p7 && p6 && p5 && p4 && p3 && p2 && !p1) {Pos = 111;}
  if(p8 && p7 && p6 && p5 && p4 && p3 && p2 && !p1) {Pos = 112;}
  if(!p8 && p7 && p6 && p5 && p4 && p3 && p2 && !p1) {Pos = 113;}
  if(!p8 && p7 && p6 && p5 && p4 && p3 && !p2 && !p1) {Pos = 114;}
  if(!p8 && p7 && p6 && p5 && !p4 && p3 && !p2 && !p1) {Pos = 115;}
  if(!p8 && p7 && p6 && p5 && !p4 && !p3 && !p2 && !p1) {Pos = 116;}
  if(!p8 && p7 && p6 && p5 && !p4 && !p3 && !p2 && p1) {Pos = 117;}   
  if(!p8 && !p7 && p6 && p5 && !p4 && !p3 && !p2 && p1) {Pos = 118;}   
  if(!p8 && !p7 && p6 && p5 && !p4 && !p3 && !p2 && !p1) {Pos = 119;} 
  if(!p8 && !p7 && !p6 && p5 && !p4 && !p3 && !p2 && !p1) {Pos = 120;} 
  if(p8 && !p7 && !p6 && p5 && !p4 && !p3 && !p2 && !p1) {Pos = 121;}
  if(p8 && !p7 && !p6 && p5 && !p4 && !p3 && p2 && !p1) {Pos = 122;}
  if(p8 && !p7 && !p6 && p5 && p4 && !p3 && p2 && !p1) {Pos = 123;}
  if(p8 && !p7 && !p6 && p5 && p4 && p3 && p2 && !p1) {Pos = 124;}
  if(!p8 && !p7 && !p6 && p5 && p4 && p3 && p2 && !p1) {Pos = 125;}
  if(!p8 && p7 && !p6 && p5 && p4 && p3 && p2 && !p1) {Pos = 126;}
  if(!p8 && p7 && !p6 && p5 && p4 && p3 && p2 && p1) {Pos = 127;}
}

     if(mess) //IST berechnen ...
      {
Refleft = 106; //Pos bei Rechtsanschlag
  if (Pos >= Refleft)
  {IST = Pos - Refleft;}

  if (Pos >= 0 && Pos < Refleft)
  {IST = Pos + (127 - Refleft);}

  IST = IST * 100 / 110;
}

if (SOLL > 100){SOLL = 100;}
//task 0 and task 1 für REFFAHRT 

  
  switch (task)
  {
 
  case 2:
    {

 

      waiting = false;
     
     
      

      if (SOLL != IST)
      {
      diff = abs (SOLL - IST);
      myStepper.setSpeed(2*diff);
      if (SOLL > IST) {myStepper.step(1);}
      if (SOLL < IST) {myStepper.step(-1);}
      t = 0;
      block = true; 
      }
       
      if (SOLL == IST)
      {
      t = t+1;
     
      }  
 
      

       
       if (SOLL == IST and t >20)
         {
    
          t = 0;
          //sollPoslast = sollPos;
          task = 3; 
          k = 0;
         }
     } 
  break; 
  
  case 3:
    {
      digitalWrite(10 , LOW);
      digitalWrite(11 , LOW);
      digitalWrite(12 , LOW);
      digitalWrite(13 , LOW);

      
    if (k <  1000) {waiting = false; k = k+1;}
    if (k >= 1000) {waiting = true;}
    }
  break; 

    
  }
   

    block = false;
    delay(0);
}


