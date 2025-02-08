byte SWITCH_PIN = 22;

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT);
}

void loop() {
  Serial.println(digitalRead(SWITCH_PIN));
}
