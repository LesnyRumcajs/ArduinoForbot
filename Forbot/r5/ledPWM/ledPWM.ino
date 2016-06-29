#define green_led 3

byte fill = 0;
int change = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(green_led, OUTPUT);
  digitalWrite(green_led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(green_led, fill);
  
  fill += change;
  
  //reverse the output when filled
  if (fill >= 255 || fill <= 0)
    change *= -1;
    
  delay(4);
}
