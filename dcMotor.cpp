/*
dcMotor.cpp Source Code for library to control a DC motor.
by Sarah Lindner
created 10/23/2020

*/

#include "Arduino.h"
#include "dcMotor.h"

dcMotor::dcMotor(int pin)
{
	this->pin = pin;
	pinMode(pin, OUTPUT);

	motorSpeed = 0;
	motorOn = false;
}

int dcMotor::getPin()
{
	return dcMotor::pin;
}

void dcMotor::setPin(int pin)
{
	this->pin = pin;
}

void dcMotor::setSpeed(int speed)
{
	motorSpeed = speed;
}

void dcMotor::turnOn()
{
	analogWrite(pin, motorSpeed);
	delay(10);
	motorOn = true;
}

void dcMotor::turnOff()
{
	analogWrite(pin, 0);
	delay(10);
	motorOn = false;
}

void dcMotor::switchMotorState()
{
	if(motorOn){
		turnOff();
	}
	else if(!motorOn){
		turnOn();
	}
}