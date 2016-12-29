#define DC_1_PWM_PIN 6
#define DC_1_LEFT_PIN 7
#define DC_1_RIGHT_PIN 8

#define DC_2_PWM_PIN 5
#define DC_2_LEFT_PIN 9
#define DC_2_RIGHT_PIN 10

void setup() {
  pinMode(DC_1_PWM_PIN, OUTPUT);
  digitalWrite(DC_1_PWM_PIN, HIGH);

  pinMode(DC_1_LEFT_PIN, OUTPUT);
  pinMode(DC_1_RIGHT_PIN, OUTPUT);

  pinMode(DC_2_PWM_PIN, OUTPUT);
  digitalWrite(DC_2_PWM_PIN, HIGH);

  pinMode(DC_2_LEFT_PIN, OUTPUT);
  pinMode(DC_2_RIGHT_PIN, OUTPUT);
}

void forward()
{
  digitalWrite(DC_1_LEFT_PIN, LOW);
  digitalWrite(DC_1_RIGHT_PIN, HIGH);
  digitalWrite(DC_2_LEFT_PIN, LOW);
  digitalWrite(DC_2_RIGHT_PIN, HIGH);
}

void backward()
{
  digitalWrite(DC_1_LEFT_PIN, HIGH);
  digitalWrite(DC_1_RIGHT_PIN, LOW);
  digitalWrite(DC_2_LEFT_PIN, HIGH);
  digitalWrite(DC_2_RIGHT_PIN, LOW);
}

void turnClockwise()
{
  digitalWrite(DC_1_LEFT_PIN, HIGH);
  digitalWrite(DC_1_RIGHT_PIN, LOW);
  digitalWrite(DC_2_LEFT_PIN, LOW);
  digitalWrite(DC_2_RIGHT_PIN, HIGH);
}

void turnAnticlockwise()
{
  digitalWrite(DC_1_LEFT_PIN, LOW);
  digitalWrite(DC_1_RIGHT_PIN, HIGH);
  digitalWrite(DC_2_LEFT_PIN, HIGH);
  digitalWrite(DC_2_RIGHT_PIN, LOW);
}

void loop()  {
  forward();
  delay(3000);
  backward();
  delay(3000);
  turnClockwise();
  delay(3000);
  turnAnticlockwise();
  delay(3000);
}
