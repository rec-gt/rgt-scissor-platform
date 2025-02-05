#include "spSystem.h"
#include "button.h"
#include "relay.h"
#include "light.h"
#include "speaker.h"
#include "countdown.h"
#include "laserSensor.h"

ScissorPlatformSystem system1;

Button button(2);

Relay relay(4);

Light powerLight(6);

Light warningLight(8);

Speaker speaker(10);

CountdownTimer countdownTimer(5);

const int numLaserSensors = 10;
LaserSensor laserSensors[numLaserSensors] = {
  LaserSensor(A0, 0),
  LaserSensor(A1, 0),
  LaserSensor(A2, 0),
  LaserSensor(A3, 0),
  LaserSensor(A4, 0),
  LaserSensor(A5, 0),
  LaserSensor(A6, 0),
  LaserSensor(A7, 0),
  LaserSensor(A8, 0),
  LaserSensor(A9, 0),
};

void setup() {
  Serial.begin(9600);

  powerLight.on();
  system1.setStatus(RUNNING);
  system1.printStatus();
}

void loop() {
  button.update();

  if (system1.getStatus() == RUNNING) {
    relay.on();

    listenSensors();
    delay(2000);
    system1.setStatus(STOPPED);
    system1.printStatus();
  }

  if (system1.getStatus() == STOPPED) {
    relay.off();
    warningLight.on();
    speaker.on();

    if (button.isPressed()) {
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
}

void listenSensors() {
  for (int i = 0; i < numLaserSensors; i++) {
    if (laserSensors[i].detetedObstacle()) {
      Serial.println("Obstacle Detected!");
      system1.setStatus(STOPPED);
    };
  }
}

void countDownCallback() {
  Serial.println("countdown finish");
  system1.setStatus(RUNNING);
  system1.printStatus();
}