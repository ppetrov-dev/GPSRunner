
#include <State/Context.h>
#include <State/SearchingPageState.h>
#include <Arduino.h>
#include <Utils/Utils.h>

Context::Context(MyGPS *myGPS) : _state(nullptr), _myGPS(myGPS)
{
    _oled = new U8X8_SSD1306_128X64_NONAME_4W_SW_SPI(PIN_Display_Clock,
                                                     PIN_Display_Data,
                                                     PIN_Display_CS,
                                                     PIN_Display_DC,
                                                     PIN_Display_Reset);
}
void Context::UpdateData()
{
    register auto speed = _myGPS->GetSpeedKmh();
    if (speed > _maxSpeed)
        _maxSpeed = speed;
    register auto distanceToStartLocation = _myGPS->GetDistanceInKmTo(_startLocation);
    if (distanceToStartLocation > _maxDistanceInKm)
        _maxDistanceInKm = distanceToStartLocation;
    register auto distance = _myGPS->GetDistanceInKmTo(_lastLocation);
    _odometerInKm += distance;
    _lastLocation = _myGPS->GetCurrentLocation();
}
void Context::ResetData()
{
    _startLocation = _myGPS->GetCurrentLocation();
    _lastLocation = _startLocation;
    _maxSpeed = 0;
    _maxDistanceInKm = 0;
    _odometerInKm = 0;
    _startTimestamp = millis();
}
void Context::Init()
{
    _oled->setContrast(255);
    _oled->setFont(u8x8_font_8x13B_1x2_f);
    _oled->begin();

    TransitionTo(new SearchingPageState);
}
Context::~Context()
{
    delete _oled;
    DisposeStateIfNotNull();
}
void Context::DisposeStateIfNotNull()
{
    if (_state == nullptr)
        return;

    delete _state;
}
void Context::Run(Command command)
{
    if (_state == nullptr)
        return;

    _state->Run(command);
}
void Context::TransitionTo(StateBase *state)
{
    DisposeStateIfNotNull();
    _state = state;
    if (_state == nullptr)
        return;
    _oled->clearDisplay();
    _state->SetContext(this);
    _state->Enter();
}
char *Context::OdometerInKmAsCharArray()
{
    auto precision = Utils::DeterminePrecision(_odometerInKm);
    return Utils::DoubleToCharArray(_odometerInKm, precision, /*width*/ 4);
}
char *Context::DistanceInKmToStartLocationAsCharArray()
{
    auto distanceInKm = _myGPS->GetDistanceInKmTo(_startLocation);
    auto precision = Utils::DeterminePrecision(distanceInKm);
    return Utils::DoubleToCharArray(distanceInKm, precision, /*width*/ 4);
}
char *Context::MaxDistanceInKmAsCharArray()
{
    auto precision = Utils::DeterminePrecision(_maxDistanceInKm);
    return Utils::DoubleToCharArray(_maxDistanceInKm, precision, /*width*/ 4);
}
char *Context::SpeedKmhAsCharArray()
{
    return Utils::DoubleToCharArray(_myGPS->GetSpeedKmh(), /*precision*/ 0, /*width*/ 4);
}
char *Context::MaxSpeedKmhAsCharArray()
{
    return Utils::DoubleToCharArray(_maxSpeed, /*precision*/ 0, /*width*/ 4);
}
char *Context::AverageSpeedKmhAsCharArray()
{
    auto seconds = MyDateTimeConverters::MillisecondsToSeconds(GetTimeDifferenceInMilliseconds());
    if (seconds == 0)
        return "   N/A";
    auto kmh = _odometerInKm * 5000 / seconds / 18;
    return Utils::DoubleToCharArray(kmh, /*precision*/ 0, /*width*/ 4);
}
char *Context::DateTimeAsCharArray()
{
    return Utils::DateTimeToCharArray(_myGPS->GetDateTime());
}
char *Context::SatellitesCountAsCharArray()
{
    return Utils::IntToCharArray(_myGPS->GetSatellitesCount());
}
char *Context::PointAsCharArray(int32_t point)
{
    return Utils::PointToCharArray(point, /*precision*/ 7, /*width*/ 4);
}
NeoGPS::Location_t Context::GetCurrentLocation()
{
    return _myGPS->GetCurrentLocation();
}
char *Context::StopwatchAsCharArray()
{
    auto milliseconds = GetTimeDifferenceInMilliseconds();
    auto totalSeconds = MyDateTimeConverters::MillisecondsToSeconds(milliseconds);

    register auto days = MyDateTimeConverters::SecondsToDays(totalSeconds);
    if (days != 0)
        totalSeconds -= MyDateTimeConverters::DaysToSeconds(days); //remove days

    auto hours = MyDateTimeConverters::SecondsToHours(totalSeconds);
    totalSeconds -= MyDateTimeConverters::HoursToSeconds(hours);
    auto minutes = MyDateTimeConverters::SecondsToMinutes(totalSeconds);
    auto seconds = totalSeconds - MyDateTimeConverters::HoursToMinutes(minutes);

    return Utils::HoursMinutesSecondsToCharArray(hours, minutes, seconds);
}