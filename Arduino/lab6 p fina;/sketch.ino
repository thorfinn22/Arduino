#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int buttonPin = 2; // Change this to the pin number connected to your pushbutton

volatile bool displaySymbol = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), onButtonPress, FALLING);

  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
}

void loop() {
  if (displaySymbol) {
    displayNonAlphanumericSymbol();
    delay(2000);
    display.clearDisplay();
    display.display();
    displaySymbol = false;
  }
}

void displayNonAlphanumericSymbol() {
  display.clearDisplay();
  display.drawCircle(display.width() / 2, display.height() / 2, 10, WHITE);
  display.display();
}

void onButtonPress() {
  displaySymbol = true;
}
