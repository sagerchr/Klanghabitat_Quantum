     /*
  Multiple Serial test

  Receives from the main serial port, sends to the others.
  Receives from serial port 1, sends to the main serial (Serial 0).

  This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc.

  The circuit:
  - any serial device attached to Serial port 1
  - Serial Monitor open on Serial port 0

  created 30 Dec 2008
  modified 20 May 2012
  by Tom Igoe & Jed Roach
  modified 27 Nov 2015
  by Arturo Guadalupi

  This example code is in the public domain.
*/
int incomingByte = 0;
int incomingByteLast = 0;
int count = 0;
void setup() {
  // initialize both serial ports:
  Serial.begin(57600); //Komunikation zu PlugIN
  //Serial.begin(9600);
  Serial1.begin(200000);
  Serial3.begin(9600); //Debugger
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

int i = 0;
void loop() {

   if (Serial.available() > 0)
  {
   incomingByte = Serial.read();

   if(incomingByte > incomingByteLast){
     count = incomingByteLast - incomingByte;

     for (int i = incomingByteLast; i <= incomingByte; i++){
      Serial1.write(i);
      Serial3.write(i);
      delay(2);
     }    
   }


      if(incomingByte < incomingByteLast){
     count = incomingByte - incomingByteLast;

     for (int i = incomingByteLast; i >= incomingByte; i--){
      Serial1.write(i);
      Serial3.write(i);
      delay(2);
     }    
   }

   incomingByteLast = incomingByte;

   digitalWrite(LED_BUILTIN, HIGH);
  }
   digitalWrite(LED_BUILTIN, LOW);
 
}
