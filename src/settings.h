#ifndef settingsH
#define settingsH

#include <enums.h>

#define DEBUG 1

#define DISPLAY_TIMEOUT_SECONDS 60

#define PIN_Display_Clock 13
#define PIN_Display_Data 11
#define PIN_Display_CS 10
#define PIN_Display_DC 9
#define PIN_Display_Reset 8

#define PIN_Button 7

#define GMT_HOURS  +2L        
#define GMT_MINUTES  0L     

extern "C"
{
    typedef void (*callback)(void);
}
#endif