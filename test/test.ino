void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(8, INPUT);
}

void loop() {
  if (digitalRead(4) == HIGH) {
    Serial.write(1);
  } else if (digitalRead(8) == HIGH) {
    Serial.write(2);
  } else {
    Serial.write(88);
  }
}
