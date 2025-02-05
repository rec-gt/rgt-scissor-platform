#include "detectSystem.h"
#include "button.h"
#include "relay.h"
#include "light.h"
#include "speaker.h"
#include "countdown.h"
#include "laserSensor.h"

DetectSystem detectSystem;

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
  detectSystem.setStatus(RUNNING);
  detectSystem.printStatus();
}

void loop() {
  button.listen();

  if (detectSystem.getStatus() == RUNNING) {
    relay.on();
    listenSensors();
  }

  if (detectSystem.getStatus() == STOPPED) {
    relay.off();
    warningLight.on();
    speaker.on();

    if (button.isPressed()) {
      Serial.println("10s Button Pressed");
      detectSystem.setStatus(ALLOW_10S);
      detectSystem.printStatus();
      countdownTimer.setStart(millis());
    }
  }

  if (detectSystem.getStatus() == ALLOW_10S) {
    relay.on();
    warningLight.off();
    speaker.off();
    countdownTimer.countdown(countDownCallback);
  }
}

void listenSensors() {
  for (int i = 0; i < numLaserSensors; i++) {
    laserSensors[i].printLength();
    if (laserSensors[i].detetedObstacle()) {
      Serial.println("Obstacle Detected!");
      detectSystem.setStatus(STOPPED);
      detectSystem.printStatus();
    };
  }

  delay(2000);
  detectSystem.setStatus(STOPPED);
  detectSystem.printStatus();
}

void countDownCallback() {
  Serial.println("countdown finish");
  detectSystem.setStatus(RUNNING);
  detectSystem.printStatus();
}