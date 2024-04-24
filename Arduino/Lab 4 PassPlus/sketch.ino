const int POT_PIN = A0;
const int LED_PIN = 7;

void setup() 
{
  Serial.begin (9600) ;
  pinMode (POT_PIN, INPUT);
  pinMode (LED_PIN, OUTPUT);
}
void loop () 
{
  int val = analogRead (POT_PIN) ;
  val = map (val, 0, 1023, 0,255);
  analogWrite(LED_PIN , val);
}