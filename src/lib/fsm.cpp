#include "Arduino.h"
#include "fsm.h"
#include "event.h"
#include "constants.h"

//////////////////////////////////////////
// GENERAL
//////////////////////////////////////////


void Fsm::init(){
  _speed=INITIAL_SPEED;  
  _setState(INITIAL_STATE);
  
}

void Fsm::_setState(int state){
  switch (state)
  {
    case TRAIN_SPEED:
    {
      _setTrainSpeed();
      break;
    }
    case WELCOME_STATE:
    {
      _setWelcome();
      break;
    }

  }
}

void Fsm::event(int event){
  if(event != BTN_NONE){
    log("event");
    log(String(event , DEC));
  }
  switch (_currentState)
  {
    case TRAIN_SPEED:
    {
      _eventTrainSpeed(event);
      break;
    }
    case CONFIGURATION_MENU:
    {
      _eventConfigurationMenu(event);
      break;
    }
    case WELCOME_STATE:
    {
      _eventWelcome(event);
      break;
    }
    case LIGHTING:
    {
      _eventLighting(event);
      break;
    }
    
  }
}


//////////////////////////////////////////
// WELCOME
//////////////////////////////////////////




void Fsm::_setWelcome(){
  log("void Fsm::_setWelcome()");
  _currentState = WELCOME_STATE;
  firstLine = WELCOME_STRING_1;
  secondLine = WELCOME_STRING_2;
  log(firstLine);
  log(secondLine); 
}


void Fsm::_eventWelcome(int event){
  delay(WELCOME_TIME);
  _setConfigurationMenu();
}





//////////////////////////////////////////
// CONFIGURATION MENU
//////////////////////////////////////////



void Fsm::_setConfigurationMenu(){
  _currentState=CONFIGURATION_MENU;
  firstLine = CONFIGURATION_MENU_STRING;
  secondLine = MENU_TRAIN_SPEED;
  _stateVar = TRAIN_SPEED;
}



void Fsm::_eventConfigurationMenu(int event){
  switch (_stateVar)
  {
    case TRAIN_SPEED:
    { 
      switch(event){
        case BTN_RIGHT:
        {
          _setTrainSpeed();
          break;
        }
        case BTN_DOWN:
        {
          _stateVar = LIGHTING;
          secondLine = MENU_LIGHTING;
          break;
        }
      }    
      break;
    }
    case LIGHTING:
    { 
      switch(event){
        case BTN_RIGHT:
        {
          _setLighting();
          break;
        }
        case BTN_UP:
        {
          _stateVar = TRAIN_SPEED;
          secondLine = MENU_TRAIN_SPEED;
          break;
        }
      }    
      break;
    }
    default:
    {
      break;
    }
  }
  
};


//////////////////////////////////////////
// TRAIN_SPEED
//////////////////////////////////////////



void Fsm::_setTrainSpeed(){
  _currentState=TRAIN_SPEED;
  _motor.setSpeed(_speed);
  firstLine = SPEED_STRING;
  secondLine = _motor.getSpeedString(_speed);
}



void Fsm::_eventTrainSpeed(int event){
  switch (event)
  {
    case BTN_RIGHT:
    {
      _speed = _motor.increaseSpeed(_speed);
      _motor.setSpeed(_speed);
      secondLine = _motor.getSpeedString(_speed);
      break;
    }
    case
     BTN_LEFT:
    {
      _speed = _motor.decreaseSpeed(_speed);
      _motor.setSpeed(_speed);
      secondLine = _motor.getSpeedString(_speed);
      break;
    }
    case BTN_SELECT:
    {
      _speed = 0;
      _motor.setSpeed(_speed);
      secondLine = _motor.getSpeedString(_speed);
      break;
    }
    case BTN_UP:
    {

      _speed = MAX_SPEED;
      _motor.setSpeed(_speed);
      secondLine = _motor.getSpeedString(_speed);
      break;
    }
    case BTN_DOWN:
    {

      _speed = -MAX_SPEED;
      _motor.setSpeed(_speed);
      secondLine = _motor.getSpeedString(_speed);
      break;
    }
  }
  
};


//////////////////////////////////////////
// LIGHTING
//////////////////////////////////////////



void Fsm::_setLighting(){
  _currentState=LIGHTING;
  firstLine = LIGHTING_STRING_1;
  secondLine = ON_STR;
}



void Fsm::_eventLighting(int event){
  if (event == BTN_LEFT)
  {
    _setConfigurationMenu();
  } 
  else if (event == BTN_RIGHT || event == BTN_DOWN || event == BTN_DOWN)
  {
    if (_lighting == ON){
      secondLine = OFF_STR;
      _lighting = OFF;
    } else {
      secondLine = ON_STR;
      _lighting = ON;
    }
  }
}
