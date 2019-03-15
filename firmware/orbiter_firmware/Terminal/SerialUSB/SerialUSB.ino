  void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  SerialUSB.begin(200000000);
  while (!SerialUSB) {
   digitalWrite(LED_BUILTIN, LOW); 
    }

 digitalWrite(LED_BUILTIN, HIGH);
}
int i = 0;
float millisstart = 0.0;

void loop() {
  while (!SerialUSB) {
  i=0;
  digitalWrite(LED_BUILTIN, LOW);
  millisstart = millis();
  }
  i = i+1;

  digitalWrite(LED_BUILTIN, HIGH);  
  if((millis() - millisstart) >= 1000) 
  {
    millisstart = millis();
    SerialUSB.print("i=");
    SerialUSB.print(i);
    SerialUSB.println("__________+1Sekunde_________");
  }
  
  
} 
