#include "Arduino.h"

class Button {
private:
  byte pin;
  byte status;
public:
  Button(byte pin) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
  }

  void listen() {
    this->status = digitalRead(this->pin);
  }

  bool isPressed() {
    return this->status == LOW;
  }
};