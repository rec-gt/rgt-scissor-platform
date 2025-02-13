#include "displayOLED.h"

DisplayOLED displayOLED;

void setup() {
  Serial.begin(9600);
  if (!displayOLED.init()) {
    // cut relay
  }

  displayOLED.print1();
  delay(5000);
  displayOLED.errSensor(22);
  
}

void loop() {
}