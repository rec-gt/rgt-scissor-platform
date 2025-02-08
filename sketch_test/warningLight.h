#include "Arduino.h"

class WarningLight {
private:
  byte pin;
  byte lastStatus;
  unsigned long lastMillis;

public:
  WarningLight(byte pin)
    : pin(pin), lastStatus(LOW), lastMillis(millis()) {
    pinMode(this->pin, OUTPUT);
  }

  void on() {
    // 模擬閃爍
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
    this->lastStatus = LOW;
    digitalWrite(this->pin, LOW);
  }

  // void on() {
  //   // 非模擬閃爍
  //   digitalWrite(this->pin, this->lastStatus);
  // }

  // void off() {
  //   digitalWrite(this->pin, LOW);
  // }
};