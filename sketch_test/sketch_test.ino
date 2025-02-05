#include "spSystem.h"
#include "button.h"
#include "relay.h"
#include "light.h"
#include "speaker.h"
#include "countdown.h"

ScissorPlatformSystem system1;
Button button1(20);
Relay relay(4);
Light powerLight(6);
Light warningLight(8);
Speaker speaker(10);
CountdownTimer countdownTimer(5);


void setup() {
  Serial.begin(9600);

  powerLight.on();
  system1.setStatus(RUNNING);
  system1.printStatus();
}

void loop() {
  button1.update();
  if (system1.getStatus() == RUNNING) {
    relay.on();

    // listenSensors();
    delay(2000);
    system1.setStatus(STOPPED);
    system1.printStatus();
  }

  if (system1.getStatus() == STOPPED) {
    relay.off();
    warningLight.on();
    speaker.on();

    if (button1.isPressed()) {
      Serial.println("10s Button Pressed");
      system1.setStatus(ALLOW_10S);
      system1.printStatus();
      countdownTimer.setStart(millis());
    }
  }

  if (system1.getStatus() == ALLOW_10S) {
    relay.on();
    warningLight.off();
    speaker.off();
    countdownTimer.countdown(countDownCallback);
  }

  delay(10);
}

void countDownCallback() {
  Serial.println("countdown finish");
  system1.setStatus(RUNNING);
  system1.printStatus();
}