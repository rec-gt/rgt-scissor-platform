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
    digitalWrite(this->pin, HIGH);
  }

  void off() {
    digitalWrite(this->pin, LOW);
  }

  void print() {
    Serial.println(digitalRead(this->pin));
  }
};