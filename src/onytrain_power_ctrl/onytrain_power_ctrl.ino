/*******************************************************
Onytrain: http://pvieytes.github.io/onytrain/src/onytrain_power_ctrl/onytrain_power_ctrl.ino

Onytrain - User interface. LCD. Power control

Pablo Vieytes - 09/27/2015
********************************************************/

#include <LiquidCrystal.h>
#include "event.h"
#include "utils.h"
#include "constants.h"
#include "motor.h"

//////////////////////////////////////////////////////////////
// GLOBALS
//////////////////////////////////////////////////////////////

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Event event;
Motor motor;
int speed;


void turnOnLight(){
	analogWrite(LCD_CTRL_LIGHT, DEFAULT_LCD_LIGHT);
}

void turnOffLight(){
	analogWrite(LCD_CTRL_LIGHT, 0);
}

void setup()
{
 
 //init serial monitor
 Serial.begin(9600);
 Serial.println("Setup fun");
 
 //init lcd
 lcd.begin(LCD_CHARS, LCD_LINES);        
 pinMode(LCD_CTRL_LIGHT, OUTPUT);

 //init motor module
 pinMode(MOTOR_IN4, OUTPUT);
 pinMode(MOTOR_IN3, OUTPUT);

 
 analogWrite(LCD_CTRL_LIGHT, DEFAULT_LCD_LIGHT);
 lcd.setCursor(0,0);
 lcd.print(MAIN_STRING);
 speed = 0;
 motor.setSpeed(speed);
 motor.printSpeed(lcd, speed);

}


void loop()
{
 int buttonRead = event.getEvent();
 switch (buttonRead)
 {
 	case BTN_RIGHT:
 	{
 		speed = motor.increaseSpeed(speed);
    motor.printSpeed(lcd, speed);
 		break;
 	}
 	case BTN_LEFT:
 	{
 		speed = motor.decreaseSpeed(speed);
    motor.printSpeed(lcd, speed);
 		break;
 	}
 }
}

