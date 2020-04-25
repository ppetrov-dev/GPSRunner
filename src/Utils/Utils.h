#ifndef UtilsH
#define UtilsH

#include <Arduino.h>
#include <NeoTime.h>

class Utils
{
private:
    static char *_buffer;

public:
    static char *StringToCharArray(String string);
    static char *PointToCharArray(int32_t point, unsigned char precision, signed char width);
    static char *DoubleToCharArray(double value, unsigned char precision, signed char width);
    static char *IntToCharArray(int value);
    static char *DateTimeToCharArray(NeoGPS::time_t dateTime);
    static char *HoursMinutesSecondsToCharArray(unsigned long hours, unsigned long minutes, unsigned long seconds);
};

#endif //UtilsH