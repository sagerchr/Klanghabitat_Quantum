#include "Tlc5940.h"
#include <Encoder.h>
Encoder encoder1(4, 2);
void setup() {
  digitalWrite(7, LOW);
  Tlc.clear();
  Tlc.init();
  delay(100);

  digitalWrite(7, HIGH);
  delay(100);
  Tlc.setAllDC(63);
  delay(100);

  digitalWrite(7, LOW);

}
int counter = 0;
byte wert = 0;
byte i = 0;
bool direct = false;
void loop() {



  /* for (int p = 0; p < 10; p++){
    digitalWrite(7, HIGH);
    delay(200);
    Tlc.setAllDC(63);
    t = 1;
    digitalWrite(7, LOW);
    }
    */


i = encoder1.read();
/*
counter ++;

wert = counter + 201;
wert = wert/4;

*/  
/*
for (int counter = 0; counter <= 65; counter++)
  {
  for (int k = 0; k < 64; k++)
  {
    if (k <= counter) {Tlc.set(k, k*20);}
    if (k > counter) {Tlc.set(k, 0);}

  }
    Tlc.update();
    delay(25);
  }


for (int bounter = 65; bounter > 0; bounter--)
  {
  for (int k = 0; k < 64; k++)
  {
    if (k <= bounter) {Tlc.set(k, k*20);}
    if (k > bounter) {Tlc.set(k, 0);}

  }
    Tlc.update();
    delay(25);
  }
  */

  for (int k = 0; k < 64; k++)
  {
    Tlc.set(k, k*40);

  }
    Tlc.update();



  



}
