#include <State/ThirdPageState.h>
#include <State/FourthPageState.h>
#include <State/Context.h>

void ThirdPageState::Enter()
{
    auto display = _context->_oled;
    display->drawString(13, 0, "3/4");

    display->drawString(0, 2, "Odo: ");
    display->drawString(14, 2, "km");
    display->drawString(0, 4, "Dst: ");
    display->drawString(14, 4, "km");
    display->drawString(0, 6, "Max: ");
    display->drawString(14, 6, "km");

    PrintStopWatch();
    PrintChangableData();
}

void ThirdPageState::PrintStopWatch()
{
     _context->_oled->drawString(0, 0, _context->StopwatchAsCharArray());
}
void ThirdPageState::PrintChangableData()
{
    _context->_oled->drawString(5, 2, _context->OdometerInKmAsCharArray());
    _context->_oled->drawString(5, 4, _context->DistanceInKmToStartLocationAsCharArray());
    _context->_oled->drawString(5, 6, _context->MaxDistanceInKmAsCharArray());
}

void ThirdPageState::Run(Command command)
{
    switch (command)
    {
    case Command::OneSecondTimerTickCommand:
        PrintStopWatch();
        break;
    case Command::ValidGpsDataCommand:
        PrintChangableData();
        break;
    case Command::ButtonClickCommand:
        _context->TransitionTo(new FourthPageState);
        break;
    case Command::ButtonLongPressCommand:
        _context->ResetData();
        break;
    default:
        break;
    }
}
