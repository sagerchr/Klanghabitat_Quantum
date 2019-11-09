#include "Tlc5940.h"
#include <math.h> 
float startMillis= millis(); 

void setup() {
  digitalWrite(7, LOW); 
  
  digitalWrite(7, LOW);
  Tlc.clear();
  Tlc.init();
  delay(100);
  digitalWrite(7, HIGH);
  delay(100);
  Tlc.setAllDC(63);
  delay(100);
  digitalWrite(7, LOW);
  
  Serial.begin(57600);

}


const int bSize = 13;
byte Buffer[bSize];
byte BufferThis[bSize];

float sampler = 0;
float samplerlast = 0;

bool startsample = 0;

int arraycount = 0;

byte sample =0;
float sig = 0;
float reader = 0;
float level = 0;



float levellast = 0;
float levelpeak = 0;
float levelpeaklast = 0;
int diff = 0;
int levelpeak2 = 0;
int level2 = 0;
float swell= 0;

void loop(){

  if(Serial.available() > 0) 
      {
      
      Serial.readBytesUntil(0xFF, Buffer, bSize);  
      startsample = 1;
      
      samplerlast = millis();
      startsample = 1;
      arraycount = 0;
      }
 



   sampler = millis() - samplerlast;
   if ((sampler >= 1 || startsample) && arraycount <= 4)
   {
    samplerlast = millis();
    arraycount++;
    level = Buffer[arraycount]+5;

    
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
   /*   
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
    */
Tlc.update();

//if(level2 < -15) {Tlc.set(0,50);} 






   }
    
}

