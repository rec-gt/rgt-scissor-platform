#include "Arduino.h"

class BaseThresholdSwitch {
private:
  byte pin;
  byte status;
  byte previousStatus;
public:
  BaseThresholdSwitch(byte pin)
    : pin(pin) {
    pinMode(this->pin, INPUT);
  }

  void listen() {
    this->status = digitalRead(this->pin);
  }

  bool isOn() {
    return this->status == HIGH;
  }
};