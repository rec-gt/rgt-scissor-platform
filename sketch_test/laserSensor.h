#include "Arduino.h"

class LaserSensor {
private:
  byte pin;
  const float baseDistance = 500;
  float bufferDistance;
  float measuredDistance;
  bool addBuffer;

public:
  LaserSensor(byte pin, float bufferDistance)
    : pin(pin), bufferDistance(bufferDistance), addBuffer(false) {
    pinMode(this->pin, INPUT);
  }

  void setAddBuffer(bool toggle) {
    this->addBuffer = toggle;
  }

  bool detectObstacle() {
    int currReading = analogRead(this->pin);

    if (this->addBuffer) {
      this->measuredDistance = currReading + this->bufferDistance;
    } else {
      this->measuredDistance = currReading;
    }

    return this->measuredDistance >= 950;
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
};