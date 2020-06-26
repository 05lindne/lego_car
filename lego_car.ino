
/*
Lego Car Project
by Sarah Lindner
created 06/06/2020

Created with help of the book "Exploring Arduino"

Description of Lego motors:
https://www.yumpu.com/de/document/read/51446269/lego-9v-technic-motors-compared-characteristicspdf
*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

#include <Servo.h>

// Define sensor pin
const int RECV_PIN = 4;
// Motor on digital pin 9
const int MOTOR = 3;
// Define LED pin for testing purposes	
const int ledPin = 13;
// Define pin for servo signal
const int servoPin = 9;

// Define integer to remember toggle state
int togglestate = 0;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

// Call constructor for Servo class
Servo myServo;


void setup()
{
	// Enable the IR Receiver
	irrecv.enableIRIn();
	// Set motor pin as output
	pinMode(MOTOR, OUTPUT);
	// Set servo motor pin
	// Set LED pin as Outputs
	pinMode(ledPin, OUTPUT);
// TODO: as soon as I attach the servo, the lego car doesn't work any more
	// myServo.attach(servoPin);

}

void loop()
{
	if (irrecv.decode(&results)){

		switch(results.value){
   
			case 0xFF18E7: // remote control button 2
			// Toggle motor On or Off
			if(togglestate==0){
				digitalWrite(ledPin, HIGH);
				analogWrite(MOTOR, 200);
				delay(10);
				togglestate = 1;
			}
			else {
				digitalWrite(ledPin, LOW);
				analogWrite(MOTOR, 0);
				delay(10);
				togglestate = 0;
			}
			break;

			// case 0xFF10EF: // remote control button 4
			// 	myServo.write(45);
			// 	delay(15);
			// break;

			// case 0xFF5AA5: // remote control button 6
			// 	myServo.write(135);
			// 	delay(15);
			// break;
		}
		irrecv.resume();
	}
}

