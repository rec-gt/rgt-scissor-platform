// #include "displayOLED.h"
// DisplayOLED displayOLED;

#include "displayDummy.h"
DisplayOLED displayOLED;

#define PIN1 30
#define PIN2 28
#define PIN3 16

byte systemStatus = 2;

void setup() {
  Serial.begin(9600);

  pinMode(PIN1, INPUT);
  pinMode(PIN2, INPUT);
  pinMode(PIN3, INPUT);

  if (!displayOLED.init()) {
    // cut relay
  }
}



void loop() {
  Serial.print(digitalRead(PIN1));
  Serial.print(digitalRead(PIN2));
  Serial.print(digitalRead(PIN3));
  Serial.println("Sensor Working");

  if (systemStatus == 1) {
    displayOLED.print(PRINT_ERR);
  }

  if (systemStatus == 2) {
    if (digitalRead(PIN2) == HIGH) {
      displayOLED.print(PRINT_MSG);
      systemStatus = 3;
    }
  }

  if (systemStatus == 3) {
    displayOLED.print(PRINT_WARNING);
    displayOLED.print3();
  }

  delay(1000);
}
