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
  
int istPos = 0;

int button = 0;
bool oldState = HIGH;

int p = 0;
int l = 0;
  
const int bSize = 13; 
byte Buffer[bSize];
byte BufferThis[bSize];

/*                    [0]    [1]   [2]   [3]   [4]   [5]                               */
/********************{Pot,listen, Mode, Val1,  CMD , END *******************************/
  byte PotAnswer[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};

  
/***************************************************************************************/
/************************************void setup ()**************************************/
/***************************************************************************************/
void setup() {

  digitalWrite(7, LOW); 

  startanimation(); //Startanimation der Pot´s

  //Serial.begin(38400);
  Serial.begin(57600);
  delay(100);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(6, INPUT_PULLUP); 

  Potadress (); //Überprüfen Pot Adresse
  
}

/***************************************************************************************/
/************************************void loop ()***************************************/
/***************************************************************************************/

void loop() {

/********Serielles Paket auswerten (GesamtString/StringHeader)**************************/
    if(Serial.available() > 0) 
        {
        Serial.readBytesUntil(0xFF, Buffer, bSize);  
        }
        
        if (Buffer[0] == number)
         {
            for (int i = 0; i < 13; i++)
              {
                BufferThis [i] = Buffer[i];      
              }
         }   
/****************************************************************************************/         
   if (BufferThis [11] == 0x01)  {PositionEnc = (BufferThis [MODE+3])/2;}
            
   EncValue1 = encoder1.read();

     if (EncValue1 > EncValueLast1) {PositionEnc = PositionEnc + 1;} //Wenn neuer Wert größer dann +1
     if (EncValue1 < EncValueLast1) {PositionEnc = PositionEnc - 1;} //Wenn neuer Wert kleiner dann -1
     EncValueLast1 = EncValue1;                                      //neuesten Wert merken für nächsten Druchgang
 
     if (PositionEnc >=63) {PositionEnc = 63;}                       //PositionEnc begrenzen
     if (PositionEnc <=0) {PositionEnc = 0;};                        //PositionEnc begrenzen

     istPos = PositionEnc * 2;
 
     if (istPos > 127) {istPos = 127;}                                   
     if (istPos <= 0) {istPos = 0;}

/***********************************RING Zeichnen*******************************************/ 

if (PositionEnc <= 15) {l = PositionEnc +48;} //RING um 90° drehen
if (PositionEnc > 15) {l = PositionEnc -16;}  //RING um 90° drehen

PrintRing (MODE, l);

/*******************************************************************************************/

ModeChange (); //Überprüft den Knopfdruck und führt einen ModeChange aus falls gedrückt wurde

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
              Buffer [0] = 0xFF; //um erneutes senden zu unterbinden
              }
   
/****************************************ENDE Main*****************************************/

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
  Tlc.init();  
    for (int k = 0; k < 64; k++)
  {
    Tlc.set(k,500); 
      for (int t = 0; t < 8; t++)
        {
          LED1.setPixelColor(t, LED1.Color(k,k/6,0));
          LED1.setBrightness(100);
        }   
    delay(10);
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
    delay(10);
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
    
    delay(10);// Short delay to debounce button.
    
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
       }
     }
    oldState = newState;
}

void Potadress () //Überprüfen Pot Adresse
{ 

  int BIT1 = analogRead(A0);
  int BIT2 = analogRead(A1);
  int BIT3 = analogRead(A2);
  int BIT4 = analogRead(A3);
  
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
  LED1.show();
}

void PrintRing (int MODUS, int t) //Ring zeichnen
{

  //t       = Position des Anzeigers
  //Modus   = Aktueller Modus und entsprechende Anzeige
  
   for (int k = 0; k < 64; k++)
   {
    switch (MODUS) //verschiedene Visualisierungs MODES
    {      
      case 0:
      {
        if (k > t)  {Tlc.set(k,30); }
        if (k < t)  {Tlc.set(k,30); }       
        if (k == t) {Tlc.set(k,800);}
      } break;
       case 1:
      {
        if (k > t)  {Tlc.set(k,30); }
        if (k < t)  {Tlc.set(k,30); }       
        if (k == t) {Tlc.set(k,800);}
      } break;
       case 2:
      {
        if (k > t)  {Tlc.set(k,30); }
        if (k < t)  {Tlc.set(k,30); }       
        if (k == t) {Tlc.set(k,800);}
      } break;
    } 
   } 
  
  Tlc.update();

}


