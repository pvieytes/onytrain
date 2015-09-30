#include "Arduino.h"

#ifndef motor_h
#define motor_h

#include "utils.h"
#include <LiquidCrystal.h>


class Motor
{
  public:
  //methods
  int increaseSpeed(int speed);
  int decreaseSpeed(int speed);
  void printSpeed(LiquidCrystal lcd, int speed);
  void setSpeed(int speed);

  //attributes
  
  private:
    //Methods

    //Attributes

};

#endif