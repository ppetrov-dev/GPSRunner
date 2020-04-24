#ifndef UtilsH
#define UtilsH

#include <Arduino.h>

class Utils
{
private:
    static char *_buffer;

public:
    static char *StringToCharArray(String string);
    static char *PointToCharArray(int32_t point);
    static char *IntToCharArray(int value);
};

#endif //UtilsH