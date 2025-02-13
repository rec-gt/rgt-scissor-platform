#include "displayOLED.h"

DisplayOLED displayOLED;

void setup() {
  Serial.begin(9600);

  displayOLED.init();

  delay(1000);
}

void loop() {
}