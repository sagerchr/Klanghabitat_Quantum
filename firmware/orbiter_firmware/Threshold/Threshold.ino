#include <Encoder.h>
#include "Tlc5940.h"
#include <Encoder.h>
#include <math.h> 
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel LED1 = Adafruit_NeoPixel(10, 8, NEO_GRB + NEO_KHZ800);
float startMillis= millis(); 
Encoder encoder1(4, 2);
void setup() {
  digitalWrite(7, LOW); 
  Tlc.init(); 
  analogReference(DEFAULT);
  startMillis = millis();
  LED1.begin();
  LED1.setPixelColor(2, LED1.Color(0,0,0));
  LED1.show();
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
int levelpeak3 = 0;
int level2 = 0;
float Reduction = 0;
float Reductionlast=0;
int Reduction2 = 0;
float swell= 0;
bool peaked = false;
bool fadestart = true;
float divider = 0.0;
int EncValue=0;
int EncValueLast=0;
int PositionEnc=-10;
float Ratio =0.75;
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

/********************LOGARYTHMISCHEN WERT ERMITTELN***********/
   sig = (20*(log(signalMax/775)));
   level = sig+60;
   level = level/2;
/*************************************************************/


    level = level + PositionEnc;
   if (level >= levelpeaklast) {levelpeak = level;}
   if (level < levelpeaklast) {levelpeak = levelpeaklast - (0.0008 * diff);} 
   

   if (level >= levellast) {level = level;}
   if (level < levellast) {level = levellast - 1;}     
   
    level2 = level;
    levelpeak2 = levelpeak;

  
   //Reduction = (level2/2)-PositionEnc;
    Reduction = (level2-16)*Ratio;
    
   if (Reduction > Reductionlast) {Reduction = Reduction;}
   if (Reduction <= Reductionlast) {Reduction = Reductionlast - 0.005;}

  Reduction2 = Reduction;
    
    //levelpeak3 = (levelpeak2/2)-PositionEnc;

    
    
   if (fadestart == true && divider < 1)
   {
    divider = divider + 0.005;

   }
   
   if (fadestart == true && divider >= 1)
   {
    fadestart == false;

   }
   EncValue = encoder1.read()/4;
   if (EncValue > EncValueLast) {PositionEnc = PositionEnc+1;} //Wenn neuer Wert größer dann +1
   if (EncValue < EncValueLast) {PositionEnc = PositionEnc-1;}
   EncValueLast = EncValue; 


/*
   for (int k = 0; k < 64; k++) 
        {
           if (k < level2) //Led Streifen AN!
            {
             Tlc.set(k,100*divider);
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
              Tlc.set(k,1000*divider); 
            }
            
            if (k > 64 - level2) //Led Streifen AN!
            {
             Tlc.set(k,100*divider);
            }
            
            if (k == 64- levelpeak2) //Peak Strich
            { 
              Tlc.set(k,1000*divider); 
            }

            
        }
 */       
   for (int k = 0; k < 64; k++) 
        {
           if (k < level2) //Led Streifen AN!
            {
             Tlc.set(k,100*divider);
            }
           if (k > level2)  
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
              Tlc.set(k,1000*divider); 
            }
            
           if (k  < Reduction2+47 && k > 47) //Led Streifen AN!
            {
             Tlc.set(k,100*divider);
            }
           
            if (k == 16) //THRESHOLD
            { 
              //Tlc.set(k,0);
              Tlc.set(k,50*divider); 
            }
            if (k == levelpeak2) //Peak Strich
            { 
              Tlc.set(k,1000*divider); 
            }
            
        }


 
      levellast = level;
      levelpeaklast = levelpeak;
      diff = levelpeak - level;
      Reductionlast = Reduction;

      
    


  /*
  if (levelpeak2 >= 30)
  {
   if (swell >= 300)
   {swell = swell;}
   if (swell <= 300)
   {swell = swell+1;}
   
   peaked = true;

   for (int k = 6; k <= 25; k++) 
        {
           Tlc.set(k,1*swell); 
         
        }
   for (int k = 39; k <= 58; k++) 
        {
           Tlc.set(k,1*swell); 
         
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
  
  
  if (levelpeak2 < 30 && peaked == true)
  {
  fadestart = true;
  divider = 0;
  peaked = false;
  swell = 0; 
  
    for (int downswell = 300; downswell > 0; downswell--)
      {

        delayMicroseconds(1000);
        for (int k = 6; k <= 25; k++) 
        {
           Tlc.set(k,downswell); 
         
        }
        for (int k = 39; k <= 58; k++) 
        {
           Tlc.set(k,downswell); 
         
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

        
        Tlc.update();
     }

  }
   */

Tlc.update();
if(level2 < -15) {Tlc.set(0,50);} 
}

