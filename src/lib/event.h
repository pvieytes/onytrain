#include "Arduino.h"

#ifndef event_h
#define event_h




// define some values used by the panel and buttons
#define BTN_NONE          -1
#define BTN_RIGHT                 1
#define BTN_DOUBLE_RIGHT          BTN_RIGHT * 10
#define BTN_UP                    2
#define BTN_DOUBLE_UP             BTN_UP * 10
#define BTN_DOWN                  3
#define BTN_DOUBLE_DOWN           BTN_DOWN * 10
#define BTN_LEFT                  4
#define BTN_DOUBLE_LEFT           BTN_LEFT * 10
#define BTN_SELECT                5
#define BTN_DOUBLE_SELECT         BTN_SELECT * 10

#define PRESS_STEP 300//millisecs
#define STEPS_FOR_DOUBLE   3

#define BTN_RIGHT_THRESHOLD 50 
#define BTN_UP_THRESHOLD 250
#define BTN_DOWN_THRESHOLD  450
#define BTN_LEFT_THRESHOLD 650
#define BTN_SELECT_THRESHOLD 850

class Event
{
  public:
  //methods
   Event();
   int getEvent();
  //attributes
  
  private:
    //Methods
    int _readButton();
    //Attributes
    int _lastChange;
    int _lastButton;
    int _repeadtedButtonTimes;

};

#endif