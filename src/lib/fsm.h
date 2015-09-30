#include "Arduino.h"
#include <LiquidCrystal.h>

#ifndef fsm_h
#define fsm_h

#include "motor.h"

#define SELECT_TRAIN_STATE 0
#define INITIAL_STATE SELECT_TRAIN_STATE




class Fsm
{
  public:
  //methods
   void init();
   void event(int event);
   
  //attributes
  String firstLine;
  String secondLine;
  private:


    //Attributes
    int _currentState;
    int _speed;
    Motor _motor;
    //methods
    void _eventSelectTrain(int event);
   
};


#endif
