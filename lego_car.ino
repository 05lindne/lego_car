
/*
Lego Car Project
by Sarah Lindner
created 06/06/2020
modified 10/21/2020

Created with help of:
- the book "Exploring Arduino"
- youtube channel DroneBot Workshop:
	-- video "Using IR Remote Controls with the Arduino"

Description of Lego motors:
https://www.yumpu.com/de/document/read/51446269/lego-9v-technic-motors-compared-characteristicspdf


TODO:
- car makes noise but does not move backwards when 9 is pressed

*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

#include <Servo.h>

// my own library
#include "dcMotor.h"

// Define sensor pin
const int RECV_PIN = 11;
// Define LED pin for testing purposes	
const int ledPin = 13;
// Define pin for servo signal
const int servoPin = 9;

// Initialize dcMotor
dcMotor myDcMotor(5);

// Define variable for servo position
// Start at 90 degrees (center position)
int pos = 90;

// Define Variable to store last code received
String continueTurn = "";

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

// Call constructor for Servo class
Servo myServo;


void setup()
{
	// Enable the IR Receiver
	irrecv.enableIRIn();

	myDcMotor.setSpeed(200);

	// Set servo motor pin
	myServo.attach(servoPin);
	// Start with Servo in Center
	myServo.write(pos);

	// Set LED pin as Output
	pinMode(ledPin, OUTPUT);

}

void loop()
{

	if (irrecv.decode(&results)){ // checks if code has been received

		switch(results.value){

			case 0xFF18E7: // remote control button 2 -> straight ahead

				// // Toggle motor On or Off
				myDcMotor.turnOn();
				continueTurn = "fwd"; // do not turn if button is held
			
			break;

			case 0xFF4AB5: // remote control button 8 -> rewind

				// // Toggle motor On or Off
				myDcMotor.rewind();
				continueTurn = "rwd"; // do not turn if button is held
			
			break;

			case 0xFF38C7: // remote control button 5 -> stop

				// // Toggle motor On or Off
				myDcMotor.turnOff();
				continueTurn = "rwd"; // do not turn if button is held
			
			break;

			case 0xFF10EF: // remote control button 4 -> turn left
				
				turnLeft();

				// prepare variable for the case that button is pressed longer
				continueTurn = "left"; 

			break;

			case 0xFF5AA5: // remote control button 6 -> turn right
				
				turnRight();

				// prepare variable for the case that button is pressed longer
				continueTurn = "right";

			break;

			case 0xFFFFFFFF: // remote control button held down

				if(continueTurn == "left"){
					turnLeft();
				}
				else if (continueTurn == "right"){
					turnRight();
				}
				else{}

			break;
		}
		irrecv.resume();
	}

	if(myDcMotor.getMotorOn()){
		digitalWrite(ledPin, HIGH);
	}else if (!myDcMotor.getMotorOn()){
		digitalWrite(ledPin, LOW);
	}

}

void turnLeft(){
	// move left 2 degrees
	pos += 2;
	// prevent position above 180
	if(pos > 180){pos = 180;}
	myServo.write(pos);
}

void turnRight(){
	// move right 2 degrees
	pos -= 2;
	// prevent position below 0
	if(pos < 0){pos = 0;}
	myServo.write(pos);;
}
