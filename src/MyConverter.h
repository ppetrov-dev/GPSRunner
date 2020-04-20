#ifndef myConverterH
#define myConverterH

#include <Arduino.h>

class MyConverter
{
private:
    static char *_buffer;

public:
    static char *StringToCharArray(String string);
    static char *PointToCharArray(int32_t point);
};

#endif //myConverterH