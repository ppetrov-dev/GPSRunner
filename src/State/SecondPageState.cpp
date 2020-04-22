#include <State/ThirdPageState.h>
#include <State/SecondPageState.h>
#include <State/Context.h>

void SecondPageState::Enter()
{
    auto display = _context->_oled;
    display->drawString(0, 0, "Avg: 45");
    display->drawString(13, 0, "2/4");

    display->draw2x2String(0, 2, "Spd: 123");
    display->drawString(0, 6, "Max: 123 km/h");
}
void SecondPageState::Run(Command command)
{
    if (command == Command::ButtonClickCommand)
    {
        _context->TransitionTo(new ThirdPageState);
    }
}