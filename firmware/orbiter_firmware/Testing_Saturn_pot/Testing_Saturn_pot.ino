#include "Tlc5940.h"


void setup() {
  digitalWrite(7, LOW); 
  Tlc.init(); 
  delay(1000);
 }
int i = 0;
int t = 30;
 
void loop() {
    
    

     
    for (int k = 0; k < 64; k++)
    {
    Tlc.set(k,50);
    }
    Tlc.update();
    delay(200);
    for (int k = 0; k < 64; k++)
    {
    Tlc.set(k,50);
    }
    Tlc.update();
    delay(200);




    
}
