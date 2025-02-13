#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


class Display() {
private:
  byte pin;
  void testdrawstyles(void) {
    display.clearDisplay();
    display.setTextSize(2.5);
    display.setTextColor(1);
    display.setCursor(0, 0);
    display.print("中文");
    display.setCursor(0, 18);
    display.print("56789");
    display.display();
    delay(1000);
  }

public:
  Display(byte pin)
    : pin(pin);
  init() {}
}



void setup() {
  Serial.begin(9600);

  // 偵測是否安裝好OLED了
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1) {}
  }

  testChinese();

  // testdrawstyles();
  delay(1000);
}

void loop() {
}