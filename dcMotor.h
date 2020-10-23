/*
dcMotor.h Library to control a DC motor.
by Sarah Lindner
created 10/23/2020

*/

#ifndef dcMotor_h
#define dcMotor_h

class dcMotor
{
	public:
		dcMotor(int pin);
		int getPin();
		int getSpeed();
		int getMotorOn();
		void setPin(int pin);
		void setSpeed(int speed);
		void turnOn();
		void turnOff();
		void switchMotorState();
		void rewind();
	private:
		int pin;
		int motorSpeed;
		bool motorOn;
};


#endif dcMotor_h
