/*
dcMotor.cpp 
Source Code for library to control a DC motor built into a car bot.
by Sarah Lindner
created 10/23/2020

*/

#include "Arduino.h"
#include "dcMotor.h"

dcMotor::dcMotor(int EN, int MC1, int MC2)
{
	this->EN = EN;
	this->MC1 = MC1;
	this->MC2 = MC2;

	pinMode(EN, OUTPUT);
    pinMode(MC1, OUTPUT);
    pinMode(MC2, OUTPUT);
    brake(); //Initialize with motor stopped	

	motorSpeed = 0;
	motorOff = true;
	forward = false;
	rewind = false;
}

// void dcMotor::initialize(int EN, int MC1, int MC2)
// {
// 	this->EN = EN;
// 	this->MC1 = MC1;
// 	this->MC2 = MC2;

// 	pinMode(EN, OUTPUT);
//     pinMode(MC1, OUTPUT);
//     pinMode(MC2, OUTPUT);
//     brake(); //Initialize with motor stopped
// }

// int dcMotor::getPin()
// {
// 	return pin;
// }

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

int dcMotor::getMotorOff()
{
	return motorOff;
}

// void dcMotor::setPin(int pin)
// {
// 	this->pin = pin;
// }

void dcMotor::setSpeed(int speed)
{
	motorSpeed = speed;
}

void dcMotor::fwd()
{
	digitalWrite(EN, LOW);
    digitalWrite(MC1, HIGH);
    digitalWrite(MC2, LOW);
    analogWrite(EN, motorSpeed);
	// analogWrite(pin, motorSpeed);
	// delay(10);
	forward = true;
	motorOff = false;
}

// Move car backwards with motorSpeed
void dcMotor::rwd()
{
	digitalWrite(EN, LOW);
    digitalWrite(MC1, LOW);
    digitalWrite(MC2, HIGH);
    analogWrite(EN, motorSpeed);
	// analogWrite(pin, -motorSpeed);
	// delay(10);
	rewind = true;
	motorOff = false;
}

void dcMotor::brake()
{
	digitalWrite(EN, LOW);
    digitalWrite(MC1, LOW);
    digitalWrite(MC2, LOW);
    digitalWrite(EN, HIGH);
	// analogWrite(pin, 0);
	// delay(10);
	motorOff = true;

}

// Switch between car moving and car standing still, i.e. motor off
void dcMotor::switchMotorState()
{
	if(motorOff && forward){ // motor is off and was moving forward previously
		fwd();
	}
	else if(motorOff && rewind){ // motor is off and was moving backward previously
		rwd();
	}else if (!motorOff){
		brake();
	}
}