#define BUZZ_OUTPUT A5

void setup() {
  pinMode(BUZZ_OUTPUT, OUTPUT);
}

void loop() {
  tone(BUZZ_OUTPUT, 4000);
  delay(100);
  noTone(BUZZ_OUTPUT);
  delay(100);
}
