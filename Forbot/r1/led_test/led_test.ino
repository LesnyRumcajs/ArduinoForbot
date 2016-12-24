const int OUTPUT_LED    = 8;
const int INPUT_BUTTON  = 7;

void blink(int pin, int times)
{
  for (int i(0) ; i < times ; ++i) {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(500);
  }
}

void setup() {
  pinMode(OUTPUT_LED, OUTPUT);
  pinMode(INPUT_BUTTON, INPUT_PULLUP);
  digitalWrite(OUTPUT_LED, LOW);
}

void loop() {
  if (digitalRead(INPUT_BUTTON) == LOW)
    blink(OUTPUT_LED, 3);
  else
    digitalWrite(OUTPUT_LED, LOW);
}
