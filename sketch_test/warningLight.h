#include "Arduino.h"

class WarningLight {
private:
  byte pin;
  byte lastStatus;
  unsigned long lastMillis;

public:
  WarningLight(byte pin) {
    this->pin = pin;
    this->lastStatus = LOW;
    this->lastMillis = millis();
    pinMode(this->pin, OUTPUT);
  }

  void on() {
    unsigned long currentMillis = millis();
    byte currentStatus = digitalRead(this->pin);
    if (currentMillis - this->lastMillis > 100) {
      this->lastMillis = currentMillis;

      if (currentStatus == this->lastStatus) {
        this->lastStatus = !currentStatus;
        digitalWrite(this->pin, this->lastStatus);
      }
    }
  }

  void off() {
    digitalWrite(this->pin, LOW);
  }
};