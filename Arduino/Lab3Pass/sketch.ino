int buzzer1 = 9; // connect first buzzer to pin 9
bool buzzer1_state = false; // variable to store the state of first buzzer

void setup() {
  Serial.begin(9600); // start serial communication at 9600 baud
  pinMode(buzzer1, OUTPUT); // set buzzer1 pin as output
}

void loop() {
  // display the menu options
  Serial.println("Select an option:");
  Serial.println("1. Toggle first buzzer");

  // wait for user input
  while(!Serial.available()); // wait for data
  int option = Serial.parseInt(); // read the input as integer

  // execute the selected option
  switch(option) {
    case 1:
      buzzer1_state = !buzzer1_state; // toggle the state of first buzzer
      digitalWrite(buzzer1, buzzer1_state); // turn on/off the first buzzer
      Serial.print("First buzzer is ");
      Serial.println(buzzer1_state ? "on" : "off");
      break;
    default:
      Serial.println("Invalid option");
      break;
  }
}
