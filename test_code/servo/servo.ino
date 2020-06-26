
/*
Test code for servo motor for lego car
by Sarah Lindner
created 2020/06/26

with help from book "Exploring Arduino"
*/

#include <Servo.h>

const int servoPin = 10; 

Servo myServo;

void setup()
{
	myServo.attach(servoPin);
}

void loop()
{
	for(int i = 0; i < 180; i=i+2)
	{
	    myServo.write(i);
	    delay(15);
	}

	for(int i = 179; i > 0; i=i-2)
	{
	    myServo.write(i);
	    delay(15);
	}
}

