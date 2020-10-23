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
	return pin;
}

int dcMotor::getSpeed()
{
	return motorSpeed;
}

int dcMotor::getMotorOn()
{
	return motorOn;
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

// Switch between car moving and car standing still, i.e. motor off
void dcMotor::switchMotorState()
{
	if(motorOn){
		turnOff();
	}
	else if(!motorOn){
		turnOn();
	}
}

// Move car backwards with motorSpeed
void dcMotor::rewind()
{
	analogWrite(pin, -motorSpeed);
	delay(10);
	motorOn = true;
}