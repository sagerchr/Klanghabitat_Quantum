#include <Encoder.h>
#include "Tlc5940.h"
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel LED1 = Adafruit_NeoPixel(10, 8, NEO_GRB + NEO_KHZ800);
Encoder encoder1(4, 2);

byte number; 
int MODE = 0;
#define BUTTON_PIN   6

float EncValue = 0;
float EncValue1 = 0;
float EncValue2 = 0;
float EncValueLast = 0;
float EncValueLast1 = 0;
float PositionEnc = 0;
float SPEED = 1.0;
float DIFF = 0;
float DIFF_ABS = 0;
float EncTime = 0.0;
  
int istPos = 0;

int button = 0;
bool oldState = HIGH;

int p = 0;
int l = 0;
int l_last = 0;
  
//const int bSize = 13;
const int bSize = 29;
byte Buffer[bSize];
byte BufferThis[bSize];

float swell = 0;
float blinkstart = 0.0;
float blinkintervall = 10;
bool sweller = true;

/*                    [0]    [1]   [2]   [3]   [4]   [5]                               */
/********************{Pot,listen, Mode, Val1,  CMD , END *******************************/
  byte PotAnswer[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};

  
/***************************************************************************************/
/************************************void setup ()**************************************/
/***************************************************************************************/
void setup() {
    
  digitalWrite(7, LOW);
  Tlc.clear();
  Tlc.init(); 
  delay(5000);
  
  digitalWrite(7, HIGH); 
  delay(100);
  Tlc.setAllDC(63);
  delay(100);
  
  digitalWrite(7, LOW);




  
  startanimation(); //Startanimation der Pot´s
  
  delay(100);
  
  //pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(6, INPUT_PULLUP); 

  Potadress (); //Überprüfen Pot Adresse
  
  delay (100);
  
  
  Serial.begin(57600);
  //Serial.begin(115200);
  
}
float swellstart =  millis();
/***************************************************************************************/
/************************************void loop ()***************************************/
/***************************************************************************************/
bool startsample = 0;
float samplerlast = 0;
int arraycount = 0;
float sampler = 0;
float level = 0;
float levelpeaklast = 0;
float levelpeak = 0;
int diff = 0;
float levellast = 0;
int level2 = 0;
int levelpeak2 = 0;
void loop() {
/***************************Blink*******************************************************/
if ((millis () - swellstart) > 10)
  {
    if (swell <= 1) 
      {
      if (MODE <= 1) {swell = swell + 0.01;}
      if (MODE > 1)  {swell = swell + 0.005;}
      }
    swellstart = millis ();
  }
/********Serielles Paket auswerten (GesamtString/StringHeader)**************************/
    if(Serial.available() > 0) 
        {
        Serial.readBytesUntil(0xFF, Buffer, bSize);  


         samplerlast = millis();
         startsample = 1;
         arraycount = 0;
          

        if (Buffer[0] == number)
          {
            for (int i = 0; i < 29; i++)
              {
                BufferThis [i] = Buffer[i];      
              }
          } 
        }
        
 
/****************************************************************************************/         
   if (BufferThis [27] == 0x01)  {PositionEnc = (BufferThis [MODE+3])/2;} //11->27
            
   EncValue1 = encoder1.read()/2,3;

     if (EncValueLast1 != EncValue1)
        {       
         if (millis () - EncTime <= 10)
           {
           SPEED = 1;
           } 
        if ((millis () - EncTime > 10) && (millis () - EncTime <= 30))
           {
           SPEED = 1;
           }   
        if (millis () - EncTime > 30)
           {
           SPEED = 1;
           }  
        EncTime = millis();
        } 

     if (EncValue1 > EncValueLast1) {PositionEnc = PositionEnc + (1*SPEED);} //Wenn neuer Wert größer dann +1
     if (EncValue1 < EncValueLast1) {PositionEnc = PositionEnc - (1*SPEED);} //Wenn neuer Wert kleiner dann -1
     EncValueLast1 = EncValue1;                                      //neuesten Wert merken für nächsten Druchgang
 
     if (PositionEnc >=63) {PositionEnc = 63;}                       //PositionEnc begrenzen
     if (PositionEnc <=0) {PositionEnc = 0;};                        //PositionEnc begrenzen

     //istPos = PositionEnc * 2;
       istPos = PositionEnc;
     if (istPos > 127) {istPos = 127;}                                   
     if (istPos <= 0) {istPos = 0;}

/***********************************RING Zeichnen*******************************************/ 

//if (PositionEnc <= 15) {l = PositionEnc +48;} //RING um 90° drehen
//if (PositionEnc > 15) {l = PositionEnc -16;}  //RING um 90° drehen
l = PositionEnc;


 


/*******************************************************************************************/



/*******************************************************************************************/
    
/****************************PotAnswer senden***********************************************/


       PotAnswer [0] = number;  //Pot Adresse senden
       PotAnswer [1] = number;  //Listen
       PotAnswer [2] = MODE;    //Wert je nach Mode in sende Array schreiben 
       PotAnswer [3] = istPos;  //Wert je nach Mode in sende Array schreiben 
       PotAnswer [4] = 0x00;    // CMD
       PotAnswer [5] = 0xFF;    //Abschlusszeichen
          

          if (Buffer[0] == number && BufferThis[27] != 0x01) //11CHANGE TOO--> 27
          //if (Buffer[0] == number)
              {  
              Serial.write(PotAnswer, sizeof(PotAnswer));
              Serial.flush();
              Buffer [0] = 0xFE; //um erneutes senden zu unterbinden
              }
   
/****************************************ENDE Main*****************************************/
ModeChange (); //Überprüft den Knopfdruck und führt einen ModeChange aus falls gedrückt wurde





l_last = l;

if ((number == 0 || number == 4) && MODE == 1){
 

sampler = millis() - samplerlast;
if ((sampler >= 1 || startsample) && arraycount <= 4)
        {
          samplerlast = millis();
          arraycount++;
          level = BufferThis[arraycount+8]+5;
      
          
         if (level >= levelpeaklast) {levelpeak = level;}
         if (level < levelpeaklast) {levelpeak = levelpeaklast - (0.001 * diff);} 
         
      
         if (level >= levellast) {level = level;}
         if (level < levellast) {level = levellast - 1;}     
         
          level2 = level;
          levelpeak2 = levelpeak;


          for (int k = 0; k < 64; k++) 
        {
           if (k < level2) //Led Streifen AN!
            {
             Tlc.set(k,500);
            }
           if (k > level2)
            { 
              Tlc.set(k,0); 
            }
           
           if (k < levelpeak2 && k > level2) //zwischen Peak und Level 
           {
              Tlc.set(k,0);
           }
            
          if (k > levelpeak2) 
            { 
              Tlc.set(k,0); 
            }

            if (k == levelpeak2) //Peak Strich
            { 
              Tlc.set(k,2000); 
            }

            if (k > 64 - level2) //Led Streifen AN!
            {
             Tlc.set(k,500);
            }
            if (k == 64- levelpeak2) //Peak Strich
            { 
              Tlc.set(k,2000); 
            }

          
        }

   for (int k = 0; k <=6 ; k++) 
        {
           Tlc.set(k,0);  
        }
   for (int k = 58; k <=63; k++) 
        {
           Tlc.set(k,0);  
        }
        
      levellast = level;
      levelpeaklast = levelpeak;
      diff = levelpeak - level;
        }
Tlc.update();
}      
else {PrintRing (MODE, l);}



 






} 


/*******************************************************************************************/
/***********************************FUNKTIONEN**********************************************/
/*******************************************************************************************/

void startanimation () //Startanimationsfunktion
{
  delay(200);
  LED1.begin();
  LED1.setPixelColor(0, LED1.Color(0,0,0)); LED1.setPixelColor(1, LED1.Color(0,0,0)); LED1.setPixelColor(2, LED1.Color(0,0,0)); LED1.setPixelColor(3, LED1.Color(0,0,0)); LED1.setPixelColor(4, LED1.Color(0,0,0));LED1.setPixelColor(5, LED1.Color(0,0,0));LED1.setPixelColor(6, LED1.Color(0,0,0));LED1.setPixelColor(7, LED1.Color(0,0,0));LED1.setPixelColor(8, LED1.Color(0,0,0));LED1.setPixelColor(9, LED1.Color(0,0,0));
  LED1.show();
   
    for (int k = 0; k < 64; k++)
  {
    Tlc.set(k,1000); 
      for (int t = 0; t < 8; t++)
        {
          LED1.setPixelColor(t, LED1.Color(k,k/6,0));
          LED1.setBrightness(100);
        }   
    delay(15);
    Tlc.update();
    LED1.show();
  }
  for (int k = 64; k >= 0; k--)
  {
    Tlc.set(k,0);
      for (int t = 0; t < 8; t++)
        {
          LED1.setPixelColor(t, LED1.Color(k,k/6,0));
          LED1.setBrightness(100);
        }     
    delay(15);
    Tlc.update();
    LED1.show(); 
  }
  LED1.setPixelColor(0, LED1.Color(0,0,0)); LED1.setPixelColor(1, LED1.Color(0,0,0)); LED1.setPixelColor(2, LED1.Color(0,0,0)); LED1.setPixelColor(3, LED1.Color(0,0,0)); LED1.setPixelColor(4, LED1.Color(0,0,0));LED1.setPixelColor(5, LED1.Color(0,0,0));LED1.setPixelColor(6, LED1.Color(0,0,0));LED1.setPixelColor(7, LED1.Color(0,0,0));LED1.setPixelColor(8, LED1.Color(0,0,0));LED1.setPixelColor(9, LED1.Color(0,0,0));
  LED1.show();
  Tlc.update(); 
}

void ModeChange () //Bei Knopfdruck wird ein ModeChange ausgeführt
{
  
    bool newState = digitalRead(BUTTON_PIN);
    
    if (newState == LOW && oldState == HIGH) // Check if state changed from high to low (button press).
    {
    
    delay(2);// Short delay to debounce button.
    
    newState = digitalRead(BUTTON_PIN);// Check if button is still low after debounce.
    if (newState == LOW) 
      {
        MODE++;    
         if (MODE > 3) {MODE=0;}

          PositionEnc = (BufferThis [MODE+3])/2;

         if (MODE == 0){LED1.setPixelColor(3, LED1.Color(20,3,0));LED1.setPixelColor(2, LED1.Color(0,0,0));LED1.setPixelColor(1, LED1.Color(0,0,0));}
         if (MODE == 1){LED1.setPixelColor(3, LED1.Color(0,0,0));LED1.setPixelColor(2, LED1.Color(20,3,0));LED1.setPixelColor(1, LED1.Color(0,0,0));}
         if (MODE == 2){LED1.setPixelColor(3, LED1.Color(0,0,0));LED1.setPixelColor(2, LED1.Color(0,0,0));LED1.setPixelColor(1, LED1.Color(20,3,0));}
         LED1.show();
         swell = 0.0;
       }
     }
    oldState = newState;
}

void Potadress () //Überprüfen Pot Adresse
{ 
  int BIT1 = 0;
  int BIT2 = 0;
  int BIT3 = 0;
  int BIT4 = 0;
  
  for (int i = 0; i < 10; i++) {BIT1 = (analogRead(A0) + BIT1)/i;}
  for (int i = 0; i < 10; i++) {BIT2 = (analogRead(A1) + BIT2)/i;}
  for (int i = 0; i < 10; i++) {BIT3 = (analogRead(A2) + BIT3)/i;}
  for (int i = 0; i < 10; i++) {BIT4 = (analogRead(A3) + BIT4)/i;}
     
  if (BIT1 < 1  &&  BIT2 < 1  && BIT3 < 1  && BIT4 < 1)  {number = 0x00;}
  if (BIT1 >=3  &&  BIT2 < 1  && BIT3 < 1  && BIT4 < 1)  {number = 0x01;}
  if (BIT1 < 1  &&  BIT2 >=3  && BIT3 < 1  && BIT4 < 1)  {number = 0x02;}
  if (BIT1 < 1  &&  BIT2 < 1  && BIT3 >=3  && BIT4 < 1)  {number = 0x03;}
  if (BIT1 < 1  &&  BIT2 < 1  && BIT3 < 1  && BIT4 >=3)  {number = 0x04;} 

  /**********************************************************************************************************************************************/
  //if (MODE == 0){LED1.setPixelColor(3, LED1.Color(20,3,0));LED1.setPixelColor(2, LED1.Color(0,0,0));LED1.setPixelColor(1, LED1.Color(0,0,0));}
  //if (MODE == 1){LED1.setPixelColor(3, LED1.Color(0,0,0));LED1.setPixelColor(2, LED1.Color(20,3,0));LED1.setPixelColor(1, LED1.Color(0,0,0));}
  //if (MODE == 2){LED1.setPixelColor(3, LED1.Color(0,0,0));LED1.setPixelColor(2, LED1.Color(0,0,0));LED1.setPixelColor(1, LED1.Color(20,3,0));}
  
  //if (number == 0){LED1.setPixelColor(5, LED1.Color(20,3,0));LED1.setPixelColor(6, LED1.Color(0,0,0));LED1.setPixelColor(7, LED1.Color(0,0,0));}
  //if (number == 1){LED1.setPixelColor(5, LED1.Color(0,0,0));LED1.setPixelColor(6, LED1.Color(20,3,0));LED1.setPixelColor(7, LED1.Color(0,0,0));}
  //if (number == 2){LED1.setPixelColor(5, LED1.Color(0,0,0));LED1.setPixelColor(6, LED1.Color(0,0,0));LED1.setPixelColor(7, LED1.Color(20,3,0));}
  //if (number == 3){LED1.setPixelColor(5, LED1.Color(20,3,0));LED1.setPixelColor(6, LED1.Color(20,3,0));LED1.setPixelColor(7, LED1.Color(0,0,0));}
  //if (number == 4){LED1.setPixelColor(5, LED1.Color(0,0,0));LED1.setPixelColor(6, LED1.Color(20,3,0));LED1.setPixelColor(7, LED1.Color(20,3,0));}

  //LED1.show();
}

void PrintRing (int MODUS, int t) //Ring zeichnen
{
  int q = BufferThis[5];
  
  if (q >= 0   && q < 10)  {q = 0;}
  if (q >= 10  && q < 30)  {q = 1;}
  if (q >= 30  && q < 50)  {q = 2;}
  if (q >= 50  && q < 70)  {q = 3;}
  if (q >= 70  && q < 90)  {q = 4;} 
  if (q >= 90  && q < 110) {q = 5;} 
  if (q >= 110 && q < 128) {q = 6;} 

  //t       = Position des Anzeigers
  //Modus   = Aktueller Modus und entsprechende Anzeige
 
  int add = t + 32 + q;
  if (add >= 64) {add=add-64;}

  int sub = t + 32 - q;
  if (sub >= 64) {sub=sub-64;}

   int plus = 32 + t;
   int minus = 32 - t;
   


           for (int k = 0; k < 64; k++)
          {
         
            
           Tlc.set(k,100*swell*2); 
           if(number == 0 || number == 4) {Tlc.set(32,00*swell*2);} 
           if(number == 2) {Tlc.set(0,00*swell*2);Tlc.set(16,00*swell*2);Tlc.set(32,00*swell*2);Tlc.set(48,00*swell*2);} 
           //if (k < t + 7) {Tlc.set(k,00*swell*2);}
           if (k == t + 7) {Tlc.set(k,2000*swell*2);}
           //if (k > t + 7) {Tlc.set(k,00*swell*2);}
           

         if (number == 0 || number == 4)
         {
           if(MODUS == 0)
           {
           if (k == 1) {Tlc.set(k,100*swell*2);}
           if (k == 2) {Tlc.set(k,100*swell*2);}

           if (k == 4) {Tlc.set(k,1000*swell*2);}
           if (k == 5) {Tlc.set(k,1000*swell*2);} 
           
           if (k == 63) {Tlc.set(k,100*swell*2);}
           if (k == 62) {Tlc.set(k,100*swell*2);}
           
           if (k == 60) {Tlc.set(k,100*swell*2);}
           if (k == 59) {Tlc.set(k,100*swell*2);}
           }
           if(MODUS == 1)
           {
           if (k == 1) {Tlc.set(k,2000*swell*2);}
           if (k == 2) {Tlc.set(k,2000*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,100*swell*2);}
           if (k == 62) {Tlc.set(k,100*swell*2);}
           
           if (k == 60) {Tlc.set(k,100*swell*2);}
           if (k == 59) {Tlc.set(k,100*swell*2);}
           }        
           if(MODUS == 2)
           {
           if (k == 1) {Tlc.set(k,100*swell*2);}
           if (k == 2) {Tlc.set(k,100*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,2000*swell*2);}
           if (k == 62) {Tlc.set(k,2000*swell*2);}
           
           if (k == 60) {Tlc.set(k,100*swell*2);}
           if (k == 59) {Tlc.set(k,100*swell*2);}
           }
           if(MODUS == 3)
           {
           if (k == 1) {Tlc.set(k,100*swell*2);}
           if (k == 2) {Tlc.set(k,100*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,100*swell*2);}
           if (k == 62) {Tlc.set(k,100*swell*2);}
           
           if (k == 60) {Tlc.set(k,2000*swell*2);}
           if (k == 59) {Tlc.set(k,2000*swell*2);}
           }

           
           if (k == 0) {Tlc.set(k,0*swell*2);}
           
           if (k == 3) {Tlc.set(k,0*swell*2);}
          
           if (k == 6) {Tlc.set(k,0*swell*2);}
            
           if (k == 61) {Tlc.set(k,0*swell*2);}
           
           if (k == 58) {Tlc.set(k,0*swell*2);}

           }
          



           if (number == 1)
         {
           if(MODUS == 0)
           {
           if (k == 49) {Tlc.set(k,2000*swell*2);}
           if (k == 50) {Tlc.set(k,2000*swell*2);}
           if (k == 51) {Tlc.set(k,2000*swell*2);}
           
           if (k == 53) {Tlc.set(k,100*swell*2);}
           if (k == 54) {Tlc.set(k,100*swell*2);} 
           if (k == 55) {Tlc.set(k,100*swell*2);} 
                     
           if (k == 57) {Tlc.set(k,100*swell*2);}
           if (k == 58) {Tlc.set(k,100*swell*2);}
           if (k == 59) {Tlc.set(k,100*swell*2);}
                      
           if (k == 61) {Tlc.set(k,100*swell*2);}
           if (k == 62) {Tlc.set(k,100*swell*2);}
           if (k == 63) {Tlc.set(k,100*swell*2);}
           }
           if(MODUS == 1)
           {

           
           if (k == 1) {Tlc.set(k,2000*swell*2);}
           if (k == 2) {Tlc.set(k,2000*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,100*swell*2);}
           if (k == 62) {Tlc.set(k,100*swell*2);}
           
           if (k == 60) {Tlc.set(k,100*swell*2);}
           if (k == 59) {Tlc.set(k,100*swell*2);}
           
           
           }          
           if(MODUS == 2)
           {
           if (k == 1) {Tlc.set(k,100*swell*2);}
           if (k == 2) {Tlc.set(k,100*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,2000*swell*2);}
           if (k == 62) {Tlc.set(k,2000*swell*2);}
           
           if (k == 60) {Tlc.set(k,100*swell*2);}
           if (k == 59) {Tlc.set(k,100*swell*2);}
           }
           if(MODUS == 3)
           {
           if (k == 1) {Tlc.set(k,100*swell*2);}
           if (k == 2) {Tlc.set(k,100*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,100*swell*2);}
           if (k == 62) {Tlc.set(k,100*swell*2);}
           
           if (k == 60) {Tlc.set(k,2000*swell*2);}
           if (k == 59) {Tlc.set(k,2000*swell*2);}
           }

           
           if (k == 48) {Tlc.set(k,0*swell*2);}
           
           if (k == 52) {Tlc.set(k,0*swell*2);}
          
           if (k == 56) {Tlc.set(k,0*swell*2);}
            
           if (k == 60) {Tlc.set(k,0*swell*2);}
           
           if (k == 0) {Tlc.set(k,0*swell*2);}

           }


           
             if (number == 3)
         {
           if(MODUS == 0)
           {
           if (k == 1) {Tlc.set(k,2000*swell*2);}
           if (k == 2) {Tlc.set(k,2000*swell*2);}
           if (k == 3) {Tlc.set(k,2000*swell*2);}
           
           if (k == 5) {Tlc.set(k,100*swell*2);}
           if (k == 6) {Tlc.set(k,100*swell*2);} 
           if (k == 7) {Tlc.set(k,100*swell*2);} 
                     
           if (k == 9) {Tlc.set(k,100*swell*2);}
           if (k == 10) {Tlc.set(k,100*swell*2);}
           if (k == 11) {Tlc.set(k,100*swell*2);}
                      
           if (k == 13) {Tlc.set(k,100*swell*2);}
           if (k == 14) {Tlc.set(k,100*swell*2);}
           if (k == 15) {Tlc.set(k,100*swell*2);}

            





           
           }
           if(MODUS == 1)
           {
           if (k == 1) {Tlc.set(k,2000*swell*2);}
           if (k == 2) {Tlc.set(k,2000*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,100*swell*2);}
           if (k == 62) {Tlc.set(k,100*swell*2);}
           
           if (k == 60) {Tlc.set(k,100*swell*2);}
           if (k == 59) {Tlc.set(k,100*swell*2);}
           }          
           if(MODUS == 2)
           {
           if (k == 1) {Tlc.set(k,100*swell*2);}
           if (k == 2) {Tlc.set(k,100*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,2000*swell*2);}
           if (k == 62) {Tlc.set(k,2000*swell*2);}
           
           if (k == 60) {Tlc.set(k,100*swell*2);}
           if (k == 59) {Tlc.set(k,100*swell*2);}
           }
           if(MODUS == 3)
           {
           if (k == 1) {Tlc.set(k,100*swell*2);}
           if (k == 2) {Tlc.set(k,100*swell*2);}

           if (k == 4) {Tlc.set(k,100*swell*2);}
           if (k == 5) {Tlc.set(k,100*swell*2);} 
           
           if (k == 63) {Tlc.set(k,100*swell*2);}
           if (k == 62) {Tlc.set(k,100*swell*2);}
           
           if (k == 60) {Tlc.set(k,2000*swell*2);}
           if (k == 59) {Tlc.set(k,2000*swell*2);}
           }

           
           if (k == 4) {Tlc.set(k,0*swell*2);}
           
           if (k == 8) {Tlc.set(k,0*swell*2);}
          
           if (k == 12) {Tlc.set(k,0*swell*2);}
            
           if (k == 16) {Tlc.set(k,0*swell*2);}
           
           if (k == 0) {Tlc.set(k,0*swell*2);}

           }
          }
  
  if (MODUS != 1) {Tlc.update();}
  //LED1.show();
}
