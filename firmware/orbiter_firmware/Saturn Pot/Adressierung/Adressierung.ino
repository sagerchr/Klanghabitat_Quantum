/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
#include "Tlc5940.h"
// the setup routine runs once when you press reset:
void setup() {
digitalWrite(7, LOW);
Tlc.init(); 
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);

  if (sensorValue1 >= 3) {Tlc.set(0,200);}
  if (sensorValue1 < 1) {Tlc.set(0,0);}

  if (sensorValue2 >= 3) {Tlc.set(1,200);}
  if (sensorValue2 < 1) {Tlc.set(1,0);}

  if (sensorValue3 >= 3) {Tlc.set(2,200);}
  if (sensorValue3 < 1) {Tlc.set(2,0);}

  if (sensorValue4 >= 3) {Tlc.set(3,200);}
  if (sensorValue4 < 1) {Tlc.set(3,0);}
  
  Tlc.update();
}
