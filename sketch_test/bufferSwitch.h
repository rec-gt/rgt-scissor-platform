#include "Arduino.h"

class BufferSwitch {
private:
  byte pin;
  byte status;
  byte previousStatus;
public:
  BufferSwitch(byte pin) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
  }

  void listen() {
    byte currentStatus = digitalRead(this->pin);
    if (currentStatus != this->previousStatus) {
      this->status = currentStatus;
    }
  }

  bool isOn() {
    return this->status == HIGH;
  }
};