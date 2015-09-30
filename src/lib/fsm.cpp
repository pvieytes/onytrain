#include "Arduino.h"
#include "fsm.h"
#include "event.h"
#include "constants.h"


void Fsm::init(){
  _currentState=INITIAL_STATE;
  _speed=INITIAL_SPEED;
  _motor.setSpeed(_speed);
  firstLine = SPEED_STRING;
  secondLine = _motor.getSpeedString(_speed);
}


void Fsm::event(int event){
  switch (_currentState)
  {
    case SELECT_TRAIN_STATE:
    {
      _eventSelectTrain(event);
      break;
    }
  }
}


void Fsm::_eventSelectTrain(int event){
  switch (event)
  {
    case BTN_RIGHT:
    {
      _speed = _motor.increaseSpeed(_speed);
      _motor.setSpeed(_speed);
      break;
    }
    case BTN_LEFT:
    {
      _speed = _motor.decreaseSpeed(_speed);
      _motor.setSpeed(_speed);
      break;
    }
     case BTN_SELECT:
    {
      _speed = 0;
      _motor.setSpeed(_speed);
      break;
    }
  }
  secondLine = _motor.getSpeedString(_speed);
  
};
