#include <Encoder.h>

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

int sensorValue;
int SollPosition;

bool refpositionL = false;
bool refpositionR = false;

Encoder encoder(2, 3);

void setup() {


  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(4, INPUT_PULLUP); //Adresse
  pinMode(5, INPUT_PULLUP); //Adresse
  pinMode(6, INPUT_PULLUP); //Adresse
  
  int pin4 = digitalRead(4); //Adresse
  int pin5 = digitalRead(5); //Adresse
  int pin6 = digitalRead(6); //Adresse
  

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




  int EncValue = 0;
  int left = 0;
  int right = 0;
  
  int istPos = 0;
  int sollPos = 64;
  int sollPoslast = 0;
  
  int task = 0;
  
  long p = 0;
  int t = 0;
  int k = 0;
  bool waiting = true;

void loop() {


/*********Routine um Motor in Refposition zu bringen************/

  
  
  //delayMicroseconds(10); //generelles Timing



/*******************************************CHAR für IST Wert aufbereiten********************************/

      //if (sensorValue<100)
      if (istPos<100)
      {
        thirdbyteIST = '0';
        if (istPos< 10){firstbyteIST = '0'; secondbyteIST = char(istPos+48);}
        if (istPos >= 10 && istPos <20 ){firstbyteIST = '1'; secondbyteIST = char(istPos+38);}
        if (istPos >= 20 && istPos <30 ){firstbyteIST = '2'; secondbyteIST = char(istPos+28);}
        if (istPos >= 30 && istPos <40 ){firstbyteIST = '3'; secondbyteIST = char(istPos+18);}
        if (istPos >= 40 && istPos <50 ){firstbyteIST = '4'; secondbyteIST = char(istPos+8);}
        if (istPos >= 50 && istPos <60 ){firstbyteIST = '5'; secondbyteIST = char(istPos-2);}
        if (istPos >= 60 && istPos <70 ){firstbyteIST = '6'; secondbyteIST = char(istPos-12);}
        if (istPos >= 70 && istPos <80 ){firstbyteIST = '7'; secondbyteIST = char(istPos-22);}
        if (istPos >= 80 && istPos <90 ){firstbyteIST = '8'; secondbyteIST = char(istPos-32);}
        if (istPos >= 90 && istPos <100 ){firstbyteIST = '9';secondbyteIST = char(istPos-42);}
      }
       //if (sensorValue >= 100)
       if (istPos >= 100)
       {
        thirdbyteIST = '1';
        if (istPos< 110){firstbyteIST = '0'; secondbyteIST = char(istPos-52);}
        if (istPos >= 110 && istPos <120 ){firstbyteIST = '1'; secondbyteIST = char(istPos-62);}
        if (istPos >= 120 && istPos <130 ){firstbyteIST = '2'; secondbyteIST = char(istPos-72);}
        if (istPos >= 130 && istPos <140 ){firstbyteIST = '3'; secondbyteIST = char(istPos-82);}
        if (istPos >= 140 && istPos <150 ){firstbyteIST = '4'; secondbyteIST = char(istPos-92);}
        if (istPos >= 150 && istPos <160 ){firstbyteIST = '5'; secondbyteIST = char(istPos-102);}
        if (istPos >= 160 && istPos <170 ){firstbyteIST = '6'; secondbyteIST = char(istPos-112);}
        if (istPos >= 170 && istPos <180 ){firstbyteIST = '7'; secondbyteIST = char(istPos-122);}
        if (istPos >= 180 && istPos <190 ){firstbyteIST = '8'; secondbyteIST = char(istPos-132);}
        if (istPos >= 190){firstbyteIST = '9'; secondbyteIST = '0';}
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
        if (StrINHeader == Position && task == 3)
        {    
        /*INT für SollPosition erzeugen*/  
        firstbytePos  = strIN.substring(4,5).toInt();
        secondbytePos = strIN.substring(5,6).toInt();
        thirdbytePos  = strIN.substring(6,7).toInt();
        
        if (thirdbytePos == 0) //hunderterStelle = 0
        {
         if (firstbytePos == 0) {sollPos = secondbytePos + 00;} //firstbytePos = 0
         if (firstbytePos == 1) {sollPos = secondbytePos + 10;} //firstbytePos = 1
         if (firstbytePos == 2) {sollPos = secondbytePos + 20;} //firstbytePos = 2
         if (firstbytePos == 3) {sollPos = secondbytePos + 30;} //firstbytePos = 3
         if (firstbytePos == 4) {sollPos = secondbytePos + 40;} //firstbytePos = 4
         if (firstbytePos == 5) {sollPos = secondbytePos + 50;} //firstbytePos = 5
         if (firstbytePos == 6) {sollPos = secondbytePos + 60;} //firstbytePos = 6
         if (firstbytePos == 7) {sollPos = secondbytePos + 70;} //firstbytePos = 7
         if (firstbytePos == 8) {sollPos = secondbytePos + 80;} //firstbytePos = 8
         if (firstbytePos == 9) {sollPos = secondbytePos + 90;} //firstbytePos = 9
        }

        if (thirdbytePos == 1) //hunderterStelle = 1
        {
         if (firstbytePos == 0) {sollPos = secondbytePos + 100;} //firstbytePos = 0
         if (firstbytePos == 1) {sollPos = secondbytePos + 110;} //firstbytePos = 1
         if (firstbytePos == 2) {sollPos = secondbytePos + 120;} //firstbytePos = 2
         if (firstbytePos == 3) {sollPos = secondbytePos + 130;} //firstbytePos = 3
         if (firstbytePos == 4) {sollPos = secondbytePos + 140;} //firstbytePos = 4
         if (firstbytePos == 5) {sollPos = secondbytePos + 150;} //firstbytePos = 5
         if (firstbytePos == 6) {sollPos = secondbytePos + 160;} //firstbytePos = 6
         if (firstbytePos == 7) {sollPos = secondbytePos + 170;} //firstbytePos = 7
         if (firstbytePos == 8) {sollPos = secondbytePos + 180;} //firstbytePos = 8
         if (firstbytePos == 9) {sollPos = secondbytePos + 190;} //firstbytePos = 9
        }
        
        StrINHeader = "NULL";
        task = 2; //Regelung einleiten
        
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
EncValue = (encoder.read())/2;
  istPos = ((EncValue - left) * 129/right); //Der korrekte MIDI Wert!
  if (istPos > 127) {istPos = 127;}

  
  switch (task)
  {
  //Position links anfahren (1 sek.) für minimalen Wert
  case 0:
    {
      analogWrite(11,40); //links
      analogWrite(10,0); //rechts
      p = p + 1;
      if (i >= 50) {
        analogWrite(11,0); //links
        analogWrite(10,0); //rechts      
        p = 0;
        task = 1;
        left = EncValue +1;
      }
    }
  break; 
  
  //Position rechts anfahren (1 sek.) für maximalen Wert
  case 1:
    {
      analogWrite(11,0); //links
      analogWrite(10,40); //rechts
      p = p + 1;
      if (p >= 3000) {
        analogWrite(11,0); //links
        analogWrite(10,0); //rechts      
        p = 0;
        task = 2;
        right = EncValue - left;
      }
    }
  break; 
  
  //Position anfahren 
  case 2:
    {
      waiting = false; 
      if (sollPos == istPos)
         {
          analogWrite(11,0); //links
          analogWrite(10,0); //rechts 
          t = t+1; 
         }
      
      if (sollPos != istPos)
         {
            if (sollPos > istPos) //rechts Bewegung
              {
                 if (sollPos-istPos <= 30) //langsam fahren
                 {
                  analogWrite(11,0); //links
                  analogWrite(10,40); //rechts  
                 }
                 if (sollPos-istPos > 30) //schnell fahren
                 {
                  analogWrite(11,0); //links
                  analogWrite(10,200); //rechts  
                 }
              }

              
            if (sollPos < istPos) //links Bewegung
              {
                if (istPos-sollPos <= 30) //langsam fahren
                { 
                 analogWrite(11,40); //links
                 analogWrite(10,0); //rechts  
                }
                if (istPos-sollPos > 30) //schnell fahren
                { 
                 analogWrite(11,200); //links
                 analogWrite(10,0); //rechts  
                }
                
              }    
         }
       
       if (sollPos == istPos and t == 300)
         {
          t = 0;
          sollPoslast = sollPos;
          task = 3; 
          k = 0;
         }
     } 
  break; 
  
  case 3:
    {
   // Serial.println(istPos);
    //if (sollPos != sollPoslast){task = 2;}   
    if (k <  100) {waiting = false; k = k+1;}
    if (k >= 100) {waiting = true;}
    }
  break; 

    
  }
      
}


