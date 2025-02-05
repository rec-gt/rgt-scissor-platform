#include "Arduino.h"

class Light {
private:
  byte pin;

public:
  Light(byte pin) {
    this->pin = pin;
    init();
  }

  void init() {
    pinMode(pin, OUTPUT);
  }

  void on() {
    digitalWrite(pin, HIGH);
  }

  void off() {
    digitalWrite(pin, LOW);
  }

  void print() {
    Serial.println(digitalRead(pin));
  }
};