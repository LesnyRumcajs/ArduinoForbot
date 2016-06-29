#define REDPIN 8
#define GREENPIN 9
#define BUTTONPIN 10

void setup() {
  Serial.begin(9600);  //setup baudrate
  
  pinMode(GREENPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);
  
  pinMode(BUTTONPIN, INPUT_PULLUP);
  
  digitalWrite(REDPIN, LOW);
  digitalWrite(GREENPIN, LOW);
}

void loop() {
  if (digitalRead(BUTTONPIN) == LOW){
    digitalWrite(GREENPIN, HIGH);
    digitalWrite(REDPIN, LOW);
  }
  else{
    digitalWrite(GREENPIN, LOW);
    digitalWrite(REDPIN, HIGH);
    Serial.println("Uwaga! Alarm! Okno nie jest zamknięte!");
    
    while(digitalRead(BUTTONPIN) == HIGH){
      delay(25);
    }
  }
}
