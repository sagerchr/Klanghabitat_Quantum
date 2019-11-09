
#include <Stepper.h>

const int stepsPerRevolution = 200;  

Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13);

void setup() {
  myStepper.setSpeed(120);
  Serial.begin(19200);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
}
  int Position = 0;
  int IST = 0;
  int SOLL = 88;
  int left = 0;
  bool p1 =false;
  bool p2 =false;
  bool p3 =false;
  bool p4 =false;
  bool p5 =false;
  bool p6 =false;
  bool p7 =false;
  bool p8 =false;

  bool mess = true;


void loop() {
  
  p1 = digitalRead(2); p2 = digitalRead(3); p3 = digitalRead(4); p4 = digitalRead(5); p5 = digitalRead(6); p6 = digitalRead(7); p7 = digitalRead(8); p8 = digitalRead(9); 

if(mess) //Position messen ...
{
  if(!p8 && p7 && p6 && p5 && p4 && p3 && p2 && p1) {Position = 0;}
  if(!p8 && !p7 && p6 && p5 && p4 && p3 && p2 && p1) {Position = 1;}
  if(!p8 && !p7 && p6 && p5 && p4 && p3 && p2 && !p1) {Position = 2;}   
  if(!p8 && !p7 && p6 && p5 && p4 && !p3 && p2 && !p1) {Position = 3;}
  if(!p8 && !p7 && p6 && p5 && p4 && !p3 && !p2 && !p1) {Position = 4;}
  if(p8 && !p7 && p6 && p5 && p4 && !p3 && !p2 && !p1) {Position = 5;}
  if(p8 && !p7 && !p6 && p5 && p4 && !p3 && !p2 && !p1) {Position = 6;}
  if(!p8 && !p7 && !p6 && p5 && p4 && !p3 && !p2 && !p1) {Position = 7;}
  if(!p8 && !p7 && !p6 && !p5 && p4 && !p3 && !p2 && !p1) {Position = 8;}
  if(!p8 && p7 && !p6 && !p5 && p4 && !p3 && !p2 && !p1) {Position = 9;}
  if(!p8 && p7 && !p6 && !p5 && p4 && !p3 && !p2 && p1) {Position = 10;}
  if(!p8 && p7 && !p6 && !p5 && p4 && p3 && !p2 && p1) {Position = 11;}
  if(!p8 && p7 && !p6 && !p5 && p4 && p3 && p2 && p1) {Position = 12;}
  if(!p8 && !p7 && !p6 && !p5 && p4 && p3 && p2 && p1) {Position = 13;}
  if(!p8 && !p7 && p6 && !p5 && p4 && p3 && p2 && p1) {Position = 14;}  
  if(p8 && !p7 && p6 && !p5 && p4 && p3 && p2 && p1) {Position = 15;}    
  if(p8 && !p7 && p6 && p5 && p4 && p3 && p2 && p1) {Position = 16;}    
  if(p8 && !p7 && !p6 && p5 && p4 && p3 && p2 && p1) {Position = 17;}   
  if(!p8 && !p7 && !p6 && p5 && p4 && p3 && p2 && p1) {Position = 18;}   
  if(!p8 && !p7 && !p6 && p5 && p4 && p3 && !p2 && p1) {Position = 19;}  
  if(!p8 && !p7 && !p6 && p5 && p4 && p3 && !p2 && !p1) {Position = 20;} 
  if(!p8 && p7 && !p6 && p5 && p4 && p3 && !p2 && !p1) {Position = 21;} 
  if(!p8 && p7 && !p6 && !p5 && p4 && p3 && !p2 && !p1) {Position = 22;}   
  if(!p8 && !p7 && !p6 && !p5 && p4 && p3 && !p2 && !p1) {Position = 23;} 
  if(!p8 && !p7 && !p6 && !p5 && !p4 && p3 && !p2 && !p1) {Position = 24;} 
  if(!p8 && !p7 && p6 && !p5 && !p4 && p3 && !p2 && !p1) {Position = 25;} 
  if(p8 && !p7 && p6 && !p5 && !p4 && p3 && !p2 && !p1) {Position = 26;} 
  if(p8 && !p7 && p6 && !p5 && !p4 && p3 && p2 && !p1) {Position = 27;} 
  if(p8 && !p7 && p6 && !p5 && !p4 && p3 && p2 && p1) {Position = 28;}   
  if(p8 && !p7 && !p6 && !p5 && !p4 && p3 && p2 && p1) {Position = 29;}  
  if(p8 && !p7 && !p6 && p5 && !p4 && p3 && p2 && p1) {Position = 30;} 
  if(p8 && p7 && !p6 && p5 && !p4 && p3 && p2 && p1) {Position = 31;} 
  if(p8 && p7 && !p6 && p5 && p4 && p3 && p2 && p1) {Position = 32;} 
  if(p8 && p7 && !p6 && !p5 && p4 && p3 && p2 && p1) {Position = 33;} 
  if(p8 && !p7 && !p6 && !p5 && p4 && p3 && p2 && p1) {Position = 34;} 
  if(p8 && !p7 && !p6 && !p5 && p4 && p3 && p2 && !p1) {Position = 35;}
  if(!p8 && !p7 && !p6 && !p5 && p4 && p3 && p2 && !p1) {Position = 36;}
  if(!p8 && !p7 && p6 && !p5 && p4 && p3 && p2 && !p1) {Position = 37;}
  if(!p8 && !p7 && p6 && !p5 && !p4 && p3 && p2 && !p1) {Position = 38;}
  if(!p8 && !p7 && !p6 && !p5 && !p4 && p3 && p2 && !p1) {Position = 39;}  
  if(!p8 && !p7 && !p6 && !p5 && !p4 && !p3 && p2 && !p1) {Position = 40;}  
  if(!p8 && !p7 && !p6 && p5 && !p4 && !p3 && p2 && !p1) {Position = 41;}
  if(!p8 && p7 && !p6 && p5 && !p4 && !p3 && p2 && !p1) {Position = 42;}
  if(!p8 && p7 && !p6 && p5 && !p4 && !p3 && p2 && !p1) {Position = 43;}
  if(p8 && p7 && !p6 && p5 && !p4 && !p3 && p2 && p1) {Position = 44;}
  if(p8 && p7 && !p6 && !p5 && !p4 && !p3 && p2 && p1) {Position = 45;}
  if(p8 && p7 && !p6 && !p5 && p4 && !p3 && p2 && p1) {Position = 46;}
  if(p8 && p7 && p6 && !p5 && p4 && !p3 && p2 && p1) {Position = 47;}
  if(p8 && p7 && p6 && !p5 && p4 && p3 && p2 && p1) {Position = 48;}
  if(p8 && p7 && p6 && !p5 && !p4 && p3 && p2 && p1) {Position = 49;}
  if(p8 && p7 && !p6 && !p5 && !p4 && p3 && p2 && p1) {Position = 50;}
  if(!p8 && p7 && !p6 && !p5 && !p4 && p3 && p2 && p1) {Position = 51;}
  if(!p8 && !p7 && !p6 && !p5 && !p4 && p3 && p2 && p1) {Position = 52;}
  if(!p8 && !p7 && !p6 && p5 && !p4 && p3 && p2 && p1) {Position = 53;}
  if(!p8 && !p7 && !p6 && p5 && !p4 && !p3 && p2 && p1) {Position = 54;}
  if(!p8 && !p7 && !p6 && !p5 && !p4 && !p3 && p2 && p1) {Position = 55;}
  if(!p8 && !p7 && !p6 && !p5 && !p4 && !p3 && !p2 && p1) {Position = 56;}
  if(!p8 && !p7 && !p6 && !p5 && p4 && !p3 && !p2 && p1) {Position = 57;}
  if(!p8 && !p7 && p6 && !p5 && p4 && !p3 && !p2 && p1) {Position = 58;}
  if(p8 && !p7 && p6 && !p5 && p4 && !p3 && !p2 && p1) {Position = 59;}
  if(p8 && p7 && p6 && !p5 && p4 && !p3 && !p2 && p1) {Position = 60;}
  if(p8 && p7 && p6 && !p5 && !p4 && !p3 && !p2 && p1) {Position = 61;}
  if(p8 && p7 && p6 && !p5 && !p4 && p3 && !p2 && p1) {Position = 62;}
  if(p8 && p7 && p6 && p5 && !p4 && p3 && !p2 && p1) {Position = 63;}
  if(p8 && p7 && p6 && p5 && !p4 && p3 && p2 && p1) {Position = 64;}     
  if(p8 && p7 && p6 && p5 && !p4 && !p3 && p2 && p1) {Position = 65;}   
  if(p8 && p7 && p6 && !p5 && !p4 && !p3 && p2 && p1) {Position = 66;}  
  if(p8 && !p7 && p6 && !p5 && !p4 && !p3 && p2 && p1) {Position = 67;}
  if(p8 && !p7 && !p6 && !p5 && !p4 && !p3 && p2 && p1) {Position = 68;}
  if(p8 && !p7 && !p6 && !p5 && p4 && !p3 && p2 && p1) {Position = 69;}
  if(p8 && !p7 && !p6 && !p5 && p4 && !p3 && !p2 && p1) {Position = 70;}
  if(p8 && !p7 && !p6 && !p5 && !p4 && !p3 && !p2 && p1) {Position = 71;}
  if(p8 && !p7 && !p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Position = 72;}
  if(p8 && !p7 && !p6 && !p5 && !p4 && p3 && !p2 && !p1) {Position = 73;}
  if(p8 && !p7 && !p6 && p5 && !p4 && p3 && !p2 && !p1) {Position = 74;}
  if(p8 && p7 && !p6 && p5 && !p4 && p3 && !p2 && !p1) {Position = 75;}
  if(p8 && p7 && p6 && p5 && !p4 && p3 && !p2 && !p1) {Position = 76;}
  if(p8 && p7 && p6 && p5 && !p4 && !p3 && !p2 && !p1) {Position = 77;}
  if(p8 && p7 && p6 && p5 && !p4 && !p3 && p2 && !p1) {Position = 78;}
  if(p8 && p7 && p6 && p5 && p4 && !p3 && p2 && !p1) {Position = 79;}
  if(p8 && p7 && p6 && p5 && p4 && !p3 && p2 && p1) {Position = 80;}
  if(p8 && p7 && p6 && p5 && p4 && !p3 && !p2 && p1) {Position = 81;}
  if(p8 && p7 && p6 && p5 && !p4 && !p3 && !p2 && p1) {Position = 82;}
  if(p8 && p7 && !p6 && p5 && !p4 && !p3 && !p2 && p1) {Position = 83;}
  if(p8 && p7 && !p6 && !p5 && !p4 && !p3 && !p2 && p1) {Position = 84;}
  if(p8 && p7 && !p6 && !p5 && !p4 && p3 && !p2 && p1) {Position = 85;}
  if(p8 && p7 && !p6 && !p5 && !p4 && p3 && !p2 && !p1) {Position = 86;}
  if(p8 && p7 && !p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Position = 87;}
  if(!p8 && p7 && !p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Position = 88;}
  if(!p8 && p7 && !p6 && !p5 && !p4 && !p3 && p2 && !p1) {Position = 89;}
  if(!p8 && p7 && !p6 && !p5 && p4 && !p3 && p2 && !p1) {Position = 90;}
  if(!p8 && p7 && p6 && !p5 && p4 && !p3 && p2 && !p1) {Position = 91;}
  if(!p8 && p7 && p6 && p5 && p4 && !p3 && p2 && !p1) {Position = 92;}
  if(!p8 && p7 && p6 && p5 && p4 && !p3 && !p2 && !p1) {Position = 93;}
  if(!p8 && p7 && p6 && p5 && p4 && !p3 && !p2 && p1) {Position = 94;}
  if(!p8 && p7 && p6 && p5 && p4 && p3 && !p2 && p1) {Position = 95;}
  if(p8 && p7 && p6 && p5 && p4 && p3 && !p2 && p1) {Position = 96;}
  if(p8 && p7 && p6 && p5 && p4 && p3 && !p2 && !p1) {Position = 97;}
  if(p8 && p7 && p6 && p5 && p4 && !p3 && !p2 && !p1) {Position = 98;}
  if(p8 && p7 && p6 && !p5 && p4 && !p3 && !p2 && !p1) {Position = 99;}
  if(p8 && p7 && p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Position = 100;}
  if(p8 && p7 && p6 && !p5 && !p4 && !p3 && p2 && !p1) {Position = 101;}
  if(!p8 && p7 && p6 && !p5 && !p4 && !p3 && p2 && !p1) {Position = 102;}
  if(!p8 && p7 && p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Position = 103;}
  if(!p8 && !p7 && p6 && !p5 && !p4 && !p3 && !p2 && !p1) {Position = 104;}
  if(!p8 && !p7 && p6 && !p5 && !p4 && !p3 && !p2 && p1) {Position = 105;}
  if(!p8 && !p7 && p6 && !p5 && !p4 && p3 && !p2 && p1) {Position = 106;}
  if(!p8 && !p7 && p6 && p5 && !p4 && p3 && !p2 && p1) {Position = 107;}
  if(!p8 && !p7 && p6 && p5 && p4 && p3 && !p2 && p1) {Position = 108;}
  if(!p8 && !p7 && p6 && p5 && p4 && p3 && !p2 && !p1) {Position = 109;}
  if(p8 && !p7 && p6 && p5 && p4 && p3 && !p2 && !p1) {Position = 110;}
  if(p8 && !p7 && p6 && p5 && p4 && p3 && p2 && !p1) {Position = 111;}
  if(p8 && p7 && p6 && p5 && p4 && p3 && p2 && !p1) {Position = 112;}
  if(!p8 && p7 && p6 && p5 && p4 && p3 && p2 && !p1) {Position = 113;}
  if(!p8 && p7 && p6 && p5 && p4 && p3 && !p2 && !p1) {Position = 114;}
  if(!p8 && p7 && p6 && p5 && !p4 && p3 && !p2 && !p1) {Position = 115;}
  if(!p8 && p7 && p6 && p5 && !p4 && !p3 && !p2 && !p1) {Position = 116;}
  if(!p8 && p7 && p6 && p5 && !p4 && !p3 && !p2 && p1) {Position = 117;}   
  if(!p8 && !p7 && p6 && p5 && !p4 && !p3 && !p2 && p1) {Position = 118;}   
  if(!p8 && !p7 && p6 && p5 && !p4 && !p3 && !p2 && !p1) {Position = 119;} 
  if(!p8 && !p7 && !p6 && p5 && !p4 && !p3 && !p2 && !p1) {Position = 120;} 
  if(p8 && !p7 && !p6 && p5 && !p4 && !p3 && !p2 && !p1) {Position = 121;}
  if(p8 && !p7 && !p6 && p5 && !p4 && !p3 && p2 && !p1) {Position = 122;}
  if(p8 && !p7 && !p6 && p5 && p4 && !p3 && p2 && !p1) {Position = 123;}
  if(p8 && !p7 && !p6 && p5 && p4 && p3 && p2 && !p1) {Position = 124;}
  if(!p8 && !p7 && !p6 && p5 && p4 && p3 && p2 && !p1) {Position = 125;}
  if(!p8 && p7 && !p6 && p5 && p4 && p3 && p2 && !p1) {Position = 126;}
  if(!p8 && p7 && !p6 && p5 && p4 && p3 && p2 && p1) {Position = 127;}
}

if(mess) //IST bereschnen ...
{
left = 106; //Position bei Rechtsanschlag
  if (Position >= left)
  {IST = Position - left;}

  if (Position >= 0 && Position < left)
  {IST = Position + (127 - left);}

  IST = IST * 100 / 110;
}

  Serial.print("IST:");
  Serial.print(IST);
  Serial.print("    SOLL:");
  Serial.println(SOLL);



  if (SOLL == IST){
 
  digitalWrite(10 , LOW);
  digitalWrite(11 , LOW);
  digitalWrite(12 , LOW);
  digitalWrite(13 , LOW);
  }  



if (SOLL != IST)
{
  if (SOLL > IST) { 
  myStepper.step(1*(SOLL - IST));
  }
  

  if (SOLL < IST) { 
  myStepper.step(1*(SOLL - IST));
  }

  if (SOLL == IST){
 
  digitalWrite(10 , LOW);
  digitalWrite(11 , LOW);
  digitalWrite(12 , LOW);
  digitalWrite(13 , LOW);
}
}
}



