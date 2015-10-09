#include "Arduino.h"
#include <LiquidCrystal.h>

#ifndef fsm_h
#define fsm_h

#include "motor.h"
#include "constants.h"

#define WELCOME_STATE               0
#define CONFIGURATION_MENU          1
#define TRAIN_SPEED                 2
#define LIGHTING                    3

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
    int _stateVar;
    int _speed;
    int _lighting = ON;
    Motor _motor;
    //methods
   
   void _setState(int state);

   void _setWelcome();
   void _eventWelcome(int event);   

   void _setTrainSpeed();
   void _eventTrainSpeed(int event);

   void _setConfigurationMenu();
   void _eventConfigurationMenu(int event);

   void _setLighting();
   void _eventLighting(int event);

   
};


#endif
