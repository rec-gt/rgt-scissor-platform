#include "detectSystem.h"
#include "button.h"
#include "relay.h"
#include "light.h"
#include "warningLight.h"
#include "speaker.h"
#include "countdown.h"
#include "laserSensor.h"
#include "bufferSwitch.h"

DetectSystem detectSystem;

Button button(2);

Relay relay(4);

Light powerLight(6);

// Light warningLight(8);
WarningLight warningLight(8);

Speaker speaker(10);

BufferSwitch bufferSwitch(12);

CountdownTimer countdownTimer(10);

LaserSensor laserSensors[] = {
  LaserSensor(A0, 0.1),
  // LaserSensor(A1, 0),
  // LaserSensor(A2, 0),
  // LaserSensor(A3, 0),
  // LaserSensor(A4, 0),
  // LaserSensor(A5, 0),
  // LaserSensor(A6, 0),
  // LaserSensor(A7, 0),
  // LaserSensor(A8, 0),
  // LaserSensor(A9, 0),
};

void setup() {
  Serial.begin(9600);

  detectSystem.setStatus(RUNNING);
  detectSystem.printStatus();
}

void loop() {
  powerLight.on();

  button.listen();

  bufferSwitch.listen();

  if (detectSystem.getStatus() == RUNNING) {
    relay.on();
    warningLight.off();
    speaker.off();
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

  delay(500);
}

void listenSensors() {
  int numLaserSensors = sizeof(laserSensors) / sizeof(laserSensors[0]);
  for (int i = 0; i < numLaserSensors; i++) {
    bool detected = laserSensors[i].detectObstacle(bufferSwitch.isOn());
    laserSensors[i].printLength();

    if (detected) {
      Serial.println("Obstacle Detected!");
      detectSystem.setStatus(STOPPED);
      detectSystem.printStatus();
      break;
    };
  }
}

void countDownCallback() {
  Serial.println("countdown finish");
  detectSystem.setStatus(RUNNING);
  detectSystem.printStatus();
}