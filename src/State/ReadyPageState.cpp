#include <State/ReadyPageState.h>
#include <State/FirstPageState.h>
#include <State/Context.h>
#include <Arduino.h> //TODO: should be removed
// #include <MyConverter.h>

void ReadyPageState::Enter()
{
    auto display = _context->_oled;
    // auto gps = _context->_myGPS;

    display->drawString(0, 0, "Ready");
    // auto satellites = "Sats(" + String(gps->GetSatellitesCount()) + ")";
    // auto satellitesCharArray = MyConverter::StringToCharArray(satellites);
    // display->drawString(8, 0, satellitesCharArray);

    // auto location = gps->GetCurrentLocation();
    // auto lat = MyConverter::PointToCharArray(location.lat());
    // display->drawString(0, 2, "Lat:");
    // display->drawString(5, 2, lat);

    // auto lon = MyConverter::PointToCharArray(location.lon());
    // display->drawString(0, 4, "Lon:");
    // display->drawString(5, 4, lon);

    PrintLongPressButtonText();
}

void ReadyPageState::PrintLongPressButtonText()
{
    _context->_oled->drawString(0, 6, _longPressButtonText->GetText());
}
void ReadyPageState::Run(Command command)
{
    switch (command)
    {
    case Command::HalfSecondTimerTickCommand:
        _longPressButtonText->Next();
        PrintLongPressButtonText();
        break;
    case Command::ButtonLongPressCommand:
        _context->TransitionTo(new FirstPageState);
        break;

    default:
        break;
    }
}