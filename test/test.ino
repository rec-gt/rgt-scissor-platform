void setup() {
  Serial.begin(9600);
  pinMode(46, INPUT);
}

void loop() {
  Serial.print(2);
  Serial.print(": ");
  Serial.println(digitalRead(2));
  Serial.print(12);
  Serial.print(": ");
  Serial.println(digitalRead(12));

  // Serial.print(3);
  // Serial.print(": ");
  // Serial.println(digitalRead(3));
  // Serial.print(4);
  // Serial.print(": ");
  // Serial.println(digitalRead(4));
  // Serial.print(5);
  // Serial.print(": ");
  // Serial.println(digitalRead(5));
  // Serial.print(6);
  // Serial.print(": ");
  // Serial.println(digitalRead(6));
  // Serial.print(7);
  // Serial.print(": ");
  // Serial.println(digitalRead(7));
  delay(100);
}
