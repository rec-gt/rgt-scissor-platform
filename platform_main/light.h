#include "Arduino.h"

class Light {
private:
  byte pin;

public:
  Light(byte pin)
    : pin(pin) {
    pinMode(this->pin, OUTPUT);
  }

  void on() {
    digitalWrite(this->pin, HIGH);
  }

  void off() {
    digitalWrite(this->pin, LOW);
  }
};