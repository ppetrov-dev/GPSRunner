#include <State/FourthPageState.h>
#include <State/ThirdPageState.h>
#include <State/Context.h>

void ThirdPageState::Enter()
{
    auto display = _context->_oled;
    display->drawString(0, 0, "Odo: 1234");
    display->drawString(13, 0, "3/4");

    display->draw2x2String(0, 2, "t: 2m 3s");
    display->drawString(0, 6, "Dst: 1234");
}
void ThirdPageState::Run(Command command)
{
    if (command == Command::ButtonClickCommand)
    {
        _context->TransitionTo(new FourthPageState);
    }
}
