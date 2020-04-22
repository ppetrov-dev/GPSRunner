#include <State/FourthPageState.h>
#include <State/FirstPageState.h>
#include <State/Context.h>

void FourthPageState::Enter()
{
    auto display = _context->_oled;
    display->drawString(13, 0, "4/4");
}
void FourthPageState::Run(Command command)
{
    if (command == Command::ButtonClickCommand)
    {
        _context->TransitionTo(new FirstPageState);
    }
}