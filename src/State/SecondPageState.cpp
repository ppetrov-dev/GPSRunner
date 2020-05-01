#include <State/ThirdPageState.h>
#include <State/SecondPageState.h>
#include <State/InvalidState.h>
#include <State/Context.h>

void SecondPageState::Enter()
{
    auto display = _context->_oled;
    display->drawString(13, 0, "2/4");
    PrintStopwatch();
    display->drawString(7, 0, "km/h");
    display->drawString(0, 6, "Odo:");
    display->drawString(14, 6, "km");
    PrintChangableData();
}
void SecondPageState::PrintChangableData()
{
    _context->_oled->drawString(0, 0, _context->SpeedKmhAsCharArray());
    _context->_oled->drawString(5, 6, _context->OdometerInKmAsCharArray());
}
void SecondPageState::PrintStopwatch()
{
    _context->_oled->draw2x2String(0, 2, _context->StopwatchAsCharArray());
}

void SecondPageState::Run(Command command)
{
    switch (command)
    {
    case Command::OneSecondTimerElapsedCommand:
        PrintStopwatch();
        break;
    case Command::ValidGpsDataCommand:
        PrintChangableData();
        break;
    case Command::InvalidGpsDataCommand:
        _context->TransitionTo(new InvalidState(Page::SecondPage));
        break;
    case Command::ButtonClickCommand:
        _context->TransitionTo(new ThirdPageState);
        break;
    case Command::ButtonLongPressCommand:
        _context->ResetData();
        break;
    default:
        break;
    }
}
