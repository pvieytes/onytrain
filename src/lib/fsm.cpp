#include "Arduino.h"
#include "fsm.h"
#include "event.h"
#include "constants.h"


void Fsm::init(){
  _setState(INITIAL_STATE);
  
}


void Fsm::event(int event){
  switch (_currentState)
  {
    case SELECT_SPEED_TRAIN_STATE:
    {
      _eventSelectTrain(event);
      break;
    }
    case WELCOME_STATE:
    {
      _eventWelcome(event);
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

void Fsm::_eventWelcome(int event){
  delay(WELCOME_TIME);
  _setSelectTrain();
}



void Fsm::_setState(int state){
  switch (state)
  {
    case SELECT_SPEED_TRAIN_STATE:
    {
      _setSelectTrain();
      break;
    }
    case WELCOME_STATE:
    {
      _setWelcome();
      break;
    }

  }
}



void Fsm::_setSelectTrain(){
  _currentState=SELECT_SPEED_TRAIN_STATE;
  _speed=INITIAL_SPEED;
  _motor.setSpeed(_speed);
  firstLine = SPEED_STRING;
  secondLine = _motor.getSpeedString(_speed);
}

void Fsm::_setWelcome(){
  _currentState=WELCOME_STATE;
  firstLine = WELCOME_STRING_1;
  secondLine = WELCOME_STRING_2;
}