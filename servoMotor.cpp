/*
dcMotor.cpp 
Source Code for library to control a DC motor built into a car bot.
by Sarah Lindner
created 10/24/2020

*/


#include "Arduino.h"
#include <Servo.h>

#include "servoMotor.h"

servoMotor::servoMotor(int pin, int servoPosition)
{
	this->pin = pin;
	pinMode(pin, OUTPUT);

	this->servoPosition = servoPosition;

	// Set servo motor pin
	myServo.attach(pin);
	// Start with Servo in Center
	myServo.write(servoPosition);
}

int servoMotor::getPin()
{
	return pin;
}

Servo servoMotor::getServo()
{
	return myServo;
}

int servoMotor::getServoPosition()
{
	return servoPosition;
}

int servoMotor::getMaxPosition()
{
	return maxPosition;
}

int servoMotor::getMinPosition()
{
	return minPosition;
}

int servoMotor::getPositionIncrement()
{
	return positionIncrement;
}

int servoMotor::setMaxPosition(int maxPosition)
{
	this->maxPosition = maxPosition;
}

int servoMotor::setMinPosition(int minPosition)
{
	this->minPosition = minPosition;
}

int servoMotor::setPositionIncrement(int positionIncrement)
{
	this->positionIncrement = positionIncrement;
}


void servoMotor::setPin(int pin)
{
	this->pin = pin;
}

void servoMotor::setServoPosition(int servoPosition)
{
	this->servoPosition = servoPosition;
}


void servoMotor::turnLeft(){
	// move left positionIncrement degrees
	servoPosition += positionIncrement;
	// prevent servoPositionition above maxPosition
	if(servoPosition > maxPosition){servoPosition = maxPosition;}
	myServo.write(servoPosition);
}

void servoMotor::turnRight(){
	// move right positionIncrement degrees
	servoPosition -= positionIncrement;
	// prevent servoPositionition below minPosition
	if(servoPosition < minPosition){servoPosition = minPosition;}
	myServo.write(servoPosition);;
}