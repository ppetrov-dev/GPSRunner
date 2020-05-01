#include <State/InvalidState.h>
#include <State/Context.h>
#include <State/FirstPageState.h>
#include <State/SecondPageState.h>
#include <State/ThirdPageState.h>
#include <State/FourthPageState.h>
#include <State/SearchingPageState.h>

InvalidState::InvalidState(Page returnPage) : _returnPage(returnPage)
{
}

StateBase *InvalidState::GetReturnPageState()
{
    switch (_returnPage)
    {
    case Page::FirstPage:
        return new FirstPageState();
        break;
    case Page::SecondPage:
        return new SecondPageState();
        break;
    case Page::ThirdPage:
        return new ThirdPageState();
        break;
    case Page::FourthPage:
        return new FourthPageState();
    default:
        return new InvalidState(_returnPage);
    }
}

void InvalidState::Enter()
{
    auto display = _context->_oled;
    display->drawString(0, 0, "No GPS Signal");
    PrintAnimatedDots();

    display->drawString(0, 2, "Wait for restore");
    display->drawString(0, 4, "Or Long press to");
    display->drawString(0, 6, "Searching page");
}
void InvalidState::PrintAnimatedDots()
{
    _context->_oled->drawString(13, 0, _animatedDots.Get());
}

void InvalidState::Run(Command command)
{
    switch (command)
    {
    case Command::HalfSecondTimerElapsedCommand:
        _animatedDots.Next();
        PrintAnimatedDots();
        break;
    case Command::ValidGpsDataCommand:
        _context->TransitionTo(GetReturnPageState());
        break;
    case Command::ButtonLongPressCommand:
        _context->TransitionTo(new SearchingPageState);
        break;
    default:
        break;
    }
}