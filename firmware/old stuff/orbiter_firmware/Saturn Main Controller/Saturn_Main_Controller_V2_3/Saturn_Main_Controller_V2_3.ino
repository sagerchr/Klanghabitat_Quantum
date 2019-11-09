#include "AH_MCP4922.h"
//#include <MIDI.h>
//IDI_CREATE_DEFAULT_INSTANCE();
const int bSize = 6; //Größe der PotAnswer
byte Buffer[bSize];
int CHANNEL_MIDI = 1;
AH_MCP4922 AnalogOutput1(51, 52, 8, LOW, HIGH); //define AnalogOutput1 for MEGA_board, select DAC_A, Gain=1x
AH_MCP4922 AnalogOutput2(51, 52, 8, HIGH, HIGH);
int CCnumber = 255;
int CCvalue = 255;
int buzzerPin = 9;
int incomingByte = 0; 
const int bSize2 = 5; //Größe der Nachricht
byte Buffer2[bSize2];

/*                       [0]    [1]   [2]   [3]   [4]   [5]   [6]   [7]   [8]   [9]  [10]  [11]  [12]  [13]  [14]  [15]  [16]  [17]  [18]  [19]  [20]  [21]  [22]  [23]  [24]  [25]  [26]  [27]  [28]
  /***********************{Pot,listen, Mode, Val1, Val2, Val3, Val4, S1.1, S2.1, S3.1, S1.2  S2.2, S3.2, S1.3, S2.3, S3.3, S1.4, S2.4, S3.4, S1.5, S2.5, S3.5, S1.6, S2.6, S3.6, S3.4, S4.4, CMD,  END}***/
byte PotStream0[] =     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream1[] =     {0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream2[] =     {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream3[] =     {0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream4[] =     {0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};

void setup()
{
  delay(0); //Verszögerung damit alle Pots gebootet sind
  
  SerialUSB.begin(57600); //Komunikation zu NANO_POT
  Serial3.begin(57600);
  Serial2.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(15, INPUT_PULLUP);
 // MIDI.begin();
 // MIDI.turnThruOff();
  Buffer [0] = 0xFF;
  
  pinMode(buzzerPin, OUTPUT);
  
  delay(100);

  Serial3.write(PotStream0, sizeof(PotStream0));
  delay(10);
  Serial3.write(PotStream1, sizeof(PotStream1));
  delay(10);
  Serial3.write(PotStream2, sizeof(PotStream2));
  delay(10);
  Serial3.write(PotStream3, sizeof(PotStream3));
  delay(10);
  Serial3.write(PotStream4, sizeof(PotStream4));
  delay(10);
digitalWrite(LED_BUILTIN, LOW);

}


byte PotStream0Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream1Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream2Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream3Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
byte PotStream4Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};

bool SendStream0 = true;
bool SendStream1 = true;
bool SendStream2 = true;
bool SendStream3 = true;
bool SendStream4 = true;

bool timerset0 = true;
float timer0 = 0;
float timer0start = millis();

bool timerset1 = true;
float timer1 = 0;
float timer1start = millis();

bool timerset2 = true;;
float timer2 = 0;
float timer2start = millis();

bool timerset3 = true;
float timer3 = 0;
float timer3start = millis();

bool timerset4 = true;
float timer4 = 0;
float timer4start = millis();


float blinkies = 0;
float blinkieslast = 0;

float sendwait = 50;

int POT_STREAM = 0;
float Millis = 0;
float Millislast = 0;
float samplerlast = 0;

float sampler = 0;

float sample = 0;

bool streaminterrupt0 = false;
bool streaminterrupt1 = false;
bool streaminterrupt2 = false;
bool streaminterrupt3 = false;
bool streaminterrupt4 = false;
int CCnumber_last = 254;
int CCvalue_last = 254;

bool MODECHANGE_BEEP = true;
int MODEFREQ = 600;

bool startsample = 1;

int arraycount = 0;
int counting = 0;

bool blinker = false;
void loop()
{
/*
  delay (5000);
  RSTC->RSTC_CR = 0xA5000005; // Reset processor and internal peripherals
  /*****************MIDI Input aufnehemen und in Potstream übernehmen******************************/
/*
  if (MIDI.read())
  {
    CCnumber  =   MIDI.getData1();
    CCvalue   =   MIDI.getData2();

    if ((CCnumber != CCnumber_last && CCvalue != CCvalue_last) || ((CCnumber != CCnumber_last && CCvalue != CCvalue_last + 2)) || ((CCnumber != CCnumber_last && CCvalue != CCvalue_last - 2)))
    {
      if (CCnumber >= 00 && CCnumber <= 7 ) {
        PotStream0[CCnumber + 3]  = CCvalue;
        PotStream0[27] = 0x01;
        timerset0 = true;
        timer0start = millis();
        SendStream0 = false;
        Serial3.write(PotStream0, sizeof(PotStream0));
        Serial3.flush();
        delay (0);
        streaminterrupt0 = true;
      }
      if (CCnumber >= 10 && CCnumber <= 17) {
        PotStream1[CCnumber - 7]  = CCvalue;
        PotStream1[27] = 0x01;
        timerset1 = true;
        timer1start = millis();
        SendStream1 = false;
        Serial3.write(PotStream1, sizeof(PotStream1));
        Serial3.flush();
        delay (0);
        streaminterrupt1 = true;
      }
      if (CCnumber >= 20 && CCnumber <= 27) {
        PotStream2[CCnumber - 17] = CCvalue;
        PotStream2[27] = 0x01;
        timerset2 = true;
        timer2start = millis();
        SendStream2 = false;
        Serial3.write(PotStream2, sizeof(PotStream2));
        Serial3.flush();
        delay (0);
        streaminterrupt2 = true;
      }
      if (CCnumber >= 30 && CCnumber <= 37) {
        PotStream3[CCnumber - 27] = CCvalue;
        PotStream3[27] = 0x01;
        timerset3 = true;
        timer3start = millis();
        SendStream3 = false;
        Serial3.write(PotStream3, sizeof(PotStream3));
        Serial3.flush();
        delay (0);
        streaminterrupt3 = true;
      }
      if (CCnumber >= 40 && CCnumber <= 47) {
        PotStream4[CCnumber - 37] = CCvalue;
        PotStream4[27] = 0x01;
        timerset4 = true;
        timer4start = millis();
        SendStream4 = false;
        Serial3.write(PotStream4, sizeof(PotStream4));
        Serial3.flush();
        delay (0);
        streaminterrupt4 = true;
      }
    }

  }


  
  /**************************************STREAM senden**********************************************/
  
    if (SerialUSB.available() > 0)
  {
   incomingByte = SerialUSB.read();
   //Serial2.write(incomingByte);
        PotStream0[3]  = incomingByte;
        PotStream0[27] = 0x01;
        timerset0 = true;
        timer0start = millis();
        SendStream0 = false;
        Serial3.write(PotStream0, sizeof(PotStream0));
        Serial3.flush();
        digitalWrite(LED_BUILTIN, HIGH);
  }
  digitalWrite(LED_BUILTIN, LOW);

  
 blinkies = millis()-blinkieslast;
 if (blinkies > 500)
  {
  blinker = !blinker;
  digitalWrite(LED_BUILTIN, blinker);
  blinkieslast = millis(); 
 }
  
  Millis = millis() - Millislast;
  if (Millis >= 8) //Sendeverzögerung
  {
    switch (POT_STREAM)
    {
      case 0: {
          if (streaminterrupt0 == false) {
            Serial3.write(PotStream0, sizeof(PotStream0));
            //Serial3.flush();
            delay(0);
          } POT_STREAM = 1;
         // AnalogOutput1 .setValue(1 * ((PotStream0[3]) + 900));
        } break;
      case 1: {
          if (streaminterrupt1 == false) {
            Serial3.write(PotStream1, sizeof(PotStream1));
            //Serial3.flush();
            delay(0);
          } POT_STREAM = 2;
         // AnalogOutput2.setValue(1 * ((2 * (PotStream2[3])) + 900));
        } break;
      case 2: {
          if (streaminterrupt2 == false) {
            Serial3.write(PotStream2, sizeof(PotStream2));
            //Serial3.flush();
            delay(0);
          } POT_STREAM = 3;
        } break;
      case 3: {
          if (streaminterrupt3 == false) {
            Serial3.write(PotStream3, sizeof(PotStream3));
            //Serial3.flush();
            delay(0);
          } POT_STREAM = 4;
        } break;
      case 4: {
          if (streaminterrupt4 == false) {
            Serial3.write(PotStream4, sizeof(PotStream4));
            //Serial3.flush();
            delay(0);
          } POT_STREAM = 0;
        } break;
    }
    Millislast = millis();
    samplerlast = millis();
    startsample = 1;
    arraycount = 0;
  }


  /***********************Wenn CMD auf 0x01 in einem Stream geht senden unterbinden x ms***********/
  
  if (timerset0 == true) {
    timer0 = millis() - timer0start;
  }
  if (PotStream0 [27] == 0x01 && timer0 > sendwait) {
    PotStream0 [27] = 0x00;
    SendStream0 = true;
    timerset0 = false;
  }

  if (timerset1 == true) {
    timer1 = millis() - timer1start;
  }
  if (PotStream1 [27] == 0x01 && timer1 > sendwait) {
    PotStream1 [27] = 0x00;
    SendStream1 = true;
    timerset1 = false;
  }

  if (timerset2 == true) {
    timer2 = millis() - timer2start;
  }
  if (PotStream2 [27] == 0x01 && timer2 > sendwait) {
    PotStream2 [27] = 0x00;
    SendStream2 = true;
    timerset2 = false;
  }

  if (timerset3 == true) {
    timer3 = millis() - timer3start;
  }
  if (PotStream3 [27] == 0x01 && timer3 > sendwait) {
    PotStream3 [27] = 0x00;
    SendStream3 = true;
    timerset3 = false;
  }

  if (timerset4 == true) {
    timer4 = millis() - timer4start;
  }
  if (PotStream4 [27] == 0x01 && timer4 > sendwait) {
    PotStream4 [27] = 0x00;
    SendStream4 = true;
    timerset4 = false;
  }

 
/*
    for (int i = 0; i < 64; i++)
    {
      delay (10);
      SerialUSB.println(i);
    }
*/ 



   
  /*******************************Buffer des Input Streams aufnehmen********************************/
  if (Serial3.available() > 0)
  {
    Serial3.readBytesUntil(0xFF, Buffer, bSize);
  }


  if (Buffer [0] == 0 && SendStream0 == true) /*Pot0 Kommunikation*********************************************************/
  {

    if (PotStream0Last [2] != PotStream0 [2] && MODECHANGE_BEEP == true) {
   
    }
    /***************************PotStreamLast merken************************************/
    for (int i = 0; i < 13; i++)
    {
      PotStream0Last [i] = PotStream0 [i];
    }
    /**********************************************************************************/

    /**************************UPDATE POTSREAM*****************************************/
    PotStream0 [0] = Buffer [0];            //PotNumber
    PotStream0 [1] = Buffer [1];            //Listen des POTS
    PotStream0 [2] = Buffer [2];            //Mode des POTS
    PotStream0 [Buffer [2] + 3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
    /**********************************************************************************/

    /***************************Je nach Mode Wert senden*******************************/
    for (int i = 3; i < 13; i++)
    {
      if (PotStream0Last [i] != PotStream0 [i] && SendStream0)
      {
        counting++;
        //MIDI.sendControlChange(PotStream0[2] + 0, PotStream0[PotStream0[2] + 3], CHANNEL_MIDI);
        SerialUSB.println(PotStream0[PotStream0[2] + 3]);   
      }
    }

    /**********************************************************************************/
  }

  if (Buffer [0] == 1 && SendStream1 == true) /*Pot1 Kommunikation*********************************************************/
  {
    if (PotStream1Last [2] != PotStream1 [2] && MODECHANGE_BEEP == true) {
    
    }
    /***************************PotStreamLast merken************************************/
    for (int i = 0; i < 13; i++)
    {
      PotStream1Last [i] = PotStream1 [i];
    }
    /**********************************************************************************/

    /**************************UPDATE POTSREAM*****************************************/
    PotStream1 [0] = Buffer [0];            //PotNumber
    PotStream1 [1] = Buffer [1];            //Listen des POTS
    PotStream1 [2] = Buffer [2];            //Mode des POTS
    PotStream1 [Buffer [2] + 3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
    /**********************************************************************************/

    /***************************Je nach Mode Wert senden*******************************/
    for (int i = 3; i < 13; i++)
    {
      if (PotStream1Last [i] != PotStream1 [i] && SendStream1)
      {
        //MIDI.sendControlChange(PotStream1[2] + 10, PotStream1[PotStream1[2] + 3], CHANNEL_MIDI);
       
     
      }
    }

    /**********************************************************************************/
  }

  if (Buffer [0] == 2 && SendStream2 == true) /*Pot2 Kommunikation*********************************************************/
  {
    if (PotStream2Last [2] != PotStream2 [2] && MODECHANGE_BEEP == true) {
     
    }
    /***************************PotStreamLast merken************************************/
    for (int i = 0; i < 13; i++)
    {
      PotStream2Last [i] = PotStream2 [i];
    }
    /**********************************************************************************/

    /**************************UPDATE POTSREAM*****************************************/
    PotStream2 [0] = Buffer [0];            //PotNumber
    PotStream2 [1] = Buffer [1];            //Listen des POTS
    PotStream2 [2] = Buffer [2];            //Mode des POTS
    PotStream2 [Buffer [2] + 3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
    /**********************************************************************************/

    /***************************Je nach Mode Wert senden*******************************/
    for (int i = 3; i < 13; i++)
    {
      if (PotStream2Last [i] != PotStream2 [i] && SendStream2)
      {
        //MIDI.sendControlChange(PotStream2[2] + 20, PotStream2[PotStream2[2] + 3], CHANNEL_MIDI);

      }
    }

    /**********************************************************************************/
  }

  if (Buffer [0] == 3 && SendStream3 == true) /*Pot3 Kommunikation*********************************************************/
  {
    if (PotStream3Last [2] != PotStream3 [2] && MODECHANGE_BEEP == true) {
      
    }
    /***************************PotStreamLast merken************************************/
    for (int i = 0; i < 13; i++)
    {
      PotStream3Last [i] = PotStream3 [i];
    }
    /**********************************************************************************/

    /**************************UPDATE POTSREAM*****************************************/
    PotStream3 [0] = Buffer [0];            //PotNumber
    PotStream3 [1] = Buffer [1];            //Listen des POTS
    PotStream3 [2] = Buffer [2];            //Mode des POTS
    PotStream3 [Buffer [2] + 3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
    /**********************************************************************************/

    /***************************Je nach Mode Wert senden*******************************/
    for (int i = 3; i < 13; i++)
    {
      if (PotStream3Last [i] != PotStream3 [i] && SendStream3)
      {
        //MIDI.sendControlChange(PotStream3[2] + 30, PotStream3[PotStream3[2] + 3], CHANNEL_MIDI);

      }
    }

    /**********************************************************************************/
  }

  if (Buffer [0] == 4 && SendStream4 == true) /*Pot4 Kommunikation*********************************************************/
  {
    if (PotStream4Last [2] != PotStream4 [2] && MODECHANGE_BEEP == true) {
    }
    /***************************PotStreamLast merken************************************/
    for (int i = 0; i < 13; i++)
    {
      PotStream4Last [i] = PotStream4 [i];
    }
    /**********************************************************************************/

    /**************************UPDATE POTSREAM*****************************************/
    PotStream4 [0] = Buffer [0];            //PotNumber
    PotStream4 [1] = Buffer [1];            //Listen des POTS
    PotStream4 [2] = Buffer [2];            //Mode des POTS
    PotStream4 [Buffer [2] + 3] = Buffer [3]; //Value je nach Mode in PotStream übernehmen
    /**********************************************************************************/

    /***************************Je nach Mode Wert senden*******************************/
    for (int i = 3; i < 13; i++)
    {
      if (PotStream4Last [i] != PotStream4 [i] && SendStream4)
      {
        //MIDI.sendControlChange(PotStream4[2] + 40, PotStream4[PotStream4[2] + 3], CHANNEL_MIDI);
       
      }
    }

    /**********************************************************************************/
  }

  streaminterrupt0 = false;
  streaminterrupt1 = false;
  streaminterrupt2 = false;
  streaminterrupt3 = false;
  streaminterrupt4 = false;
/*
  sampler = millis() - samplerlast;
  if (sampler >= 1 || startsample)
  {
    samplerlast = millis();
    startsample = 0;

    //sample = ((analogRead(A5)))*2.2*1000;
    sample = ((analogRead(A7)));
    if (sample < 90 && sample >= 0) {
      sample = 0;
    }
    if (sample < 100 && sample >= 90) {
      sample = 1;
    }
    if (sample < 122 && sample >= 100) {
      sample = 2;
    }
    if (sample < 137 && sample >= 122) {
      sample = 3;
    }
    if (sample < 154 && sample >= 137) {
      sample = 4;
    }
    if (sample < 173 && sample >= 154) {
      sample = 5;
    }
    if (sample < 194 && sample >= 173) {
      sample = 6;
    }
    if (sample < 218 && sample >= 194) {
      sample = 7;
    }
    if (sample < 244 && sample >= 218) {
      sample = 8;
    }
    if (sample < 274 && sample >= 244) {
      sample = 9;
    }
    if (sample < 308 && sample >= 274) {
      sample = 10;
    }
    if (sample < 346 && sample >= 308) {
      sample = 11;
    }
    if (sample < 388 && sample >= 346) {
      sample = 12;
    }
    if (sample < 435 && sample >= 388) {
      sample = 13;
    }
    if (sample < 488 && sample >= 435) {
      sample = 14;
    }
    if (sample < 548 && sample >= 488) {
      sample = 15;
    }
    if (sample < 615 && sample >= 548) {
      sample = 16;
    }
    if (sample < 690 && sample >= 615) {
      sample = 17;
    }
    if (sample < 774 && sample >= 690) {
      sample = 18;
    }
    if (sample < 1024 && sample >= 774) {
      sample = 19;
    }
    PotStream0[arraycount + 8] = sample;
    PotStream1[arraycount + 8] = sample;
    PotStream2[arraycount + 8] = sample;
    PotStream3[arraycount + 8] = sample;
    PotStream4[arraycount + 8] = sample;
    arraycount++;
  }

*/

}
