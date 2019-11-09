#include <math.h> 
#include "AH_MCP4922.h"

void setup() {
  
AH_MCP4922 AnalogOutput1(51, 52, 8, LOW, HIGH); 
AH_MCP4922 AnalogOutput2(51, 52, 8, HIGH, HIGH);
AnalogOutput1 .setValue(1 * (100 + 900));
AnalogOutput2 .setValue(1 * (100+ 900));
Serial3.begin(57600); //Komunikation zu NANO_POT
analogReference(INTERNAL1V1);
}

byte PotStream0[] =     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};

float Millis = 0;
float Millislast = 0;

float sampler = 0;
float samplerlast = 0;

bool startsample = 0;

int arraycount = 0;

float sample =0;
int sample2 =0;
void loop() {

/************Senden des Streams********************/
  Millis = millis() - Millislast;
  if (Millis >= 5) //Sendeverzögerung 
  {
   Millislast = millis();
   samplerlast = millis();
   Serial3.write(PotStream0, sizeof(PotStream0));
   Serial3.flush();
   startsample = 1;
   arraycount = 0;
   }
/*************************************************/


  sampler = millis() - samplerlast;
  if (sampler >= 1 || startsample)
  {
    samplerlast = millis();
    startsample = 0;
    
    //sample = ((analogRead(A5)))*2.2*1000;
    sample = ((analogRead(A7)));
    if(sample<90 && sample>=0){sample = 0;}
    if(sample<100 && sample>=90){sample = 1;}
    if(sample<122 && sample>=100){sample = 2;}  
    if(sample<137 && sample>=122){sample = 3;}  
    if(sample<154 && sample>=137){sample = 4;}  
    if(sample<173 && sample>=154){sample = 5;}  
    if(sample<194 && sample>=173){sample = 6;}
    if(sample<218 && sample>=194){sample = 7;}
    if(sample<244 && sample>=218){sample = 8;}
    if(sample<274 && sample>=244){sample = 9;}
    if(sample<308 && sample>=274){sample = 10;}
    if(sample<346 && sample>=308){sample = 11;}
    if(sample<388 && sample>=346){sample = 12;}
    if(sample<435 && sample>=388){sample = 13;}
    if(sample<488 && sample>=435){sample = 14;}
    if(sample<548 && sample>=488){sample = 15;}
    if(sample<615 && sample>=548){sample = 16;}
    if(sample<690 && sample>=615){sample = 17;}
    if(sample<774 && sample>=690){sample = 18;}
    if(sample<1024 && sample>=774){sample = 19;}
    PotStream0[arraycount]=sample;
    arraycount++;
  }

   
   
}
