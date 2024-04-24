#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int buttonPin = 2; // Change this to the pin number connected to your pushbutton

volatile bool displaySymbol = false;
volatile int symbolIndex = 0;

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
    displayNonAlphanumericSymbol(symbolIndex);
    delay(2000);
    display.clearDisplay();
    display.display();
    displaySymbol = false;
  }
}

void displayNonAlphanumericSymbol(int index) {
  display.clearDisplay();

  switch (index) {
    case 0:
      display.drawCircle(display.width() / 2, display.height() / 2, 10, WHITE);
      break;
    case 1:
      display.drawRect(display.width() / 4, display.height() / 4, display.width() / 2, display.height() / 2, WHITE);
      break;
    case 2:
      display.fillTriangle(display.width() / 2, 10, 10, display.height() - 10, display.width() - 10, display.height() - 10, WHITE);
      break;
    // Add more symbols here as desired
    default:
      break;
  }

  display.display();
}

void onButtonPress() {
  displaySymbol = true;
  symbolIndex = (symbolIndex + 1) % 3; // Update this value if more symbols are added
}
