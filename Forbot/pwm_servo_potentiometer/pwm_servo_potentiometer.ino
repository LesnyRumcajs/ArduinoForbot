#include <Servo.h>

#define SERVO_PORT 9
#define POTENTIOMETER_PIN A5
#define SERVO_POS_MAX 180
#define SERVO_POS_MIN 0

Servo servo;
int _servoPos     = 0;

int resistanceToAngle(int resistanceRead)
{
  return resistanceRead * 180.0 / 1024.0;
}

void setup()
{
  servo.attach(SERVO_PORT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop()
{
  int pos = resistanceToAngle(analogRead(POTENTIOMETER_PIN));
  if (pos >= SERVO_POS_MIN and pos <= SERVO_POS_MAX)
    {
    _servoPos = pos;
    servo.write(_servoPos);
    Serial.println("Set position to " + String(_servoPos));
    }
  else
    Serial.println("Invalid position: " + String(pos));
  delay(200);
}
