#include "Arduino.h"



class Relay {
private:
  byte pin;

public:
  Relay(byte pin) {
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
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