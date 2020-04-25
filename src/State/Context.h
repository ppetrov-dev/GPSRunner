#ifndef contextH
#define contextH

#include <settings.h>
#include <U8g2lib.h>
#include <MyGPS/MyGPS.h>
#include <State/StateBase.h>
#include <MyDateTimeConverters.h>

class Context
{
private:
    StateBase *_state;
    void DisposeStateIfNotNull();

    NeoGPS::Location_t _startLocation;
    NeoGPS::Location_t _lastLocation;
    float _maxSpeed = 0;
    float _maxDistanceInKm = 0;
    float _odometerInKm = 0;
    unsigned long _startTimestamp;
    MyGPS *_myGPS;

public:
    U8X8_SSD1306_128X64_NONAME_4W_SW_SPI *_oled;

    Context(MyGPS *myGPS);
    ~Context();
    void TransitionTo(StateBase *state);
    void Init();
    void Run(Command command);
    void ResetData();
    void UpdateData();
    NeoGPS::Location_t GetCurrentLocation();

    char *StopwatchAsCharArray();
    char *OdometerInKmAsCharArray();
    char *DistanceInKmToStartLocationAsCharArray();
    char *MaxDistanceInKmAsCharArray();
    char *SpeedKmhAsCharArray();
    char *MaxSpeedKmhAsCharArray();
    char *AverageSpeedKmhAsCharArray();
    char *DateTimeAsCharArray();
    char *PointAsCharArray(int32_t point);
    char *SatellitesCountAsCharArray();

    float GetMaxSpeed()
    {
        return _maxSpeed;
    }
    unsigned long GetTimeDifferenceInMilliseconds()
    {
        return millis() - _startTimestamp;
    }
};

#endif //contextH
