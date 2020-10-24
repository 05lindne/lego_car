/*
servoMotor.h 
Library to control a servo motor built into a car bot.
by Sarah Lindner
created 10/24/2020

*/


#ifndef servoMotor_h
#define servoMotor_h

class servoMotor
{
	public:
		servoMotor(int pin, int servoPosition);
		int getPin();
		Servo getServo();
		int getMaxPosition();
		int getMinPosition();
		int getPositionIncrement();
		int getServoPosition();
		void setPin(int pin);
		void setServoPosition(int servoPosition);
		int setMaxPosition(int maxPosition);
		int setMinPosition(int minPosition);
		int setPositionIncrement(int positionIncrement);		
		void turnLeft();
		void turnRight();

	private:
		int pin;
		Servo myServo;
		int servoPosition;
		int maxPosition;
		int minPosition;
		int positionIncrement;
};


#endif servoMotor_h
