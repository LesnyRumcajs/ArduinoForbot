#define TRIGGER_PIN 6
#define ECHO_PIN    5
#define BUZZER_PIN  2
#define MAGIC_NUMBER 58

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

int measureDistanceCm()
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);

  return pulseIn(ECHO_PIN, HIGH) / MAGIC_NUMBER;
}

void turnBuzzerOn()
{
  digitalWrite(BUZZER_PIN, HIGH);
}

void turnBuzzerOff()
{
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  unsigned distance = measureDistanceCm();
  Serial.println(distance);

  (distance > 5 and distance < 10) ? turnBuzzerOn() : turnBuzzerOff();
  delay(500);
}
