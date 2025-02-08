#include "Arduino.h"

class LaserSensor {
private:
  byte pin;
  const float baseDistance = 500;
  float bufferDistance;
  float measuredDistance;

public:
  LaserSensor(byte pin, float bufferDistance)
    : pin(pin), bufferDistance(bufferDistance) {
    pinMode(this->pin, INPUT);
  }

  LaserSensor& print() {
    return *this;
  }

  void byVoltage() {
    Serial.println(this->measuredDistance / 1023 * 5);
  }

  void byValue() {
    Serial.println(this->measuredDistance);
  }

  bool detectObstacle(bool addBuffer = false) {
    int currReading = analogRead(this->pin);

    if (addBuffer) {
      this->measuredDistance = currReading + this->bufferDistance;
    } else {
      this->measuredDistance = currReading;
    }

    return this->measuredDistance >= 950;
  }
};