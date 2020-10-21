
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

*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

#include <Servo.h>

// Define sensor pin
const int RECV_PIN = 11;
// Motor on digital pin 9
const int MOTOR = 5;
// Define LED pin for testing purposes	
const int ledPin = 13;
// Define pin for servo signal
const int servoPin = 9;

// Define integer to remember toggle state
int togglestate = 0;

// Set a speed for the DC (forward) motor
int motorSpeed = 200;

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

	// Set motor pin as output
	pinMode(MOTOR, OUTPUT);
	// Set LED pin as Outputs
	pinMode(ledPin, OUTPUT);

	// Set servo motor pin
	myServo.attach(servoPin);
	// Start with Servo in Center
	myServo.write(pos);

}

void loop()
{

	if (irrecv.decode(&results)){ // checks if code has been received

		switch(results.value){

			case 0xFF18E7: // remote control button 2 -> straight ahead

				// Toggle motor On or Off
				if(togglestate==0){
					digitalWrite(ledPin, HIGH);
					analogWrite(MOTOR, motorSpeed);
					delay(10);
					togglestate = 1;
				}
				else {
					digitalWrite(ledPin, LOW);
					analogWrite(MOTOR, 0);
					delay(10);
					togglestate = 0;
				}
				continueTurn = "fwd"; // do not turn if button is held
			
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
				else if (continueTurn == "fwd"){
									// Toggle motor On or Off
					if(togglestate==1){
						digitalWrite(ledPin, HIGH);
						analogWrite(MOTOR, motorSpeed);
					}
					else {
						digitalWrite(ledPin, LOW);
						analogWrite(MOTOR, 0);
					}
				}

			break;
		}
		irrecv.resume();
	}
}

void turnLeft(){
	// move left 2 degrees
	pos += 2;
	// prevent position above 180
	if(pos > 180){pos = 180;}
	myServo.write(pos);
	// delay(15);
}

void turnRight(){
	// move right 2 degrees
	pos -= 2;
	// prevent position below 0
	if(pos < 0){pos = 0;}
	myServo.write(pos);
	// delay(15);
}
