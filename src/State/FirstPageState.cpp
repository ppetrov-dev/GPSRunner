#include <State/FirstPageState.h>
#include <State/SecondPageState.h>
#include <State/Context.h>

void FirstPageState::Enter()
{
    auto display = _context->_oled;
    //  _myGPS->GetDateTime()
    display->drawString(0, 0, "04.04");
    display->drawString(6, 0, "16:10");

    display->drawString(13, 0, "1/4");

    display->drawString(0, 2, "Spd: 123");
    display->drawString(11, 2, "(123)");

    display->drawString(0, 4, "Odo: 1234");

    display->drawString(0, 6, "Dst: 1.23");
    display->drawString(10, 6, "(1.23)");
}

void FirstPageState::Run(Command command)
{
    if (command == Command::ButtonClickCommand)
    {
        _context->TransitionTo(new SecondPageState);
    }
}
