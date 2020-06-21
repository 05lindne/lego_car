/*
  Testing toggling a state with IR remote control
  
  author: Sarah Lindner
  created on 2020/06/21

  with the help of DroneBot Workshop 2017 http://dronebotworkshop.com
*/

// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;

// Define LED pin constants
const int ledPin = 13; 

// Define integer to remember toggle state
int togglestate = 0;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup(){
  // Enable the IR Receiver
  irrecv.enableIRIn();
  // Set LED pins as Outputs
  pinMode(ledPin, OUTPUT);
}


void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
   
        case 0xFF30CF: // remote control button 1
        // Toggle LED On or Off
        if(togglestate==0){
        digitalWrite(ledPin, HIGH);
        togglestate=1;
        }
        else {
        digitalWrite(ledPin, LOW);
        togglestate=0;
        }
        break;
        
    }
    irrecv.resume(); 
  }

}