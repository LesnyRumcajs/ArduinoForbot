const int INPUT_PIN = 8;
const int OUTPUT_LED_GREEN = 7;
const int OUTPUT_LED_RED = 6;

void blink(int pin, int times, int period = 1000)
{
  for (int i(0) ; i < times ; ++i) {
    digitalWrite(pin, HIGH);
    delay(period/2);
    digitalWrite(pin, LOW);
    delay(period/2);
  }
}

void setup() {
  pinMode(INPUT_PIN, INPUT_PULLUP);
  pinMode(OUTPUT_LED_RED, OUTPUT);
  pinMode(OUTPUT_LED_GREEN, OUTPUT);

  digitalWrite(OUTPUT_LED_RED, LOW);
  digitalWrite(OUTPUT_LED_GREEN, LOW);

  Serial.begin(9600);
  Serial.println("Setup done");
}

void loop() {
  if (digitalRead(INPUT_PIN) == HIGH)
  {
    digitalWrite(OUTPUT_LED_GREEN, HIGH);
    digitalWrite(OUTPUT_LED_RED, LOW);
  }
  else
  {
    digitalWrite(OUTPUT_LED_GREEN, LOW);
    Serial.println("ALARM!");
    blink(OUTPUT_LED_RED, 3, 500);
    digitalWrite(OUTPUT_LED_RED, HIGH);

    while(digitalRead(INPUT_PIN) == LOW) delay(25);
  }
}
