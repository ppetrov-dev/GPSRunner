#include <OneButton.h>
#include <MyTimer.h>
#include <MyGPS/MyGPS.h>
#include <State/Context.h>

OneButton _button = OneButton(PIN_Button, true, true);
MyTimer _halfSecondTimer;
MyTimer _oneSecondTimer;
MyGPS *_myGPS = new MyGPS(GMT_HOURS, GMT_MINUTES);
Context *_context = new Context(_myGPS);

void OnHalfSecondTimerElapsed()
{
  _context->Run(Command::HalfSecondTimerTickCommand);
  _context->Run(_myGPS->GetIsValid() ? Command::ValidGpsDataCommand : Command::InvalidGpsDataCommand);
}

void setup()
{
  DEBUG_PORT.begin(9600);
  while (!DEBUG_PORT)
    ;

  _context->Init();
  _button.attachClick([]() { _context->Run(Command::ButtonClickCommand); });
  _button.attachLongPressStart([]() { _context->Run(Command::ButtonLongPressCommand); });
  _oneSecondTimer.SetInterval(1000);
  _oneSecondTimer.AttachOnElapsed([]() { _context->Run(Command::OneSecondTimerTickCommand); });
  _halfSecondTimer.SetInterval(500);
  _halfSecondTimer.AttachOnElapsed(&OnHalfSecondTimerElapsed);

  _oneSecondTimer.Start();
  _halfSecondTimer.Start();
}

void loop()
{
  _myGPS->ReadWhileAvailable();
  _button.tick();
  _halfSecondTimer.Tick();
  _oneSecondTimer.Tick();
}