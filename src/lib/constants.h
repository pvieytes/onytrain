#include "Arduino.h"

#ifndef constants_h
#define constants_h

#define WELCOME_TIME 1000
#define WELCOME_STRING_1 "ONYTRAIN"
#define WELCOME_STRING_2 "MOLA"

#define SPEED_STRING "Velocidad:"
#define MENU_TRAIN_SPEED "Start         ->"

#define CONFIGURATION_MENU_STRING "MENU"

#define MENU_LIGHTING		"Luminaria     ->"

#define LIGHTING_STRING_1 "<- LUMINARIA"


#define ON 1
#define OFF 0

#define ON_STR "ON"
#define OFF_STR "OFF"


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

