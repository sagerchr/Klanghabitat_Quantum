#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include "AH_MCP320x.h"


#define PIN            53
#define NUMPIXELS      1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int bright=1;

const int right = 2;     
const int stopp = 3;     
int ist=0;
int ist0=0;
int ist1=0;
int ist2=0;
int ist3=0;
int ist4=0;
int ist5=0;

int soll=20;
int i=200;
int tol=0;
int pos=0;
int run_pos=0;
bool match = false;
int t=0;

byte address = 0x00;
byte address2 = 0x10;
int CS= 5;
float DigValue=0;

AH_MCP320x ADC_SPI(6); 

void setup() {
  digitalWrite(A0, INPUT_PULLUP);
  pixels.begin();
  pinMode(right, OUTPUT);
  pinMode(stopp, OUTPUT);
  pinMode (CS, OUTPUT);
  digitalWrite(stopp, LOW); 
  Serial.begin(9600);
  SPI.begin();
  analogReference(DEFAULT);
}

void loop() {
  
pixels.show(); // This sends the updated pixel color to the hardware.
pixels.setPixelColor(0, pixels.Color(255,100,0)); // Gelb oranges Licht
bright=ist;
pixels.setBrightness(bright);

//pos = 60;

if (pos == 0){run_pos=0;}
if (pos == 1){run_pos=1;}
if (pos == 2){run_pos=3;}
if (pos == 3){run_pos=5;}
if (pos == 4){run_pos=9;}
if (pos == 5){run_pos=20;}
if (pos == 6){run_pos=30;}
if (pos == 7){run_pos=50;}
if (pos == 8){run_pos=70;}
if (pos == 9){run_pos=90;}
if (pos == 10){run_pos=110;}

if (pos == 11){run_pos=140;}
if (pos == 12){run_pos=200;}
if (pos == 13){run_pos=300;}
if (pos == 14){run_pos=400;}
if (pos == 15){run_pos=500;}
if (pos == 16){run_pos=600;}
if (pos == 17){run_pos=700;}
if (pos == 18){run_pos=800;}
if (pos == 19){run_pos=900;}
if (pos == 20){run_pos=1000;}

if (pos == 21){run_pos=1100;}
if (pos == 22){run_pos=1200;}
if (pos == 23){run_pos=1300;}
if (pos == 24){run_pos=1400;}
if (pos == 25){run_pos=1500;}
if (pos == 26){run_pos=1600;}
if (pos == 27){run_pos=1700;}
if (pos == 28){run_pos=1800;}
if (pos == 29){run_pos=1900;}
if (pos == 30){run_pos=2000;}

if (pos == 31){run_pos=2100;}
if (pos == 32){run_pos=2200;}
if (pos == 33){run_pos=2300;}
if (pos == 34){run_pos=2400;}
if (pos == 35){run_pos=2500;}
if (pos == 36){run_pos=2600;}
if (pos == 37){run_pos=2700;}
if (pos == 38){run_pos=2800;}
if (pos == 39){run_pos=2900;}
if (pos == 40){run_pos=3000;}

if (pos == 41){run_pos=3100;}
if (pos == 41){run_pos=3200;}
if (pos == 42){run_pos=3300;}
if (pos == 43){run_pos=3400;}
if (pos == 44){run_pos=3500;}
if (pos == 45){run_pos=3600;}
if (pos == 46){run_pos=3700;}
if (pos == 47){run_pos=3830;}
if (pos == 48){run_pos=3860;}
if (pos == 49){run_pos=3920;}
if (pos == 50){run_pos=4000;}

if (pos == 51){run_pos=4010;}
if (pos == 52){run_pos=4030;}
if (pos == 53){run_pos=4040;}
if (pos == 54){run_pos=4050;}
if (pos == 55){run_pos=4060;}
if (pos == 56){run_pos=4070;}
if (pos == 57){run_pos=4080;}
if (pos == 58){run_pos=4090;}
//if (pos == 59){run_pos=4094;}
if (pos == 60){run_pos=4094;}

pot (run_pos, !match);
//pot (run_pos,true);
//pot (i,!match);


    Serial.print("  MATCH: ");
    Serial.print(match);
    Serial.print("  pos: ");
    Serial.println(pos);

if (match == true)
  {
  delay(300);
  pos=pos+10;
  match =false;
  }

if(pos == 70){pos=0;}



}

/*Motor Poti auslesen, steuern und an digitales Poti IST-Wert übermitteln*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void pot (int soll, bool active) 
{

for(int t = 0; t <= 5;t++)
{ 
if(t==0){ist0 = ADC_SPI.readCH(0);}
if(t==1){ist1 = ADC_SPI.readCH(0);}
if(t==2){ist2 = ADC_SPI.readCH(0);} 
if(t==3){ist3 = ADC_SPI.readCH(0);}
if(t==4){ist4 = ADC_SPI.readCH(0);}
if(t==5){ist5 = ADC_SPI.readCH(0);}
}
ist=(ist0+ist1+ist2+ist3+ist4+ist5)/6;




if(soll >= 4060)
{tol=0;}   
if(soll > 3850 && soll <= 4060)
{tol=5;}  
if(soll > 200 && soll <= 3850)
{tol=20;}  
if(soll > 10 && soll <= 200)
{tol=5;}
if(soll<= 10)
{tol=0;}
  
/*********************analog Poti Position ermitteln*********************/   
/*ist0 = ADC_SPI.readCH(0);
ist1 = ADC_SPI.readCH(0);
ist2 = ADC_SPI.readCH(0);
ist3 = ADC_SPI.readCH(0);
ist=((ist0+ist1+ist2+ist3)/4)/1;
//ist = ((analogRead(A1)-0)/1); // Wert am analogen Poti ermitteln
/*******************Werte an digitales Poti übertragen*******************/
    digitalWrite(CS, LOW);
    SPI.transfer(address);
    SPI.transfer(256-(ist*2));
    digitalWrite(CS, HIGH);


    Serial.print("ist: ");
    Serial.print(ist);

    Serial.print("soll: ");
    Serial.print(soll);
/******************Poti in Position fahren*****************************/
      if(((ist >= soll - tol) && (ist <= soll + tol)) || (ist == soll))
      {
      digitalWrite(stopp, LOW); //stoppen
      match = true;
      active = false;
      }
/******************************left*************************************/
    if(ist > soll && active == true) 
      {
      digitalWrite(right, HIGH); //links
      digitalWrite(stopp, HIGH); //fahren
      match = false;
      
      }
      if(((ist >= soll - tol) && (ist <= soll + tol)) || (ist == soll))
      {
      
      //if(soll == 0 && ist <= 2){delay(500);} //stoppen verzögern  
      
      digitalWrite(stopp, LOW); //stoppen
      match = true;
      active = false;
      }
/******************************right************************************/  
    if(ist < soll && active == true) 
      {
      digitalWrite(right, LOW);  //rechts
      digitalWrite(stopp, HIGH); //fahren
      match = false;
      }
      if(((ist >= soll - tol) && (ist <= soll + tol)) || (ist == soll))
      {
      digitalWrite(stopp, LOW); //stoppen
      match = true;
      active = false;
      }
    
    Serial.print("  active: ");
    Serial.print(active);  
  
}   
