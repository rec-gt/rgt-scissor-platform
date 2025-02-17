#include "Arduino.h"

class PressButton {
private:
  byte pin;
  byte state;
  unsigned long lastMillis;
public:
  PressButton(byte pin)
    : pin(pin) {
    pinMode(this->pin, INPUT_PULLUP);
    digitalWrite(this->pin, HIGH);
  }

  void normalListen() {
    this->state = digitalRead(this->pin);
  }

  void debounceListen() {
    byte reading = digitalRead(this->pin);

    if (reading == LOW) {
      if ((millis() - this->lastMillis) > 150) {
        this->state = reading;
      }
    } else {
      this->state = HIGH;
      this->lastMillis = millis();
    }
  }

  void print() {
    Serial.println(this->state);
  }

  bool isPressed() {
    return this->state == LOW;  // once pressed (i.e., GND), the pin become 0V
  }
};