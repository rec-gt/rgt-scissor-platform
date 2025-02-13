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

#define LH1 18  // Line Height or y-position
#define LH2 36
#define LH3 54

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

// 8個中文字為上限
class DisplayOLED {
private:
  void clearAll() {
    u8g2.clearBuffer();
  }
public:
  bool init() {
    if (!u8g2.begin()) {
      Serial.println(F("SSD1306 allocation failed"));
      return false;
    }

    u8g2.enableUTF8Print();
    u8g2.setFont(u8g2_font_unifont_t_chinese1);
    u8g2.setFontDirection(0);
    u8g2.clearDisplay();
    return true;
  }

  void printTest() {
    this->clearAll();
    u8g2.setCursor(0, LH1);
    u8g2.print("感應器感應器感應");
    u8g2.setCursor(0, LH2);
    u8g2.print("感應器感應器感應");
    u8g2.setCursor(0, LH3);
    u8g2.print("感應器12318");
    u8g2.sendBuffer();
  }

  // system message
  void systemRunning() {
    this->clearAll();
    u8g2.setCursor(0, LH1);
    u8g2.print("系統運作中");
    u8g2.sendBuffer();
  }

  void systemStopped() {
    this->clearAll();
    u8g2.setCursor(0, LH1);
    u8g2.print("系統停止運作");
    u8g2.sendBuffer();
  }

  void systemWaitFor() {
    this->clearAll();

    u8g2.setCursor(0, LH1);
    u8g2.print("系統允許");

    u8g2.setCursor(0, LH2);
    u8g2.print("短暫運作十秒");

    u8g2.sendBuffer();
  }

  // sensor errors
  void sensorDetected(byte num) {
    this->clearAll();

    u8g2.setCursor(0, LH1);
    u8g2.print("感應器 ");
    u8g2.print(num);

    u8g2.setCursor(0, LH2);
    u8g2.print("偵測到障礙物！");

    u8g2.sendBuffer();
  }

  void sensorFail(byte num) {
    this->clearAll();

    u8g2.setCursor(0, LH1);
    u8g2.print("感應器 ");
    u8g2.print(num);
    u8g2.print(" 故障！");

    u8g2.sendBuffer();
  }
};