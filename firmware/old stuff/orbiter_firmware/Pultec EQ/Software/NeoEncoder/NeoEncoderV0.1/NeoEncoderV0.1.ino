#include <Encoder.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel LED1 = Adafruit_NeoPixel(4, 6, NEO_GRB + NEO_KHZ800);
Encoder encoder1(2, 3);

void setup() 
{
  LED1.begin();
  Serial.begin(9600);
}


int   Possi = 0;



bool  Button1 = false;
int   EncValue1 = 0;
int   EncValueLast1 = 0;
int   EncValuePushed1 = 0;
int   EncValueLastPushed1 = 0;
int   Position = 0;
int   B = 20; 

void loop() 
{

Possi = encoderweel1 (0);  
Serial.println(Possi);
}

int encoderweel1 (int Button1Pin)
{
  Button1 = digitalRead (Button1Pin);

  if(Button1 == HIGH)
    {  
     EncValue1 = encoder1.read()/4;
     if (EncValue1 > EncValueLast1) {Position = Position + 1;} 
     if (EncValue1 < EncValueLast1) {Position = Position - 1;} 
     EncValueLast1 = EncValue1;
     if (Position >=3) {Position = 3;}
     if (Position <=0) {Position = 0;}
     switch (Position)
      {
      case 0: {LED1.setPixelColor(0, LED1.Color(B,B,B)); LED1.setPixelColor(1, LED1.Color(0,0,0)); LED1.setPixelColor(2, LED1.Color(0,0,0)); LED1.setPixelColor(3, LED1.Color(0,0,0));} break;
      case 1: {LED1.setPixelColor(0, LED1.Color(0,0,0)); LED1.setPixelColor(1, LED1.Color(B,B,B)); LED1.setPixelColor(2, LED1.Color(0,0,0)); LED1.setPixelColor(3, LED1.Color(0,0,0));} break;
      case 2: {LED1.setPixelColor(0, LED1.Color(0,0,0)); LED1.setPixelColor(1, LED1.Color(0,0,0)); LED1.setPixelColor(2, LED1.Color(B,B,B)); LED1.setPixelColor(3, LED1.Color(0,0,0));} break;
      case 3: {LED1.setPixelColor(0, LED1.Color(0,0,0)); LED1.setPixelColor(1, LED1.Color(0,0,0)); LED1.setPixelColor(2, LED1.Color(0,0,0)); LED1.setPixelColor(3, LED1.Color(B,B,B));} break;
      }
    }
  
  else
    {
     EncValuePushed1 = encoder1.read()/4;
     if (EncValuePushed1 > EncValueLastPushed1) {B = B + 5;} 
     if (EncValuePushed1 < EncValueLastPushed1) {B = B - 5;} 
     EncValueLastPushed1 = EncValuePushed1;
     EncValueLast1 = EncValuePushed1;
     if (B >=50) {B = 50;}
     if (B <=20) {B = 20;}
     LED1.setPixelColor(0, LED1.Color(B,B,B)); LED1.setPixelColor(1, LED1.Color(B,B,B)); LED1.setPixelColor(2, LED1.Color(B,B,B)); LED1.setPixelColor(3, LED1.Color(B,B,B));
    }
      
  LED1.show(); 
  return Position;
}
