#include "Arduino.h"

class LaserSensor {
private:
  byte pin;
  const float baseThreshold = 500;
  float bufferThreshold;
  float measuredDistance;
  bool needBuffer;

  float calculateDistance(float reading) {
    float min_factor = 192;
    float max_factor = 965;
    float min_sensor = 0;
    float max_sensor = 2000;

    return ((reading - max_factor) / (min_factor - max_factor)) * (min_sensor - max_sensor) + max_sensor;
  }

public:
  LaserSensor(byte pin, float bufferThreshold)
    : pin(pin), bufferThreshold(bufferThreshold), needBuffer(false) {
    pinMode(this->pin, INPUT);
  }

  void setBuffer(bool toggle) {
    this->needBuffer = toggle;
  }

  bool detectObstacle() {
    float reading = analogRead(this->pin);

    this->measuredDistance = this->calculateDistance(reading);

    float threshold = this->baseThreshold + (this->needBuffer ? this->bufferThreshold : 0);

    // Serial.println(reading);
    Serial.println(this->measuredDistance);
    return this->measuredDistance <= threshold;
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

  float getDistance() {
    return this->measuredDistance;
  }
};