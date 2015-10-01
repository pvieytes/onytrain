#include "Arduino.h"
#include "utils.h"
#include "constants.h"
#include "motor.h"

#include <LiquidCrystal.h>

String  Motor::getSpeedString(int speed){
  String str;
  //str = "<";
  if (speed < 0 ){
    str = "<<";
  } else {
    str = "  ";
  }
  for (int i=0; i<START_SPEED_CHAR-2; i++){
    str = str + " ";
  }
  str = str + String(abs(speed), DEC);
  for (int i=0; i<LCD_CHARS-str.length()+3; i++)
  {
    str = str + " ";
  }
  if (speed>0 ){
    str = str + ">>";
  } else {
    str = str + "  ";
  }
  return str;
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
  if (speed == 0){
    analogWrite(MOTOR_IN4, 0);
    analogWrite(MOTOR_IN3, 0);
  } else {
    conversion_aux = (speed * MAX_ANALOG_WRITE)/MAX_SPEED;

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