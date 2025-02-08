#include "Arduino.h"

class BufferSwitch {
private:
  byte pin;
  byte status;
  byte previousStatus;
public:
  BufferSwitch(byte pin)
    : pin(pin) {
    pinMode(this->pin, INPUT);
  }

  void listen() {
    this->status = digitalRead(this->pin);
    // Serial.println(this->status);
  }

  bool isOn() {
    return this->status == HIGH;
  }
};