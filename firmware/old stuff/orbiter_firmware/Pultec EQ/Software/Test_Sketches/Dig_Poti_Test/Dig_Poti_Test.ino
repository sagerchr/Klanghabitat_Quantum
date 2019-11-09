#include <SPI.h>

byte address = 0x00;
byte address2 = 0x10;
int CS= 4;
float value=0;
float value2=0;
void setup()
{
pinMode (CS, OUTPUT);
SPI.begin();
Serial.begin(9600);
}

void loop()
{
value = 255-(analogRead(A0)/4);

if (value != value2)
{
digitalPotWrite(value);
value2 = value;
Serial.println(value);
}
delay(1);

}

/*
for (int i = 0; i <= 255; i++)
{
digitalPotWrite(i);
delay(1);
}
delay(1);
for (int i = 255; i >= 0; i--)
{
digitalPotWrite(i);
delay(1);
}
}
*/

int digitalPotWrite(int value)
{
digitalWrite(CS, LOW);
SPI.transfer(address);
SPI.transfer(value);
SPI.transfer(address2);
SPI.transfer(value);
digitalWrite(CS, HIGH);
}
