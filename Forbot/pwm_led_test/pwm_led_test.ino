#define OUTPUT_PWM_PIN 6
const int FILL_MIN = 0x0F;
const int FILL_MAX = 0x7F;
int fill(FILL_MIN);
int step(3);



void setup() {
  pinMode(OUTPUT_PWM_PIN, OUTPUT);
  digitalWrite(OUTPUT_PWM_PIN, LOW);

  Serial.begin(9600);
}

void loop() {
  analogWrite(OUTPUT_PWM_PIN, fill);

  if (fill > FILL_MAX || fill <= FILL_MIN)
    step *= -1;

  fill += step;
  if (fill < FILL_MIN) fill = FILL_MIN;

  delay(10);
}
