void setup() {
  pinMode (52, OUTPUT);
pinMode (13, OUTPUT);
}

void loop() {
  digitalWrite(52, HIGH);
  digitalWrite(13, HIGH);
  delay(3000);
  digitalWrite(52, LOW);
  digitalWrite(13, LOW);
  delay(3000);

}
