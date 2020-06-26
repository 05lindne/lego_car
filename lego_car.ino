
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

// Define sensor pin
const int RECV_PIN = 4;
// Motor on digital pin 9
const int MOTOR = 9;
// Steering motor on digital pin 8
const int STEER = 7;
// Define LED pin for testing purposes	
const int ledPin = 13;

// Define integer to remember toggle state
int togglestate = 0;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
	// Enable the IR Receiver
	irrecv.enableIRIn();
	// Set motor pin as output
	pinMode(MOTOR, OUTPUT);
	// Set steering motor pin as output
	pinMode(STEER, OUTPUT);
	// Set LED pin as Outputs
	pinMode(ledPin, OUTPUT);
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
// marry this code with the Servo example to make motor turn in both directions
			case 0xFF10EF: // remote control button 4
				analogWrite(STEER, 200);
				// digitalWrite(ledPin, HIGH);
				delay(200);
				analogWrite(STEER, 0);
				// digitalWrite(ledPin, LOW);
			break;

			case 0xFF38C7: // remote control button 6
				analogWrite(STEER, -200);
				// digitalWrite(ledPin, HIGH);
				delay(200);
				analogWrite(STEER, 0);
				// digitalWrite(ledPin, LOW);
			break;
		}
		irrecv.resume();
	}
}

