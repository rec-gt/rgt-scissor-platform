#include "displayOLED.h"

DisplayOLED displayOLED;

void setup() {
  Serial.begin(9600);
  if (!displayOLED.init()) {
    // cut relay
  }

  // displayOLED.systemRunning();
  // delay(1000);
  // displayOLED.systemStopped();
  // delay(1000);
  // displayOLED.systemWaitFor();
  // delay(1000);

  displayOLED.errSensorDetected(1);
  delay(1000);
  displayOLED.errSensorFail(2);
}

void loop() {
}