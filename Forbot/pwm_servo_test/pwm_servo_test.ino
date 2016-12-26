#include <Servo.h>

#define SERVO_PORT 9
#define SERVO_POS_MAX 180
#define SERVO_POS_MIN 0

Servo servo;
int _servoPos     = 0;

void setup()
{
  servo.attach(SERVO_PORT);
  servo.write(SERVO_POS_MIN);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop()
{
  if (Serial.available() > 0)
  {
    int pos = Serial.parseInt();
    if (pos >= SERVO_POS_MIN and pos <= SERVO_POS_MAX)
      {
      _servoPos = pos;
      servo.write(_servoPos);
      Serial.println("Set position to " + String(_servoPos));
      }
    else
      Serial.println("Invalid position");
  }
  delay(200);
}
