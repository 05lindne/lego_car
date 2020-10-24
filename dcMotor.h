/*
dcMotor.h 
Library to control a DC motor built into a car bot.
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
		int getForward();
		int getRewind();
		int getMotorOff();
		void setPin(int pin);
		void setSpeed(int speed);
		void fwd();
		void turnOff();
		void switchMotorState();
		void rwd();
	private:
		int pin;
		int motorSpeed;
		bool motorOff;
		bool forward;
		bool rewind;
};


#endif dcMotor_h
