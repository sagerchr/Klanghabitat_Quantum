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


bool allowed [] = {
                   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   };


/*bool allowed [] = {
                   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   };
*/

/*bool allowed [] = {
                   0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,
                   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                   };

*/

int enc = 0;

void loop() {

enc = encoder1.read();
if (enc >= 63){enc=63;}
if (enc <= 0) {enc=0;}

for(int t=0; t<32; t++)
{
  for (int k = 0; k < 64; k++)
  {
    Tlc.set(k, 40);
    //if (k<t) {Tlc.set(k, (1000));}
    //if (k>64-t) {Tlc.set(k, (1000));}
    
    //if (allowed[k]){ Tlc.set(k, (1000));}
    //if (!allowed[k]){ Tlc.set(k, (0));}
    //Tlc.set(enc, (4000));
  }       
    Tlc.update();
    delay(50);
}
}
