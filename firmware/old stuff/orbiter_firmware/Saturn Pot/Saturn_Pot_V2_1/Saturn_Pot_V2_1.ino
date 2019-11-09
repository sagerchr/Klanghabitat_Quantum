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
const int bSize = 13;
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
    
  digitalWrite(7,LOW); 
  delay(100);
  Tlc.init(); 
  delay(100);
  Tlc.clear();
  delay(100);
  Tlc.update();
  startanimation(); //Startanimation der Pot´s
  
  delay(100);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(6, INPUT_PULLUP); 

  Potadress (); //Überprüfen Pot Adresse
  
  delay (100);
  
  
  Serial.begin(57600);
  
}
float swellstart =  millis();
/***************************************************************************************/
/************************************void loop ()***************************************/
/***************************************************************************************/

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


        if (Buffer[0] == number)
          {
            for (int i = 0; i < 13; i++)
              {
                BufferThis [i] = Buffer[i];      
              }
          } 
        }
        
 
/****************************************************************************************/         
   if (BufferThis [11] == 0x01)  {PositionEnc = (BufferThis [MODE+3])/2;}
            
   EncValue1 = encoder1.read()/4;

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

     istPos = PositionEnc * 2;
 
     if (istPos > 127) {istPos = 127;}                                   
     if (istPos <= 0) {istPos = 0;}

/***********************************RING Zeichnen*******************************************/ 

//if (PositionEnc <= 15) {l = PositionEnc +48;} //RING um 90° drehen
//if (PositionEnc > 15) {l = PositionEnc -16;}  //RING um 90° drehen
l = PositionEnc;


 

l_last = l;
/*******************************************************************************************/



/*******************************************************************************************/
    
/****************************PotAnswer senden***********************************************/


       PotAnswer [0] = number;  //Pot Adresse senden
       PotAnswer [1] = number;  //Listen
       PotAnswer [2] = MODE;    //Wert je nach Mode in sende Array schreiben 
       PotAnswer [3] = istPos;  //Wert je nach Mode in sende Array schreiben 
       PotAnswer [4] = 0x00;    // CMD
       PotAnswer [5] = 0xFF;    //Abschlusszeichen
          

          if (Buffer[0] == number && BufferThis[11] != 0x01)
          //if (Buffer[0] == number)
              {  
              Serial.write(PotAnswer, sizeof(PotAnswer));
              Serial.flush();
              Buffer [0] = 0xFE; //um erneutes senden zu unterbinden
              }
   
/****************************************ENDE Main*****************************************/
ModeChange (); //Überprüft den Knopfdruck und führt einen ModeChange aus falls gedrückt wurde
PrintRing (MODE, l);
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
    Tlc.set(k,500); 
      for (int t = 0; t < 8; t++)
        {
          LED1.setPixelColor(t, LED1.Color(k,k/6,0));
          LED1.setBrightness(100);
        }   
    delay(5);
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
    delay(5);
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
         if (MODE > 2) {MODE=0;}

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
  if (MODE == 0){LED1.setPixelColor(3, LED1.Color(20,3,0));LED1.setPixelColor(2, LED1.Color(0,0,0));LED1.setPixelColor(1, LED1.Color(0,0,0));}
  if (MODE == 1){LED1.setPixelColor(3, LED1.Color(0,0,0));LED1.setPixelColor(2, LED1.Color(20,3,0));LED1.setPixelColor(1, LED1.Color(0,0,0));}
  if (MODE == 2){LED1.setPixelColor(3, LED1.Color(0,0,0));LED1.setPixelColor(2, LED1.Color(0,0,0));LED1.setPixelColor(1, LED1.Color(20,3,0));}
  
  if (number == 0){LED1.setPixelColor(5, LED1.Color(20,3,0));LED1.setPixelColor(6, LED1.Color(0,0,0));LED1.setPixelColor(7, LED1.Color(0,0,0));}
  if (number == 1){LED1.setPixelColor(5, LED1.Color(0,0,0));LED1.setPixelColor(6, LED1.Color(20,3,0));LED1.setPixelColor(7, LED1.Color(0,0,0));}
  if (number == 2){LED1.setPixelColor(5, LED1.Color(0,0,0));LED1.setPixelColor(6, LED1.Color(0,0,0));LED1.setPixelColor(7, LED1.Color(20,3,0));}
  if (number == 3){LED1.setPixelColor(5, LED1.Color(20,3,0));LED1.setPixelColor(6, LED1.Color(20,3,0));LED1.setPixelColor(7, LED1.Color(0,0,0));}
  if (number == 4){LED1.setPixelColor(5, LED1.Color(0,0,0));LED1.setPixelColor(6, LED1.Color(20,3,0));LED1.setPixelColor(7, LED1.Color(20,3,0));}

  LED1.show();
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
    switch (MODUS) //verschiedene Visualisierungs MODES
    {
/**********************************************************************************************************************************************/           
      case 0:
      {
        if (k > t)  {Tlc.set(k,10*swell*0); }
        if (k < t)  {Tlc.set(k,10*swell*0); }       
        if (k == t) {Tlc.set(k,3000*swell);}
       
        if (t >= 48)                        {if (k == t - 32) {Tlc.set(k,0);}if (k == t - 32 - q)   {Tlc.set(k,0);}   if (k == t - 32 + q) {Tlc.set(k,0);}}
       
        if (t >= 0  && t < 32)              {if (k == t + 32) {Tlc.set(k,0);}if (k == add )   {Tlc.set(k,0);}   if (k == sub) {Tlc.set(k,0);}} 
        
        if (t >= 32 && t < 48)              {if (k == t - 32) {Tlc.set(k,0);}if (k == add)   {Tlc.set(k,0);}   if (k == sub) {Tlc.set(k,0);}}
      
      } break;
/**********************************************************************************************************************************************/      
       case 1:
      {
        if (k == 15)
        {
        if (k > t)  {Tlc.set(k,10*swell*2); }
        if (k < t)  {Tlc.set(k,10*swell*2); } 
        if (k == t) {Tlc.set(k,1000*swell*2);}
        }
        if (k != 15)
        {
        if (k > t)  {Tlc.set(k,10*swell); }
        if (k < t)  {Tlc.set(k,10*swell); } 
        if (k == t) {Tlc.set(k,1000*swell);}
        }

        
        
      } break;

/**********************************************************************************************************************************************/     
       case 2:
      {

        if (k <= plus && k >= minus) {Tlc.set(k,600 * swell);}
        
        if (k > plus) {Tlc.set(k,0);}
        if (k < minus) {Tlc.set(k,0);}

      } break;
/**********************************************************************************************************************************************/     
    } 
    
   } 
  
  Tlc.update();
  //LED1.show();
}


