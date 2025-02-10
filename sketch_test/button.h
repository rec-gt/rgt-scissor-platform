#include "Arduino.h"

class Button {
private:
  byte pin;
  byte status;
public:
  Button(byte pin)
    : pin(pin) {
    pinMode(this->pin, INPUT);
  }

  void listen() {                           // GPIO design, using +/- only
    this->status = digitalRead(this->pin);  // in input mode, pin output is 5V
    digitalWrite(this->pin, this->status);  // write the 5V to pin at the same time, if not GND, the pin keep receive 5V
  }

  // void listen() {  // using default button (-/+/S)
  //   this->status = digitalRead(this->pin);
  //   Serial.println(this->status);
  // }

  bool isPressed() {
    return this->status == LOW;  // once pressed (i.e., GND), the pin become 0V
  }
};