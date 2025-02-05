#include "Arduino.h"

class CountdownTimer {
private:
  const unsigned long TIMER_DURATION = 10 * 1000;
  int remainingTime = 10;
  unsigned long startMillis = millis();
  unsigned long duration = 10 * 1000;

public:
  CountdownTimer(unsigned long duration) {
    this->startMillis = millis();
    this->duration = duration * 1000;
  }

  void start(void (*callback)()) {
    unsigned long currentMillis = millis();

    // print countdown
    int currentRemainingTime = (TIMER_DURATION - (currentMillis - startMillis)) / 1000;

    if (currentRemainingTime >= 0 && currentRemainingTime != remainingTime) {
      remainingTime = currentRemainingTime;
      Serial.println(int(currentRemainingTime) + 1);
    }

    if (currentMillis - startMillis >= TIMER_DURATION) {
      remainingTime = TIMER_DURATION / 1000;
      callback();
    }
  }
};