// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

#include <LiquidCrystal.h> //bug. It's include in a lib
#include <Wire.h>
#include "i2c-protocol.h"

void setup() {
  Wire.begin(NANO_1);                // join i2c bus with address #NANO_1
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  delay(100);
}



// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int _howMany) {
  String cmd = "";
  while (0 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    cmd = cmd + c;
  }
  executesCmd(cmd);         // print the integer
}


void executesCmd(String cmd){
	Serial.println("execute: " + cmd);
	if (cmd == LED_ON)
	{
		digitalWrite(13, HIGH);		
	} 
	else if (cmd == LED_OFF) 
	{
		digitalWrite(13, LOW);
	}
}