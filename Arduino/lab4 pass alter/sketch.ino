int ldrPin = A0; // analog input pin for LDR sensor
int ledPin = 2; // digital output pin for LED bar

void setup() {
  pinMode(ledPin, OUTPUT); // set LED pin as output
  Serial.begin(9600); // initialize serial communication for debugging
}

void loop() {
  int ldrValue = analogRead(ldrPin); // read LDR sensor value
  Serial.println(ldrValue); // print LDR value for debugging
  
  if (ldrValue < 500) { // if LDR value is less than 500 (darkness threshold)
    digitalWrite(ledPin, HIGH); // turn on LED bar
  } else {
    digitalWrite(ledPin, LOW); // turn off LED bar
  }
  
  delay(1000); // wait for 1 second before reading sensor again
}
