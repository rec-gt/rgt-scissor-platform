#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// #define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, A5, A4, U8X8_PIN_NONE);

// void testdrawstyles(void) {
//   display.clearDisplay();
//   display.setTextSize(2.5);
//   display.setTextColor(1);
//   display.setCursor(0, 0);
//   display.print("中文");
//   display.setCursor(0, 18);
//   display.print("56789");
//   display.display();
//   delay(1000);
// }


void testChinese() {
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_unifont_t_chinese2);
  u8g2.setFontDirection(0);
  u8g2.clearBuffer();
  u8g2.setCursor(0, 15);
  u8g2.print("HIHI中文");
  u8g2.sendBuffer();

}

void setup() {
  Serial.begin(9600);

  // // 偵測是否安裝好OLED了
  // if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  //   Serial.println(F("SSD1306 allocation failed"));
  //   for (;;) {}
  // }

  testChinese();

  // testdrawstyles();
  delay(1000);
}

void loop() {
}