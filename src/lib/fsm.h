#include "Arduino.h"
#include <LiquidCrystal.h>

#ifndef fsm_h
#define fsm_h

#include "motor.h"

#define WELCOME_STATE 0
#define SELECT_SPEED_TRAIN_STATE 1


#define INITIAL_STATE WELCOME_STATE




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
   void _eventWelcome(int event);
   void _eventSelectTrain(int event);
   void _setState(int state);
   void _setWelcome();
   void _setSelectTrain();


   
};


#endif
