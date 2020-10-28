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
		dcMotor(int EN, int MC1, int MC2);
		// void initialize(int EM, int MC1, int MC2);
		// int getPin();
		int getSpeed();
		int getForward();
		int getRewind();
		int getMotorOff();
		// void setPin(int pin);
		void setSpeed(int speed);
		void fwd();
		void brake();
		void switchMotorState();
		void rwd();
	private:
		int EN;
		int MC1;
		int MC2;
		int motorSpeed;
		bool motorOff;
		bool forward;
		bool rewind;
};


#endif dcMotor_h
