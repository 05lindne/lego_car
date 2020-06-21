
/*
IR Receiver output
by Sarah Lindner
created 2020/06/21

Testing remote control with an IR receiver.
Demonstrates IR codes with IR Receiver
Displays results on Serial Monitor
 
Source: DroneBot Workshop 2017 http://dronebotworkshop.com
*/

#include <IRremote.h>
 
// Define sensor pin
const int RECV_PIN = 4;
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;
 
 
void setup(){
  // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
}
 
void loop(){
  if (irrecv.decode(&results)){
    // Print Code in HEX
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}