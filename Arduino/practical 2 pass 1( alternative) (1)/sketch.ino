int LED = 7;
int val;
bool ledstate;
int btn1 = 4;



void setup() {
  // put your setup code here, to run once:
pinMode(btn1, INPUT_PULLUP);
pinMode(LED, OUTPUT);
ledstate = LOW;
}



void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(btn1);
  if ( val == LOW){
    if (ledstate == LOW){
    //digitalWrite(LED, HIGH);
    ledstate = HIGH;
  }
 //if(ledstate == HIGH){
   else ledstate = LOW;
    //digitalWrite(LED, LOW);


} 
  if(ledstate ==HIGH){
     digitalWrite(LED, HIGH);
  }
  else{
  digitalWrite(LED, LOW);
}

  delay(100);

}