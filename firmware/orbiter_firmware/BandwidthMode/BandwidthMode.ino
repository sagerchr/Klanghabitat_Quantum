#include "Tlc5940.h"
#include <Encoder.h>
Encoder encoder1(4, 2);

void setup() {
  digitalWrite(7, LOW); 
  Tlc.init(); 
 }
int i = 0;
int t = 30;
int EncValue1 = 0;
int EncValueLast1 = 0;
int PositionEnc = 0;
int ArcPos = 0;

void loop() {
    
    
   EncValue1 = encoder1.read()/4;
     if (EncValue1 > EncValueLast1) {PositionEnc = PositionEnc + 1;} 
     if (EncValue1 < EncValueLast1) {PositionEnc = PositionEnc - 1;} 
     EncValueLast1 = EncValue1;
     if (PositionEnc >=63) {PositionEnc = 63;}
     if (PositionEnc <=0) {PositionEnc = 0;};
     if (PositionEnc <= 15) {ArcPos = PositionEnc + 48;}
     if (PositionEnc > 16) {ArcPos = PositionEnc - 16;}
    
     
    for (int k = 0; k < 64; k++)
      
    {    
     if (PositionEnc >=28) {PositionEnc = 28;}
     if (PositionEnc <=0) {PositionEnc = 0;};
     
      if(PositionEnc <=15)
      {
        if (k >= 16-PositionEnc && k <= 16 + PositionEnc) 
         {
          Tlc.set(k,300);  
         }
        else
         { 
          Tlc.set(k,0);   
         }
      }
    
      if(PositionEnc > 15 && PositionEnc <= 64)
      {
         if (k <= 32) 
         {
          Tlc.set(k,300);  
         }
         else if (k >= 80-PositionEnc) 
         {
          Tlc.set(k,300);  
         }
         else if (k <= 16 + PositionEnc)
         {
          Tlc.set(k,300); 
          }
        else
         { 
          Tlc.set(k,0);   
         }
      }
    
    }
    
    Tlc.update();





    
}
