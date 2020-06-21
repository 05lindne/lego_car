
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
}

void loop()
{
	if (irrecv.decode(&results)){

        switch(results.value){
   
        	case 0xFF30CF: // remote control button 1
        	// Toggle motor On or Off
        	if(togglestate==0){
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
			}
			else {
        		analogWrite(MOTOR, 0);
				delay(10);
        	}
			break;
		}
		irrecv.resume();
	}
}

