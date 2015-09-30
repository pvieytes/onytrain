#include "Arduino.h"
#include "utils.h"
#include "constants.h"
#include "motor.h"

#include <LiquidCrystal.h>





void  Motor::printSpeed(LiquidCrystal lcd, int speed){
  //clearLine(lcd, 1);
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

int Motor::increaseSpeed(int speed){
  speed = speed + SPEED_STEP;
  if (speed > MAX_SPEED){
    speed = MAX_SPEED;
  }
  setSpeed(speed);
  return speed;
}

int Motor::decreaseSpeed(int speed){
  speed = speed - SPEED_STEP;
  if (speed < -MAX_SPEED){
    speed = - MAX_SPEED;
  }
  setSpeed(speed);
  return speed;
}

void Motor::setSpeed(int speed){
  int conversion_aux;
  Serial.println("Speed: " + String(speed, DEC));
  if (speed == 0){
    analogWrite(MOTOR_IN4, 0);
    analogWrite(MOTOR_IN3, 0);
  } else {
    conversion_aux = (speed * MAX_ANALOG_WRITE)/MAX_SPEED;
    Serial.println("conversion_aux: " + String(conversion_aux, DEC));

    if (speed > 0)
    {
      analogWrite(MOTOR_IN4, conversion_aux);
      analogWrite(MOTOR_IN3, 0);
    } else {
      analogWrite(MOTOR_IN4, 0);
      analogWrite(MOTOR_IN3, abs(conversion_aux));
    }
  }
}