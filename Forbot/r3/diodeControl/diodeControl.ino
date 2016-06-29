#define red_led 8
#define green_led 9

String dataReceived = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  
  digitalWrite(green_led, LOW);
  digitalWrite(red_led, LOW);

}

void invert_led(int pin)
{
  bool led_status = digitalRead(pin);
  if (led_status)
    digitalWrite(pin, LOW);
  else
    digitalWrite(pin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    dataReceived = Serial.readStringUntil('\n');
    
    if (dataReceived == "green"){
      invert_led(green_led);
    }
  else
  if (dataReceived == "red"){
    invert_led(red_led);
  }
  else{
    Serial.println("Unknown command!");
  }
  }
}
