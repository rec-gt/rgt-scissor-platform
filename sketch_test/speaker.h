#include "Arduino.h"

class Speaker {
private:
  byte pin;

public:
  Speaker(byte pin) {
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