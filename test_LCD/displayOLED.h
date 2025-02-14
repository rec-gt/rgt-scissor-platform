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

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

// 8個中文字為上限
class DisplayOLED {
private:
  bool allowPrint = false;

  void clear() {
    u8g2.clearBuffer();
    u8g2.clear();
  }

  void plotMsg(byte lh, String str) {
    u8g2.setCursor(0, lh == 0 ? LH1 : (lh == 1 ? LH2 : LH3));
    u8g2.print(str);
  }

  void send() {
    u8g2.sendBuffer();
    this->allowPrint = false;
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

    // welcome msg
    this->plotMsg(1, "正在加載保護系統...");
    this->send();
    delay(3000);

    return true;
  }

  void allowOnce() {
    this->allowPrint = true;
  }

  void printTest() {
    this->clear();
    this->plotMsg(0, "123");
    this->plotMsg(1, "456");
    this->send();
  }

  // system message
  void systemRunning() {
    if (this->allowPrint) {
      this->clear();
      this->plotMsg(0, "系統運作中！");
      this->send();
    }
  }

  void systemStopped() {
    this->clear();
    this->plotMsg(0, "系統暫停運作！");
    this->send();
  }

  void systemWaitFor() {
    this->clear();
    this->plotMsg(0, "系統允許暫時");
    this->plotMsg(1, "運作十秒！");
    this->send();
  }

  // sensor errors
  void sensorDetected(String str) {
    this->clear();
    this->plotMsg(0, "感應器" + str);
    this->plotMsg(1, "偵測到障礙物");
    this->plotMsg(2, "系統暫停運作！");
    this->send();
  }

  void sensorFail(String str) {
    this->clear();
    this->plotMsg(0, "感應器 " + str + " 故障！");
    this->send();
  }

  void wannaQuit() {
    this->clear();
    this->plotMsg(1, "心很累，想quit");
    this->send();
  }
};