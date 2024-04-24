#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <EEPROM.h>
#include<avr/pgmspace.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char table1[] PROGMEM = {"103517299"};
const char table2[] PROGMEM = {"Harry"};
const char table3[] PROGMEM = {"ENG20009"};
const char table4[] PROGMEM = {"Engineering Technology Inquiry Project"};
const char table5[] PROGMEM = {"Semester 1"};
const char table6[] PROGMEM = {"2023"};

char myChar;

void setup() {
  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Set the text color to white
  display.setTextColor(SSD1306_WHITE);

  // Set the text size to fit the screen
  display.setTextSize(1);

  // Store the student ID in EEPROM memory
  /*int student_ID_address = 0; // Address of the student ID in EEPROM memory
  String student_ID = students[0]; // Get the student ID from the students array
  EEPROM.put(student_ID_address, student_ID);

  // Store the student name in EEPROM memory
  int student_name_address = 1; // Address of the student ID in EEPROM memory
  String student_name = students[1]; // Get the student ID from the students array
  EEPROM.put(student_name_address, student_name);

    // Store the student ID in EEPROM memory
  int course_code_address = 2; // Address of the student ID in EEPROM memory
  String course_code = students[2]; // Get the student ID from the students array
  EEPROM.put(course_code_address, course_code);

   // Store the student ID in EEPROM memory
  int course_name_address = 3; // Address of the student ID in EEPROM memory
  String course_name = students[3]; // Get the student ID from the students array
  EEPROM.put(course_name_address, course_name);

  // Store the student name in EEPROM memory
  int semester_address = 4; // Address of the student ID in EEPROM memory
  String semester = students[4]; // Get the student ID from the students array
  EEPROM.put(semester_address, semester);

    // Store the student ID in EEPROM memory
  int year_address = 5; // Address of the student ID in EEPROM memory
  String year = students[5]; // Get the student ID from the students array
  EEPROM.put(year_address, year);*/

  // Scroll through each item in the students array and display it on the OLED screen
 // for (int j = 0; j < 6; j++) {
   // String student = students[j];
// read back a char
   

  

   //for (int j = 0; j < 6; j++) {
   //String student = students[j];

    // Scroll the student detail from right to left
    for(int i = SCREEN_WIDTH; i >= -display.getCursorX(); i--) {
      display.clearDisplay();
      display.setCursor(i, 10);
      for (byte k = 0; k < sizeof(table1); k++) {
     
     myChar = pgm_read_byte_near(table1 + k);
    // Serial.println(myChar);
   display.print(myChar);
  }
     // display.println(myChar);
      display.display();
      delay(1);
    }
    delay(100);
    for(int i = SCREEN_WIDTH; i >= -display.getCursorX(); i--) {
      display.clearDisplay();
      display.setCursor(i, 20);
      for (byte k = 0; k < sizeof(table2); k++) {
     
     myChar = pgm_read_byte_near(table2 + k);
    // Serial.println(myChar);
   display.print(myChar);
  }
     // display.println(myChar);
      display.display();
      delay(1);
    }

        delay(100);
    for(int i = SCREEN_WIDTH; i >= -display.getCursorX(); i--) {
      display.clearDisplay();
      display.setCursor(i, 30);
      for (byte k = 0; k < sizeof(table3); k++) {
     
     myChar = pgm_read_byte_near(table3 + k);
    // Serial.println(myChar);
   display.print(myChar);
  }
     // display.println(myChar);
      display.display();
      delay(1);
    }

        delay(100);
    for(int i = SCREEN_WIDTH; i >= -display.getCursorX(); i--) {
      display.clearDisplay();
      display.setCursor(i, 30);
      for (byte k = 0; k < sizeof(table4); k++) {
     
     myChar = pgm_read_byte_near(table4 + k);
    // Serial.println(myChar);
   display.print(myChar);
  }
     // display.println(myChar);
      display.display();
      delay(1);
    }

        delay(100);
    for(int i = SCREEN_WIDTH; i >= -display.getCursorX(); i--) {
      display.clearDisplay();
      display.setCursor(i, 40);
      for (byte k = 0; k < sizeof(table5); k++) {
     
     myChar = pgm_read_byte_near(table5 + k);
    // Serial.println(myChar);
   display.print(myChar);
  }
     // display.println(myChar);
      display.display();
      delay(1);
    }

        delay(100);
    for(int i = SCREEN_WIDTH; i >= -display.getCursorX(); i--) {
      display.clearDisplay();
      display.setCursor(i, 40);
      for (byte k = 0; k < sizeof(table6); k++) {
     
     myChar = pgm_read_byte_near(table6 + k);
    // Serial.println(myChar);
   display.print(myChar);
  }
    
      display.display();
      delay(1);
    }

        delay(100);
   

  }


void loop() {
  // Leave the loop empty since we're only displaying data once in the setup function
}
