#include "spSystem.h"
#include "button.h"
#include "relay.h"
#include "light.h"
#include "speaker.h"
#include "countdown.h"
#include "laserSensor.h"

ScissorPlatformSystem SPSystem;

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
  SPSystem.setStatus(RUNNING);
  SPSystem.printStatus();
}

void loop() {
  button.listen();

  if (SPSystem.getStatus() == RUNNING) {
    relay.on();
    listenSensors();
  }

  if (SPSystem.getStatus() == STOPPED) {
    relay.off();
    warningLight.on();
    speaker.on();

    if (button.isPressed()) {
      Serial.println("10s Button Pressed");
      SPSystem.setStatus(ALLOW_10S);
      SPSystem.printStatus();
      countdownTimer.setStart(millis());
    }
  }

  if (SPSystem.getStatus() == ALLOW_10S) {
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
      SPSystem.setStatus(STOPPED);
      SPSystem.printStatus();
    };
  }

  delay(2000);
  SPSystem.setStatus(STOPPED);
  SPSystem.printStatus();
}

void countDownCallback() {
  Serial.println("countdown finish");
  SPSystem.setStatus(RUNNING);
  SPSystem.printStatus();
}