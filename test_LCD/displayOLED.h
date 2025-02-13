#include "Arduino.h"
#include "U8g2lib.h"
#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define SDA 20
#define SCL 21  // SCL/SCK

#define LINE_HEIGHT 18  // SCL/SCK

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

// 8個中文字為上限
class DisplayOLED {
public:
  bool init() {
    if (!u8g2.begin()) {
      Serial.println(F("SSD1306 allocation failed"));
      return false;
    }

    u8g2.enableUTF8Print();
    u8g2.setFont(u8g2_font_unifont_t_chinese1);
    u8g2.setFontDirection(0);
    u8g2.clearBuffer();
    return true;
  }

  void print1() {
    u8g2.clearBuffer();
    u8g2.setCursor(0, LINE_HEIGHT);
    u8g2.print("感應器感應器感應");
    u8g2.setCursor(0, LINE_HEIGHT * 2);
    u8g2.print("感應器感應器感應");
    u8g2.setCursor(0, LINE_HEIGHT * 3);
    u8g2.print("感應器12318");
    u8g2.sendBuffer();
  }

  void errSensor(byte num) {
    u8g2.clearBuffer();
    u8g2.setCursor(0, LINE_HEIGHT);
    u8g2.print("感應器");
    u8g2.print(num);
    u8g2.print("故障一！");
    u8g2.sendBuffer();
  }
};