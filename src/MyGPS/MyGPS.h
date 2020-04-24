#ifndef myGPSH
#define myGPSH

#include <NMEAGPS.h>
#include <GPSport.h>

// Uncomment one DST changeover rule, or define your own:
//#define DST_USA
#define DST_EU

#if defined(DST_USA)
static const uint8_t DST_SpringMonth = 3;
static const uint8_t DST_SpringDate = 14; // latest 2nd Sunday
static const uint8_t DST_SpringHour = 2;
static const uint8_t DST_FallMonth = 11;
static const uint8_t DST_FallDate = 7; // latest 1st Sunday
static const uint8_t DST_FallHour = 2;
#define CalculateDaylightSavingTime

#elif defined(DST_EU)
static const uint8_t DST_SpringMonth = 3;
static const uint8_t DST_SpringDate = 31; // latest last Sunday
static const uint8_t DST_SpringHour = 1;
static const uint8_t DST_FallMonth = 10;
static const uint8_t DST_FallDate = 31; // latest last Sunday
static const uint8_t DST_FallHour = 1;
#define CalculateDaylightSavingTime
#endif

class MyGPS
{
private:
    NMEAGPS _gps; // This parses received characters
    gps_fix _fix; // This contains all the parsed pieces

    NeoGPS::clock_t _timezoneOffset;
    void AdjustTime(NeoGPS::time_t &dt);
    void ReadAndAdjustTime();

public:
    MyGPS(int gmtHours, int gmtMinutes);

    bool GetIsValid();
    uint8_t GetSatellitesCount();
    NeoGPS::Location_t GetCurrentLocation();
    void ReadWhileAvailable();
    float GetSpeedKmh();
    String GetDateTime();
};
#endif //myGPSH