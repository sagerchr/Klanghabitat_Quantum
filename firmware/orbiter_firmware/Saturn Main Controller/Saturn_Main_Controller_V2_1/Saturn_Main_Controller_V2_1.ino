#include "AH_MCP4922.h"
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
const int bSize = 6; //Größe der PotAnswer
byte Buffer[bSize];
int CHANNEL_MIDI = 1;
AH_MCP4922 AnalogOutput1(51, 52, 8, LOW, HIGH); //define AnalogOutput1 for MEGA_board, select DAC_A, Gain=1x
AH_MCP4922 AnalogOutput2(51, 52, 8, HIGH, HIGH);
int CCnumber = 255;
int CCvalue = 255;
int buzzerPin = 9;

/*                       [0]    [1]   [2]   [3]   [4]   [5]   [6]   [7]   [8]   [9]   [10]  [11]
  /***********************{Pot,listen, Mode, Val1, Val2, Val3, Val4, Val5, Val6, Val7, Val8, CMD, END}***/
byte PotStream0[] =     {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream1[] =     {0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream2[] =     {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream3[] =     {0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream4[] =     {0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};

void setup()
{
  Serial3.begin(57600); //Komunikation zu NANO_POT
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(15, INPUT_PULLUP);
  MIDI.begin();
  MIDI.turnThruOff();
  Buffer [0] = 0xFF;
  delay(1000); //Verszögerung damit alle Pots gebootet sind
  pinMode(buzzerPin, OUTPUT);
  for (int i = 700; i < 900; i = i + 20)
  {
    tone(buzzerPin, 450, 10);
    delay(i - 700);
  }
  tone(buzzerPin, 450, 100);
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
  AnalogOutput2.setValue(0);
  AnalogOutput1.setValue(0);

}


byte PotStream0Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream1Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream2Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream3Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};
byte PotStream4Last[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF};

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


float sendwait = 50;

int POT_STREAM = 0;
float Millis = 0;
float Millislast = 0;

bool streaminterrupt0 = false;
bool streaminterrupt1 = false;
bool streaminterrupt2 = false;
bool streaminterrupt3 = false;
bool streaminterrupt4 = false;
int CCnumber_last = 254;
int CCvalue_last = 254;

bool MODECHANGE_BEEP = true;
int MODEFREQ = 600;

void loop()
{
  /*****************MIDI Input aufnehemen und in Potstream übernehmen******************************/

  if (MIDI.read())
  {
    CCnumber  =   MIDI.getData1();
    CCvalue   =   MIDI.getData2();

    if ((CCnumber != CCnumber_last && CCvalue != CCvalue_last) || ((CCnumber != CCnumber_last && CCvalue != CCvalue_last + 2)) || ((CCnumber != CCnumber_last && CCvalue != CCvalue_last - 2)))
    {
      if (CCnumber >= 00 && CCnumber <= 7 ) {
        PotStream0[CCnumber + 3]  = CCvalue;
        PotStream0[11] = 0x01;
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
        PotStream1[11] = 0x01;
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
        PotStream2[11] = 0x01;
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
        PotStream3[11] = 0x01;
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
        PotStream4[11] = 0x01;
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
  Millis = millis() - Millislast;
  if (Millis >= 10) //Sendeverzögerung
  {
    switch (POT_STREAM)
    {
      case 0: {
          if (streaminterrupt0 == false) {
            Serial3.write(PotStream0, sizeof(PotStream0));
            Serial3.flush();
            delay(0);
          } POT_STREAM = 1;
          AnalogOutput1 .setValue(1 * ((PotStream0[3]) + 900));
        } break;
      case 1: {
          if (streaminterrupt1 == false) {
            Serial3.write(PotStream1, sizeof(PotStream1));
            Serial3.flush();
            delay(0);
          } POT_STREAM = 2;
          AnalogOutput2.setValue(1 * ((2 * (PotStream2[3])) + 900));
        } break;
      case 2: {
          if (streaminterrupt2 == false) {
            Serial3.write(PotStream2, sizeof(PotStream2));
            Serial3.flush();
            delay(0);
          } POT_STREAM = 3;
        } break;
      case 3: {
          if (streaminterrupt3 == false) {
            Serial3.write(PotStream3, sizeof(PotStream3));
            Serial3.flush();
            delay(0);
          } POT_STREAM = 4;
        } break;
      case 4: {
          if (streaminterrupt4 == false) {
            Serial3.write(PotStream4, sizeof(PotStream4));
            Serial3.flush();
            delay(0);
          } POT_STREAM = 0;
        } break;
    }
    Millislast = millis();
  }


  /***********************Wenn CMD auf 0x01 in einem Stream geht senden unterbinden x ms***********/
  if (timerset0 == true) {
    timer0 = millis() - timer0start;
  }
  if (PotStream0 [11] == 0x01 && timer0 > sendwait) {
    PotStream0 [11] = 0x00;
    SendStream0 = true;
    timerset0 = false;
  }

  if (timerset1 == true) {
    timer1 = millis() - timer1start;
  }
  if (PotStream1 [11] == 0x01 && timer1 > sendwait) {
    PotStream1 [11] = 0x00;
    SendStream1 = true;
    timerset1 = false;
  }

  if (timerset2 == true) {
    timer2 = millis() - timer2start;
  }
  if (PotStream2 [11] == 0x01 && timer2 > sendwait) {
    PotStream2 [11] = 0x00;
    SendStream2 = true;
    timerset2 = false;
  }

  if (timerset3 == true) {
    timer3 = millis() - timer3start;
  }
  if (PotStream3 [11] == 0x01 && timer3 > sendwait) {
    PotStream3 [11] = 0x00;
    SendStream3 = true;
    timerset3 = false;
  }

  if (timerset4 == true) {
    timer4 = millis() - timer4start;
  }
  if (PotStream4 [11] == 0x01 && timer4 > sendwait) {
    PotStream4 [11] = 0x00;
    SendStream4 = true;
    timerset4 = false;
  }


  /*******************************Buffer des Input Streams aufnehmen********************************/
  if (Serial3.available() > 0)
  {
    Serial3.readBytesUntil(0xFF, Buffer, bSize);
  }


  if (Buffer [0] == 0 && SendStream0 == true) /*Pot0 Kommunikation*********************************************************/
  {

    if (PotStream0Last [2] != PotStream0 [2] && MODECHANGE_BEEP == true) {
      tone(buzzerPin, MODEFREQ, 20);
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
        MIDI.sendControlChange(PotStream0[2] + 0, PotStream0[PotStream0[2] + 3], CHANNEL_MIDI);
        tone(buzzerPin, 100, 5);
      }
    }

    /**********************************************************************************/
  }

  if (Buffer [0] == 1 && SendStream1 == true) /*Pot1 Kommunikation*********************************************************/
  {
    if (PotStream1Last [2] != PotStream1 [2] && MODECHANGE_BEEP == true) {
      tone(buzzerPin, MODEFREQ, 20);
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
        MIDI.sendControlChange(PotStream1[2] + 10, PotStream1[PotStream1[2] + 3], CHANNEL_MIDI);
        tone(buzzerPin, 100, 5);
      }
    }

    /**********************************************************************************/
  }

  if (Buffer [0] == 2 && SendStream2 == true) /*Pot2 Kommunikation*********************************************************/
  {
    if (PotStream2Last [2] != PotStream2 [2] && MODECHANGE_BEEP == true) {
      tone(buzzerPin, MODEFREQ, 20);
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
        MIDI.sendControlChange(PotStream2[2] + 20, PotStream2[PotStream2[2] + 3], CHANNEL_MIDI);
        tone(buzzerPin, 100, 5);
      }
    }

    /**********************************************************************************/
  }

  if (Buffer [0] == 3 && SendStream3 == true) /*Pot3 Kommunikation*********************************************************/
  {
    if (PotStream3Last [2] != PotStream3 [2] && MODECHANGE_BEEP == true) {
      tone(buzzerPin, MODEFREQ, 20);
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
        MIDI.sendControlChange(PotStream3[2] + 30, PotStream3[PotStream3[2] + 3], CHANNEL_MIDI);
        tone(buzzerPin, 100, 5);
      }
    }

    /**********************************************************************************/
  }

  if (Buffer [0] == 4 && SendStream4 == true) /*Pot4 Kommunikation*********************************************************/
  {
    if (PotStream4Last [2] != PotStream4 [2] && MODECHANGE_BEEP == true) {
      tone(buzzerPin, MODEFREQ, 20);
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
        MIDI.sendControlChange(PotStream4[2] + 40, PotStream4[PotStream4[2] + 3], CHANNEL_MIDI);
        tone(buzzerPin, 100, 5);
      }
    }

    /**********************************************************************************/
  }

  streaminterrupt0 = false;
  streaminterrupt1 = false;
  streaminterrupt2 = false;
  streaminterrupt3 = false;
  streaminterrupt4 = false;

}
