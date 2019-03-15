#include "Tlc5940.h"
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
    for (int k = 0; k < 64; k++) 
      {
      Tlc.set(k,0);
      if (k <= Buffer[arraycount]) {Tlc.set(k,1000);}  
      Tlc.update();
      }
   }




    
}

