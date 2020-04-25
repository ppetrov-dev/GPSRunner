#include <State/ReadyPageState.h>
#include <State/SearchingPageState.h>
#include <State/Context.h>

void SearchingPageState::Enter()
{
    _context->_oled->drawString(0, 0, "Searching");
    PrintDots();
    _context->_oled->draw2x2String(0, 2, "Sats: ");
    PrintSats();
}
void SearchingPageState::PrintDots()
{
    _context->_oled->drawString(9, 0, _animatedDots.Get());
}

void SearchingPageState::PrintSats()
{
    _context->_oled->draw2x2String(11, 2, _context->SatellitesCountAsCharArray());
}
void SearchingPageState::Run(Command command)
{
    switch (command)
    {
    case Command::HalfSecondTimerTickCommand:
        _animatedDots.Next();
        PrintDots();
        PrintSats();
        break;
    case Command::ValidGpsDataCommand:
        _context->TransitionTo(new ReadyPageState);
        break;
    default:
        break;
    }
}