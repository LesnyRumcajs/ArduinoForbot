#include <Servo.h>
 
#define servo_pin 9
 
Servo my_servo;  
int currPos = 0;
 
void setup() 
{ 
	Serial.begin(9600);
  	my_servo.attach(servo_pin);  	//bind servo to pin
  	my_servo.write(0);				//go to initial position
} 
 
void loop() 
{  
	if (Serial.available() > 0)
	{
		String dataReceived = Serial.readStringUntil('\n');

		int newPos = dataReceived.toInt();

		if (newPos >= 0 && newPos < 180)
			my_servo.write(newPos);
		else
			Serial.println("Bad command.");
	}

  delay(50);
}
