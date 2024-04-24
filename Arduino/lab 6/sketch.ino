#include <Adafruit_SSD1306.h> // if you are using an SSD1306 OLED display
// #include <Adafruit_TFTLCD.h> // if you are using a TFT-LCD display

// Define the interrupt pin for the button
#define BUTTON_PIN 4

// Define the non-alphanumeric symbol to display
#define SYMBOL "\x7F"

// Initialize the LCD display (change these values to match your display)
Adafruit_SSD1306 display(128, 32, &Wire, -1); // if you are using an SSD1306 OLED display
// Adafruit_TFTLCD display = Adafruit_TFTLCD(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST); // if you are using a TFT-LCD display

volatile bool buttonPressed = false;

void buttonInterrupt() {
  buttonPressed = true;
}

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Initialize the button pin as an input with pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Attach the interrupt to the button pin
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonInterrupt, FALLING);

  // Initialize the LCD display
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
}

void loop() {
  // Check if the button was pressed
  if (buttonPressed) {
    // Clear the display
    display.clearDisplay();

    // Display the non-alphanumeric symbol
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print(SYMBOL);
    display.display();

    // Reset the button pressed flag
    buttonPressed = false;
  }
}
