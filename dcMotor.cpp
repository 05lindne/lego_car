/*
dcMotor.cpp 
Source Code for library to control a DC motor built into a car bot.
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
	motorOff = true;
	forward = false;
	rewind = false;
}

int dcMotor::getPin()
{
	return pin;
}

int dcMotor::getSpeed()
{
	return motorSpeed;
}

int dcMotor::getForward()
{
	return forward;
}

int dcMotor::getRewind()
{
	return rewind;
}

void dcMotor::setPin(int pin)
{
	this->pin = pin;
}

void dcMotor::setSpeed(int speed)
{
	motorSpeed = speed;
}

void dcMotor::fwd()
{
	analogWrite(pin, motorSpeed);
	delay(10);
	forward = true;
}

void dcMotor::turnOff()
{
	analogWrite(pin, 0);
	delay(10);
	motorOff = true;

}

// Switch between car moving and car standing still, i.e. motor off
void dcMotor::switchMotorState()
{
	if(motorOff && forward){ // motor is off and was moving forward previously
		fwd();
		motorOff = false;
	}
	else if(motorOff && rewind){ // motor is off and was moving backward previously
		rwd();
		motorOff = false;
	}else if (!motorOff){
		turnOff();
		motorOff = true;
	}
}

// Move car backwards with motorSpeed
void dcMotor::rwd()
{
	analogWrite(pin, -motorSpeed);
	delay(10);
	rewind = true;
}