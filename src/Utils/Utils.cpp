
#include <Utils/Utils.h>

char *Utils::_buffer = new char[16];

unsigned char Utils::DeterminePrecision(float value)
{
    return value < 1000.0
               ? 3
               : value < 10000.0
                     ? 2
                     : value < 100000.0 ? 1 : 0;
}

char *Utils::StringToCharArray(String string)
{
    Utils::_buffer[0] = '\0';
    string.toCharArray(Utils::_buffer, 16);
    return _buffer;
}

char *Utils::PointToCharArray(int32_t point, unsigned char precision, signed char width)
{
    Utils::_buffer[0] = '\0';
    auto result = point / 10000000.0;
    return dtostrf(result, width, precision, Utils::_buffer);
}

char *Utils::DoubleToCharArray(double value, unsigned char precision, signed char width)
{
    Utils::_buffer[0] = '\0';
    return dtostrf(value, width, precision, Utils::_buffer);
}

char *Utils::IntToCharArray(int value)
{
    Utils::_buffer[0] = '\0';
    return itoa(value, Utils::_buffer, 10);
}
char *Utils::DateTimeToCharArray(NeoGPS::time_t dateTime)
{
    Utils::_buffer[0] = '\0';
    sprintf(_buffer, "%02d.%02d %02d:%02d", dateTime.date, dateTime.month, dateTime.hours, dateTime.minutes);
    return _buffer;
}
char *Utils::HoursMinutesSecondsToCharArray(unsigned long hours, unsigned long minutes, unsigned long seconds)
{
    Utils::_buffer[0] = '\0';
    sprintf(_buffer, "%02lu:%02lu:%02lu", hours, minutes, seconds);
    return _buffer;
}
