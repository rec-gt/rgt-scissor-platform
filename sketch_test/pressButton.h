  #include "Arduino.h"

  class PressButton {
  private:
    byte pin;
    byte status;
    byte lastStatus;
    byte lastMillis;
  public:
    PressButton(byte pin)
      : pin(pin) {
      pinMode(this->pin, INPUT);
    }

    void listen() {
      this->status = digitalRead(this->pin);
    }

    void debounceListen() {
      byte reading = digitalRead(this->pin);
      if (reading != this->lastStatus) {
        this->lastMillis = millis();
      } else {
        if (millis() - this->lastMillis > 100) {
          this->status = this->lastStatus = reading;
        }
      }
    }

    bool isPressed() {
      return this->status == LOW;  // once pressed (i.e., GND), the pin become 0V
    }
  };