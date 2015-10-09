// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

#include <LiquidCrystal.h> //bug. It's include in a lib
#include <Wire.h>
#include "i2c-protocol.h"


bool ledState = false;
void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
	Wire.beginTransmission(NANO_1); // transmit to device #NANO_1
	if (ledState == true){
		Wire.write(LED_OFF);
	} else {
		Wire.write(LED_ON);
	}  	
  	Wire.endTransmission();    // stop transmitting
  	delay(500);
  	ledState = !ledState; 
}
