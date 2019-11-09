#include <Encoder.h>

Encoder myEnc(2, 3);


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
    
    
  analogWrite(11,40); //links
  analogWrite(10,0); //rechts
  delay(800);
  analogWrite(11,00); //links
  analogWrite(10,0); //rechts
  delay(500);
}

long oldPosition  = -999;
  int i = 0;
  int startleft;
  
void loop() 

{
  
  if(i==0)
  {
  startleft = myEnc.read();
  i=1;
  }
  
  long newPosition = myEnc.read();
  
  if (newPosition != oldPosition) 
  {
    oldPosition = newPosition;
    Serial.println((newPosition - startleft)/3);
  }
  
  if(i==1)
  {
  analogWrite(11,0); //links
  analogWrite(10,255); //rechts
  delay(20);
  analogWrite(11,0); //links
  analogWrite(10,0); //rechts
  delay(500);
  analogWrite(11,0); //links
  analogWrite(10,255); //rechts
  delay(20);
  analogWrite(11,0); //links
  analogWrite(10,0); //rechts
  delay(500);
  analogWrite(11,0); //links
  analogWrite(10,255); //rechts
  delay(20);
  analogWrite(11,0); //links
  analogWrite(10,0); //rechts
  delay(500);
  analogWrite(11,255); //links
  analogWrite(10,0); //rechts
  delay(20);
  analogWrite(11,0); //links
  analogWrite(10,0); //rechts
  delay(500);
  analogWrite(11,255); //links
  analogWrite(10,0); //rechts
  delay(20);
  analogWrite(11,0); //links
  analogWrite(10,0); //rechts
  delay(500);
  analogWrite(11,255); //links
  analogWrite(10,0); //rechts
  delay(25 );
  analogWrite(11,0); //links
  analogWrite(10,0); //rechts
  i=2;
  }

  
  
}




  
