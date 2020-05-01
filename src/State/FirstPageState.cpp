#include <State/SecondPageState.h>
#include <State/FirstPageState.h>
#include <State/InvalidState.h>
#include <State/Context.h>

void FirstPageState::Enter()
{
    auto display = _context->_oled;
    display->drawString(0, 0, "Avg:");
    display->drawString(13, 0, "1/4");
    display->drawString(11, 3, "km/h");
    display->drawString(0, 6, "Max:");
    display->drawString(9, 6, "km/h");

    PrintChangableData();
}
void FirstPageState::PrintChangableData()
{
    register auto display = _context->_oled;

    display->drawString(4, 0, _context->AverageSpeedKmhAsCharArray());
    display->draw2x2String(0, 2, _context->SpeedKmhAsCharArray());
    display->drawString(4, 6, _context->MaxSpeedKmhAsCharArray());
}
void FirstPageState::Run(Command command)
{
    switch (command)
    {
    case Command::ValidGpsDataCommand:
        PrintChangableData();
        break;
    case Command::InvalidGpsDataCommand:
        _context->TransitionTo(new InvalidState(Page::FirstPage));
         break;
    case Command::ButtonClickCommand:
        _context->TransitionTo(new SecondPageState);
        break;
    case Command::ButtonLongPressCommand:
        _context->ResetData();
        break;
    default:
        break;
    }
}