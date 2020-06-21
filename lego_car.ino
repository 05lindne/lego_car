
/*
Lego Car Project
by Sarah Lindner
created 06/06/2020

Created with help of the book "Exploring Arduino"
*/

const int MOTOR = 9;	// Motor on digital pin 9

void setup()
{
	pinMode(MOTOR, OUTPUT);
}

void loop()
{
	for(int i = 0; i < 256; i++)
	{
		analogWrite(MOTOR, i);
		delay(10);
	}

	delay(2000);

	for(int i = 255; i >= 0; i--)
	{
		analogWrite(MOTOR, i);
		delay(10);
	}
	delay(2000);
}

