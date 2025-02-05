#include "spSystem.h"
#include "button.h"
#include "relay.h"
#include "light.h"
#include "speaker.h"
#include "countdown.h"

ScissorPlatformSystem system1;
Button button1(20);
Relay relay1(4);
Light warningLight(8);
Speaker speaker(10);
CountdownTimer countdownTimer(10);


void setup() {
  Serial.begin(9600);

  system1.setStatus(RUNNING);
}

void loop() {

  if (system1.getStatus() == RUNNING) {
    relay1.on();

    // listenSensors();
    delay(3000);
    system1.setStatus(STOPPED);
    system1.printStatus();
  }

  if (system1.getStatus() == STOPPED) {
    relay1.off();
    warningLight.on();
    speaker.on();

    if (button1.isPressed()) {
      system1.setStatus(ALLOW_10S);
      countdownTimer.setStart(millis());
    }
  }

  if (system1.getStatus() == ALLOW_10S) {
    relay1.on();
    warningLight.off();
    speaker.off();

    countdownTimer.countdown(countDownCallback);
  }

  delay(10);
}

void countDownCallback() {
  Serial.println("countdown finish");
  system1.setStatus(RUNNING);
}