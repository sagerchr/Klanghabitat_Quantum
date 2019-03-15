#include <Encoder.h>


int zeit = 5000;
int POSITION = 0;
int   EncValue1 = 0;
int   EncValueLast1 = 0;
int   Position = 0;
Encoder encoder1(2, 3);

void setup() {
  // set the slaveSelectPin as an output:
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
     
     EncValue1 = encoder1.read()/4;
     
     if (EncValue1 > EncValueLast1) {Position = Position + 1;} 
     if (EncValue1 < EncValueLast1) {Position = Position - 1;} 
     
     if (Position >=15) {Position = 15;}
     if (Position <=0) {Position = 0;}
     EncValueLast1 = EncValue1;
     Serial.print(Position);
      
  switch (Position)
  {
    case 0:   {digitalWrite (8, LOW); digitalWrite (9, LOW); digitalWrite (10, LOW); digitalWrite (11, LOW);} break;
    case 1:   {digitalWrite (8, HIGH); digitalWrite (9, LOW); digitalWrite (10, LOW); digitalWrite (11, LOW);}break;
    case 2:   {digitalWrite (8, LOW); digitalWrite (9, HIGH); digitalWrite (10, LOW); digitalWrite (11, LOW);}break;
    case 3:   {digitalWrite (8, HIGH); digitalWrite (9, HIGH); digitalWrite (10, LOW); digitalWrite (11, LOW);}break;
    case 4:   {digitalWrite (8, LOW); digitalWrite (9, LOW); digitalWrite (10, HIGH); digitalWrite (11, LOW);}break;
    case 5:   {digitalWrite (8, HIGH); digitalWrite (9, LOW); digitalWrite (10, HIGH); digitalWrite (11, LOW);}break;
    case 6:   {digitalWrite (8, LOW); digitalWrite (9, HIGH); digitalWrite (10, HIGH); digitalWrite (11, LOW);}break;
    case 7:   {digitalWrite (8, HIGH); digitalWrite (9, HIGH); digitalWrite (10, HIGH); digitalWrite (11, LOW);}break;
    case 8:   {digitalWrite (8, LOW); digitalWrite (9, LOW); digitalWrite (10, LOW); digitalWrite (11, HIGH);}break;
    case 9:   {digitalWrite (8, HIGH); digitalWrite (9, LOW); digitalWrite (10, LOW); digitalWrite (11, HIGH);}break;
    case 10:  {digitalWrite (8, LOW); digitalWrite (9, HIGH); digitalWrite (10, LOW); digitalWrite (11, HIGH);}break;
    case 11:  {digitalWrite (8, HIGH); digitalWrite (9, HIGH); digitalWrite (10, LOW); digitalWrite (11, HIGH);}break;
    case 12:  {digitalWrite (8, LOW); digitalWrite (9, LOW); digitalWrite (10, HIGH); digitalWrite (11, HIGH);}break;
    case 13:  {digitalWrite (8, HIGH); digitalWrite (9, LOW); digitalWrite (10, HIGH); digitalWrite (11, HIGH);}break;
    case 14:  {digitalWrite (8, LOW); digitalWrite (9, HIGH); digitalWrite (10, HIGH); digitalWrite (11, HIGH);}break;
    case 15:  {digitalWrite (8, HIGH); digitalWrite (9, HIGH); digitalWrite (10, HIGH); digitalWrite (11, HIGH);}break;
  }
}

