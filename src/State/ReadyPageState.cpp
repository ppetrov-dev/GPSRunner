#include <State/ReadyPageState.h>
#include <State/FirstPageState.h>
#include <State/SearchingPageState.h>
#include <State/Context.h>
#include <Utils/Utils.h>

void ReadyPageState::Enter()
{
    auto display = _context->_oled;
    display->drawString(0, 0, "Ready");

    display->drawString(0, 2, "Lat:");
    display->drawString(0, 4, "Lon:");

    PrintChangableData();
    PrintLongPressButtonText();
}

void ReadyPageState::PrintChangableData()
{
    auto display = _context->_oled;
    auto satellites = "Sats(" + String(_context->SatellitesCountAsCharArray()) + ")";
    display->drawString(8, 0, Utils::StringToCharArray(satellites));

    auto location = _context->GetCurrentLocation();
    display->drawString(5, 2, _context->PointAsCharArray(location.lat()));
    display->drawString(5, 4, _context->PointAsCharArray(location.lon()));
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
    case Command::_200msTimerElapsedCommand:
        _longPressButtonText->Next();
        PrintLongPressButtonText();
        break;
    case Command::ButtonLongPressCommand:
        _context->ResetData();
        _context->TransitionTo(new FirstPageState);
        break;
    case Command::InvalidGpsDataCommand:
        _context->TransitionTo(new SearchingPageState);
        break;
    default:
        break;
    }
}