#include "MyGPS.h"

MyGPS::MyGPS(int gmtHours, int gmtMinutes)
{
    _timezoneOffset =
        gmtHours * NeoGPS::SECONDS_PER_HOUR +
        gmtMinutes * NeoGPS::SECONDS_PER_MINUTE;
}

void MyGPS::AdjustTime(NeoGPS::time_t &dt)
{
    NeoGPS::clock_t seconds = dt; // convert date/time structure to seconds

#ifdef CalculateDaylightSavingTime
        //  Calculate DST changeover times once per reset and year!
    static NeoGPS::time_t changeover;
    static NeoGPS::clock_t springForward, fallBack;

    if ((springForward == 0) || (changeover.year != dt.year))
    {
        //  Calculate the spring changeover time (seconds)
        changeover.year = dt.year;
        changeover.month = DST_SpringMonth;
        changeover.date = DST_SpringDate;
        changeover.hours = DST_SpringHour;
        changeover.minutes = 0;
        changeover.seconds = 0;
        changeover.set_day();

        // Step back to a Sunday, if day != SUNDAY
        changeover.date -= (changeover.day - NeoGPS::time_t::SUNDAY);
        springForward = (NeoGPS::clock_t)changeover;

        //  Calculate the fall changeover time (seconds)
        changeover.month = DST_FallMonth;
        changeover.date = DST_FallDate;
        changeover.hours = DST_FallHour - 1; // to account for the "apparent" DST +1
        changeover.set_day();
        // Step back to a Sunday, if day != SUNDAY
        changeover.date -= (changeover.day - NeoGPS::time_t::SUNDAY);
        fallBack = (NeoGPS::clock_t)changeover;
    }
#endif

    //  First, offset from UTC to the local timezone
    seconds += _timezoneOffset;

#ifdef CalculateDaylightSavingTime
    //  Then add an hour if DST is in effect
    if ((springForward <= seconds) && (seconds < fallBack))
        seconds += NeoGPS::SECONDS_PER_HOUR;
#endif

    dt = seconds; // convert seconds back to a date/time structure
}

void MyGPS::ReadWhileAvailable()
{
    while (_gps.available(gpsPort))
    {
        _fix = _gps.read();
        if (_fix.valid.time && _fix.valid.date)
            AdjustTime(_fix.dateTime);
    }
}