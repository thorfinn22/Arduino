int val1, val2, val3, val4;
int btn1 = 4; 
int btn2 = 5;

int btn3 = 6;
int btn4 = 7;
 
const uint8_t LedPin1 = 8;
const uint8_t LedPin2 = 9;
const uint8_t LedPin3 = 10;   



void setup()
{
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(LedPin1, OUTPUT);
  pinMode(LedPin2, OUTPUT);
  pinMode(LedPin3, OUTPUT);

  
 
}

void loop() {
  // read the state of the switch into a local variable:
  val1 = digitalRead(btn1);
   if (val1 == HIGH)
   {
     digitalWrite(LedPin1, HIGH);
     delay(100);
   }
 else {

  digitalWrite(LedPin1, LOW);
  delay(100);
  }
  
  
  val2 = digitalRead(btn2);
  val3 = digitalRead(btn3);
  
  if (val2 == HIGH && val3 == LOW){
  digitalWrite(LedPin2, HIGH);
  delay(100);
  digitalWrite(LedPin2, LOW);

  delay (100);
  }
 else if (val3 == HIGH)
    
  {
    digitalWrite(LedPin2, HIGH);
    delay(1000);
    digitalWrite(LedPin2, LOW);
    delay(1000);
  }
 else{
   digitalWrite(LedPin2, HIGH);
   delay(500);
   digitalWrite(LedPin2, LOW);
   delay(500);
 }

 val4 = digitalWrite(btn4);
 if (val4 == HIGH)
  {
   digitalWrite(LedPin3, HIGH);
   delay(100);

  }
   else 
   {
     digitalWrite(LedPin3, LOW);
     delay(100);
   }
}
