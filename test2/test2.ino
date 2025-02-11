byte LASER_PIN = A0;
float sum = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LASER_PIN, INPUT);
}

void loop() {
  float reading = analogRead(LASER_PIN);

  sum += reading;
  count++;
  Serial.println(sum / count);
}
