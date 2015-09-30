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
#include "fsm.h"

//////////////////////////////////////////////////////////////
// GLOBALS
//////////////////////////////////////////////////////////////

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Event event;
Fsm fsm;


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
 analogWrite(LCD_CTRL_LIGHT, DEFAULT_LCD_LIGHT);
 lcd.setCursor(0,0);

 //init motor module
 pinMode(MOTOR_IN4, OUTPUT);
 pinMode(MOTOR_IN3, OUTPUT);

 fsm.init();
 lcdPrintLine(lcd, 0, fsm.firstLine);
 lcdPrintLine(lcd, 1, fsm.secondLine);
 

}


void loop()
{
  fsm.event(event.getEvent());
  lcdPrintLine(lcd, 0, fsm.firstLine);
  lcdPrintLine(lcd, 1, fsm.secondLine);
}

