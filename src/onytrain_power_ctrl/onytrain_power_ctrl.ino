/*******************************************************
Onytrain: http://pvieytes.github.io/onytrain/src/onytrain_power_ctrl/onytrain_power_ctrl.ino

Onytrain - User interface. LCD. Power control

Pablo Vieytes - 09/27/2015
********************************************************/

#include <LiquidCrystal.h>
#include "event.h"
#include "utils.h"
#include "constants.h"

//////////////////////////////////////////////////////////////
// GLOBALS
//////////////////////////////////////////////////////////////

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Event event;
int speed;
int direction;





void clearLine(LiquidCrystal lcd, int line){
  lcd.setCursor(0,line);
  for(int i=0; i<LCD_CHARS; i++){
    lcd.print(" ");
  }
}

void printSpeed(){
  clearLine(lcd, 1);
  lcd.setCursor(START_SPEED_CHAR, 1);
  lcd.print(abs(speed), DEC);
  if (speed<0){
  	lcd.setCursor(0, 1);
  	lcd.print("<-");
  }
  if (speed>0){
  	lcd.setCursor(LCD_CHARS -3, 1);
  	lcd.print("->");
  }
}

void increaseSpeed(){
  speed = speed + SPEED_STEP;
  if (speed>MAX_SPEED){
    speed = MAX_SPEED;
  }
  printSpeed();
}

void decreaseSpeed(){
  speed = speed - SPEED_STEP;
  if (speed< -MAX_SPEED){
    speed = - MAX_SPEED;
  }
  printSpeed();
}



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
 lcd.print(MAIN_STRING);
 speed = 0;
 direction = FRONT_REAR;
 printSpeed();

}


void loop()
{
 int buttonRead = event.getEvent();
 switch (buttonRead)
 {
 	case BTN_UP:
 	{
 		increaseSpeed();
 		break;
 	}
 	case BTN_DOWN:
 	{
 		decreaseSpeed();
 		break;
 	}
 }
}

