#include "Arduino.h"

class LaserSensor {
private:
  byte pin;
  const float baseDistance = 500;
  float bufferDistance;

public:
  LaserSensor(byte pin, float bufferDistance) {
    this->pin = pin;
    this->bufferDistance = bufferDistance;
    pinMode(this->pin, INPUT);
  }

  void printLength() {
    int sensorValue = analogRead(this->pin);
    float measuredDistance = sensorValue * 5.0 / 1023.0;
    Serial.println(measuredDistance);
  }

  bool detetedObstacle() {
    return false;
    // int sensorValue = analogRead(this->pin);
    // float measuredDistance = sensorValue * 5.0 / 1023.0;
    // return measuredDistance >= this->baseDistance + this->bufferDistance;
  }
};

// class LaserSensorGroup {
// private:
//   this->LaserSensor[] laserSensors;
// public:
//   LaserSensorGroup(LaserSensor[] laserSensors) {}
// }