#include <State/ReadyPageState.h>
#include <State/FirstPageState.h>
#include <State/SearchingPageState.h>
#include <State/Context.h>
#include <Utils/Utils.h>

void ReadyPageState::Enter()
{
    register auto display = _context->_oled;
    display->drawString(0, 0, "Ready");

    display->drawString(0, 2, "Lat:");
    display->drawString(0, 4, "Lon:");

    PrintChangableData();
    PrintLongPressButtonText();
}

void ReadyPageState::PrintChangableData()
{
    register auto display = _context->_oled;
    register auto gps = _context->_myGPS;

    auto satellites = "Sats(" + String(gps->GetSatellitesCount()) + ")";
    auto satellitesCharArray = Utils::StringToCharArray(satellites);
    display->drawString(8, 0, satellitesCharArray);

    auto location = gps->GetCurrentLocation();
    auto lat = Utils::PointToCharArray(location.lat());
    display->drawString(5, 2, lat);

    auto lon = Utils::PointToCharArray(location.lon());
    display->drawString(5, 4, lon);
}
void ReadyPageState::PrintLongPressButtonText()
{
    _context->_oled->drawString(0, 6, _longPressButtonText->GetText());
}
void ReadyPageState::Run(Command command)
{
    switch (command)
    {
    case Command::ValidGpsDataCommand:
        PrintChangableData();
        break;
    case Command::OneSecondTimerTickCommand:
        _longPressButtonText->Next();
        PrintLongPressButtonText();
        break;
    case Command::ButtonLongPressCommand:
        _context->SaveStartLocation();
        _context->TransitionTo(new FirstPageState);
        break;
    case Command::InvalidGpsDataCommand:
        _context->TransitionTo(new SearchingPageState);
        break;
    default:
        break;
    }
}