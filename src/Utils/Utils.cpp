
#include <Utils/Utils.h>

char *Utils::_buffer = new char[16];

char *Utils::StringToCharArray(String string)
{
    Utils::_buffer[0] = '\0';
    string.toCharArray(Utils::_buffer, 16);
    return _buffer;
}

char *Utils::PointToCharArray(int32_t point)
{
    Utils::_buffer[0] = '\0';
    auto result = point / 10000000.0;
    return dtostrf(result, 4, 7, Utils::_buffer);
}

char *Utils::IntToCharArray(int value)
{
    Utils::_buffer[0] = '\0';
    return itoa(value, Utils::_buffer, 10);
}