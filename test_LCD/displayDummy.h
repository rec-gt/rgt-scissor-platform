#include "Arduino.h"
#include "U8g2lib.h"
#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define SDA 20
#define SCL 21  // SCL/SCK

#define LH1 18  // Line Height or y-position
#define LH2 36
#define LH3 54

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

enum StateEnum {
  _NULL,
  INIT,
  PRINT_ERR,
  PRINT_MSG,
  PRINT_WARNING,
};

class DisplayOLED {
private:
  StateEnum lastState = _NULL;

  void clear() {
    u8g2.clearBuffer();
  }

  void plot(byte lh, char* msg) {
    u8g2.setCursor(0, lh == 0 ? LH1 : (lh == 1 ? LH2 : LH3));
    u8g2.print(msg);
  }

  void send() {
    u8g2.sendBuffer();
  }
public:
  bool init() {
    if (!u8g2.begin()) {
      Serial.println(F("SH1106 allocation failed"));
      return false;
    }

    u8g2.enableUTF8Print();
    u8g2.setFont(u8g2_font_unifont_t_chinese1);
    u8g2.setFontDirection(0);
    u8g2.clearDisplay();

    this->print(INIT);

    return true;
  }

  void print(StateEnum currState, char* addStr = "") {
    if (this->lastState == currState) {
      return;
    }

    this->lastState = currState;

    // handle all plotting here
    this->clear();

    switch (currState) {
      case INIT:
        // this->plot(1, "正在加載保護系統...");
        this->plot(1, "正在加載..");
        break;
      case PRINT_ERR:
        this->plot(0, ("感應器" + String(addStr)).c_str());
        this->plot(1, "偵測到障礙物");
        this->plot(2, "系統暫停運作！");
        break;
      case PRINT_MSG:
        this->plot(0, ("系統允許暫時" + String(addStr)).c_str());
        this->plot(1, "運作十秒！");
        break;
      case PRINT_WARNING:
        this->plot(0, "系統暫停運作！");
        break;
      default:
        break;
    }

    this->send();
  }
};