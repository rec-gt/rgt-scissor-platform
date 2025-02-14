// #include "displayOLED.h"
// DisplayOLED displayOLED;

#include "displayDummy.h"
DisplayOLED displayOLED;

#define BUTTON_PIN 30

byte systemStatus = 2;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);

  if (!displayOLED.init()) {
    // cut relay
  }
}


bool buttonIsPressed() {
  return digitalRead(BUTTON_PIN) == HIGH;
}


void loop() {
  Serial.println("Sensor Working");


  if (systemStatus == 1) {
    displayOLED.print1();
  }

  if (systemStatus == 2) {
    if (buttonIsPressed()) {
      displayOLED.print2();
    }
  }

  if (systemStatus == 3) {
    displayOLED.print3();
  }

  delay(1000);
}
