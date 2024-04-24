#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* PROGEM[] = {
  "*103517299*",
  "*Harry*",
  "ENG20009",
  "Engineering Technology Inquiry Project",
  "Semester 1",
  "2023"
};
const int numItems = sizeof(PROGEM) / sizeof(PROGEM[0]);

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
}

void loop() {
  for (int i = 0; i < numItems; i++) {
    displayTextRightToLeft(PROGEM[i]);
    delay(1000);
  }
}

void displayTextRightToLeft(const char* text) {
  int16_t textWidth = display.width();
  int16_t textHeight = display.height();

  display.getTextBounds(text, 0, 0, 0, 0, &textWidth, &textHeight);

  for (int x = display.width(); x > -textWidth; x--) {
    display.clearDisplay();
    display.setCursor(x, (display.height() - textHeight) / 2);
    display.print(text);
    display.display();
    delay(50);
  }
}
