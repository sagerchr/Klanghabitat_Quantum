#include "Tlc5940.h"
#include <Encoder.h>
#include <math.h> 
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel LED1 = Adafruit_NeoPixel(10, 8, NEO_GRB + NEO_KHZ800);
float startMillis= millis(); 

void setup() {
  digitalWrite(7, LOW); 
  
  analogReference(DEFAULT);
  startMillis = millis();
  LED1.begin();
  LED1.setPixelColor(2, LED1.Color(0,0,0));
  LED1.show();  
  
  digitalWrite(7, LOW);
  Tlc.clear();
  Tlc.init();
  delay(100);
  digitalWrite(7, HIGH);
  delay(100);
  Tlc.setAllDC(63);
  delay(100);
  digitalWrite(7, LOW);
}

float signalMax = 0;                           
float sample = 0;
const int sampleWindow = 2;  //sampling zeitraum
float sig = 0;
float level = 0;

float levellast = 0;
float levelpeak = 0;
float levelpeaklast = 0;
int diff = 0;
   int levelpeak2 = 0;
   int level2 = 0;
float swell= 0;

void loop(){

/*******************AUFNAHME PEAK*****************************/
   if(millis() - startMillis < sampleWindow)
      {  
      sample = ((analogRead(A5)))*2.2*1000;
      sample = sample / 1023; 
         if (sample > signalMax)
         {
           signalMax = sample;
         }
      }
      
    if(millis() - startMillis > sampleWindow)
      { 
        startMillis = millis();
        signalMax = 0;
        
      }
/*************************************************************/  
   LED1.show();
/********************LOGARYTHMISCHEN WERT ERMITTELN***********/
   sig = (20*(log(signalMax/775)));
   level = sig+60;
   level = level/2;
/*************************************************************/

   if (level >= levelpeaklast) {levelpeak = level;}
   if (level < levelpeaklast) {levelpeak = levelpeaklast - (0.0005 * diff);} 
   

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
           if (k > level2) //greyed out 
            { 
              Tlc.set(k,0); 
            }
           
           if (k < levelpeak2 && k > level2) //zwischen Peak und Level 
           {
              Tlc.set(k,0);
           }
            
          if (k > levelpeak2) //greyed out 
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
        
      levellast = level;
      levelpeaklast = levelpeak;
      diff = levelpeak - level;
      
  if (levelpeak2 < 30){swell = 0;}    
  
  if (levelpeak2 >= 30)
  {
   swell = swell + 1;
   
   for (int k = 6; k <= 25; k++) 
        {
           Tlc.set(k,10*swell); 
         
        }
   for (int k = 39; k <= 58; k++) 
        {
           Tlc.set(k,10*swell); 
         
        }
   for (int k = 0; k <= 5; k++) 
        {
           Tlc.set(k,0);
            
        }  
   for (int k = 26; k <39; k++) 
        {
           Tlc.set(k,0);
            
        }
          
   for (int k = 59; k <=64; k++) 
        {
           Tlc.set(k,0);
            
        }     
        
  }
   for (int k = 56; k <=64; k++) 
        {
           Tlc.set(k,0);
            
        }
   for (int k = 0; k <=8; k++) 
        {
           Tlc.set(k,0);
            
        }
    
Tlc.update();
if(level2 < -15) {Tlc.set(0,50);} 
}

