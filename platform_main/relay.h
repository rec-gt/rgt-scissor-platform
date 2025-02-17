#include "Arduino.h"

// Relay default is LOW, and is NC, LOW=NC, HIGH=NO
class Relay {
private:
  byte pin;

public:
  Relay(byte pin)
    : pin(pin) {
    pinMode(this->pin, OUTPUT);
  }

  void connect() {
    // NC
    // COM -------|
    // NO --------|
    digitalWrite(this->pin, HIGH);
  }

  void cut() {
    // NC --------|
    // COM -------|
    // NO
    digitalWrite(this->pin, LOW);
  }
};