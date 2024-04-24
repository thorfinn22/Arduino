#include <Wire.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_SCL 21
#define OLED_SDA 20
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
 Wire.begin();
 display.begin(SSD1306_SWITCHCAPVCC,0x3C);
 display.clearDisplay();
 display.setTextColor(SSD1306_WHITE);
 display.setTextSize(1);
}

void loop()
{
 String studentname = "Harry";
 String studentid = "103517299";
 String unitcode = "ENG20009";
 String unitname = "Eng Tech Inquiry Project";
 String semester = "Semester 1";
 String year = "2023";

 int stringWidth = 10;
 int shift = SCREEN_WIDTH; // Start from the right edge
 while(shift >=stringWidth);
 { 
  display.clearDisplay();
  display.setCursor(shift, 0); 
  display.println(studentname+ " , " +studentid);
  display.setCursor(shift, 10);
  display.println(unitname);
  display.setCursor(shift, 20);
  display.println(unitcode+ " , " +semester + " , " + year);
  display.println();
  display.display();
  delay (40);
  shift -= 1;
 }
}