#include "Tlc5940.h"
#include <Encoder.h>
#include <math.h> 
Encoder encoder1(4, 2);
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel LED1 = Adafruit_NeoPixel(10, 8, NEO_GRB + NEO_KHZ800);

void setup() {
  digitalWrite(7, LOW); 
  Tlc.init(); 
  analogReference(DEFAULT);
    LED1.begin();
  
   for (int t = 0; t < 8; t++)
    {
   LED1.setPixelColor(t, LED1.Color(0,0,0));   
   //LED1.setPixelColor(t, LED1.Color(20,3,0));
    }
    
  //LED1.setPixelColor(0, LED1.Color(20,1,0)); LED1.setPixelColor(1, LED1.Color(20,1,0)); LED1.setPixelColor(2, LED1.Color(20,1,0)); LED1.setPixelColor(3, LED1.Color(20,1,0)); LED1.setPixelColor(4, LED1.Color(20,1,0));LED1.setPixelColor(5, LED1.Color(20,1,0));LED1.setPixelColor(6, LED1.Color(20,1,0));LED1.setPixelColor(7, LED1.Color(20,1,0));
  LED1.setBrightness(100);
  LED1.show();
 }
int i = 0;
int t = 30;
int EncValue1 = 0;
int EncValueLast1 = 0;
int PositionEnc = 0;
int ArcPos = 0;
float sig = 0;

const int sampleWindow = 20;                              // Sample window width in mS 

   float db =0;
   float signalMax = 0;                           
   float sample = 0;
   float level = 0;

   float levellast = 0;
   float levelpeak = 0;
   float levelpeaklast = 0;
   int levelpeak2 = 0;
   int level2 = 0;
   int diff = 0;
   bool blinker = true;
   int snakecount = 0;
   bool limit = false;
void loop() {

   float startMillis= millis();                   
  
   while (millis() - startMillis < sampleWindow)
   {

     sample = ((analogRead(A5)))*2.2*1000;
      sample = sample / 1023;  
                                  
         if (sample > signalMax)
         {
            signalMax = sample;
         }
   }

    
   sig = (20*(log(signalMax/775)));
   level = sig+45;


   if (level >= levelpeaklast) {levelpeak = level;}
   if (level < levelpeaklast) {levelpeak = levelpeaklast - (0.02 * diff);} 
   if (level >= levellast) {level = level;}
   if (level < levellast) {level = levellast - 1;}     
 
    level2 = level;
    levelpeak2 = levelpeak;

   
    if (levelpeak2 >= 55 || snakecount != 30)
      {
         limit = true;
         if (snakecount <= 30)
         {
         snakecount = snakecount +1;
         }
         if (snakecount > 30)
         {
         snakecount = 0;
         }         
      }
      
    if (levelpeak2 < 55 && snakecount == 30)
      {
         limit = false;
      }

   
    for (int k = 0; k < 64; k++)
      
    {    
          
           if (k < level2) //Led Streifen AN!
            {
              if (!limit)
              { 
              Tlc.set(k,1000);
              }
              if (limit)
              {
              Tlc.set(k,snakecount*30);
              }
            }
        
         
          if (k < levelpeak2 && k > level2) //zwischen Peak und Level 
           {
              Tlc.set(k,200);
           }
            
          if (k > levelpeak2) //greyed out 
            { 
              Tlc.set(k,30); 
            }

            if (k == levelpeak2) //Peak Strich
            { 
              Tlc.set(k,1000); 
            }

         levellast = level;
         levelpeaklast = levelpeak;
         diff = levelpeak - level;
      }   
      
      Tlc.update();



 db = 0;
 signalMax = 0;                            
 sample = 0;
                    
}
