#include <Arduino.h> //TODO: should be removed
#include <State/ReadyPageState.h>
#include <State/SearchingPageState.h>
#include <State/Context.h>
// #include <MyConverter.h>

void SearchingPageState::Enter()
{
     auto display = _context->_oled;
    // auto gps = _context->_myGPS;

     display->drawString(0, 0, _searchingText->GetText());

    // auto satellites = "Sats: " + String(gps->GetSatellitesCount());
    // auto satellitesCharArray = MyConverter::StringToCharArray(satellites);
    // display->draw2x2String(0, 2, satellitesCharArray);
}
void SearchingPageState::Run(Command command)
{
    if (command == Command::HalfSecondTimerTickCommand)
    {
        _searchingText->Next();
        Enter();
        if (_context->_myGPS->GetIsValid())
            _context->TransitionTo(new ReadyPageState);
    }
}
