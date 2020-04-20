
#include "MyConverter.h"

char *MyConverter::_buffer = new char[16];

char *MyConverter::StringToCharArray(String string)
{
    MyConverter::_buffer[0] = '\0';
    string.toCharArray(MyConverter::_buffer, 16);
    return _buffer;
}

char *MyConverter::PointToCharArray(int32_t point)
{
    MyConverter::_buffer[0] = '\0';
    auto result = point / 10000000.0;
    return dtostrf(result, 4, 7, MyConverter::_buffer);
}