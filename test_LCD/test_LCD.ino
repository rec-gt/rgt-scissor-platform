// #include "displayOLED.h"
// DisplayOLED displayOLED;

#include "displayDummy.h"
DisplayOLED displayOLED;

#define PIN1 30
#define PIN2 28
#define PIN3 16

byte systemStatus = 3;

void setup() {
  Serial.begin(9600);

  pinMode(PIN1, INPUT);
  pinMode(PIN2, INPUT);
  pinMode(PIN3, INPUT);

  if (!displayOLED.init()) {
    // cut relay
  }

  delay(1000);
}


void loop() {
  Serial.println("Sensor Working");

  if (systemStatus == 1) {
    displayOLED.print(PRINT_ERR, "Logical String");
  }

  if (systemStatus == 2) {
    displayOLED.print(PRINT_MSG, "Logical String");
  }

  if (systemStatus == 3) {
    displayOLED.print(PRINT_WARNING, "Logical String");
  }

  delay(1000);
}
