#include <State/FourthPageState.h>
#include <State/FirstPageState.h>
#include <State/Context.h>

void FourthPageState::Enter()
{
    auto display = _context->_oled;
    display->drawString(13, 0, "4/4");
    display->drawString(1, 2, "Lat:");
    display->drawString(1, 4, "Lon:");
    display->drawString(0, 6, "Sats:");
    PrintDateTime();
    PrintChangableData();
}

void FourthPageState::PrintChangableData()
{
    auto display = _context->_oled;
    auto location = _context->GetCurrentLocation();
    display->drawString(6, 2, _context->PointAsCharArray(location.lat()));
    display->drawString(6, 4, _context->PointAsCharArray(location.lon()));
    display->drawString(6, 6, _context->SatellitesCountAsCharArray());
}
void FourthPageState::PrintDateTime()
{
    _context->_oled->drawString(0, 0, _context->DateTimeAsCharArray());
}
void FourthPageState::Run(Command command)
{
    switch (command)
    {
    case Command::OneSecondTimerTickCommand:
        PrintDateTime();
        break;
    case Command::ValidGpsDataCommand:
        PrintChangableData();
        break;
    case Command::ButtonClickCommand:
        _context->TransitionTo(new FirstPageState);
        break;
    case Command::ButtonLongPressCommand:
        _context->ResetData();
        break;
    default:
        break;
    }
}