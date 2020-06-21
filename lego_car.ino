
/*
Lego Car Project
by Sarah Lindner
created 06/06/2020

Created with help of the book "Exploring Arduino"
*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;
// Motor on digital pin 9
const int MOTOR = 9;
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
				for(int i = 0; i < 256; i++)
				{
					analogWrite(MOTOR, i);
					delay(10);
				}

				delay(2000);

				for(int i = 255; i >= 0; i--)
				{
					analogWrite(MOTOR, i);
					delay(10);
				}
				delay(2000);
				togglestate = 1;
			}
			else {
				digitalWrite(ledPin, LOW);
        		analogWrite(MOTOR, 0);
				delay(10);
				togglestate = 0;
        	}
			break;
		}
		irrecv.resume();
	}
}

