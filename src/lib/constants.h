#include "Arduino.h"

#ifndef constants_h
#define constants_h

#define SPEED_STRING "Velocidad:"

#define LCD_CHARS  16
#define LCD_LINES 2

#define MAX_ANALOG_WRITE 255
#define LCD_CTRL_LIGHT  10
#define DEFAULT_LCD_LIGHT MAX_ANALOG_WRITE/10


#define INITIAL_SPEED 0
#define MAX_SPEED 100
#define SPEED_STEP MAX_SPEED/20

#define START_SPEED_CHAR 6

#define MOTOR_IN4		3
#define MOTOR_IN3		2

#endif

