#include "spSystem.h"
#include "button.h"
#include "relay.h"
#include "light.h"
#include "speaker.h"

ScissorPlatformSystem system1;
Button button1(20);
Relay relay1(4);
Light warningLight(8);
Speaker speaker(10);


void setup() {
  Serial.begin(9600);

  system1.setStatus(RUNNING);
  Serial.println(system1.getStatus());
}

void loop() {

  if (system1.getStatus() == RUNNING) {
    relay1.on();

    // listenSensors();
    delay(3000);
    system1.setStatus(STOPPED);
  }

  if (system1.getStatus() == STOPPED) {
    relay1.off();
    warningLight.on();
    speaker.on();

    if (button1.isPressed()) {
      system1.setStatus(ALLOW_10S);
    }

    // listenButton();
  }

  if (system1.getStatus() == ALLOW_10S) {
    relay1.on();
    warningLight.off();
    speaker.off();
    // handleTimer();
  }

  delay(10);
}
