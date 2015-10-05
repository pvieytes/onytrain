#include "Arduino.h"
#include "event.h"
#include "utils.h"

Event::Event(){
  _lastChange=0;
  _lastButton=BTN_NONE;
  _repeadtedButtonTimes=0;
}

int Event::_readButton(){
   int analog_key  = analogRead(0);
   if (analog_key < BTN_RIGHT_THRESHOLD){
     return BTN_RIGHT; 
   }
   if (analog_key < BTN_UP_THRESHOLD){
    return BTN_UP; 
   }
   if (analog_key < BTN_DOWN_THRESHOLD){
     return BTN_DOWN; 
   }
   if (analog_key < BTN_LEFT_THRESHOLD){
    return  BTN_LEFT; 
   }
   if (analog_key < BTN_SELECT_THRESHOLD){
     return BTN_SELECT;  
   }
  return BTN_NONE;
  
}

// read the buttons
int Event::getEvent()
{
   int return_btn;
   int pressed = _readButton();
   int now = millis();

   return_btn = pressed;
   if (pressed != BTN_NONE){
    //check keep pressed the same button for a long time
    if (pressed == _lastButton)
    {  
      //more than a time step
      if ( now - _lastChange >= PRESS_STEP){
        _repeadtedButtonTimes++;
        _lastChange = now;
        _lastButton = pressed;
        //check for double pressed 
        if (_repeadtedButtonTimes >= STEPS_FOR_DOUBLE ){
          return_btn = return_btn *  10;
          _lastButton = return_btn;
          _repeadtedButtonTimes = 0;
        }
      } else {
        // it doesn't count as a new event
        return_btn = BTN_NONE;
      }
    //new button
    } else {
      _repeadtedButtonTimes = 0;
      _lastChange = now;
      _lastButton = pressed;
    }
  } else {
    _repeadtedButtonTimes = 0;
    _lastChange = now;
    _lastButton = pressed;  }
  return return_btn;
}   


