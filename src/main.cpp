#include <OneButton.h>
#include <MyTimer.h>
#include <MyGPS/MyGPS.h>
#include <State/Context.h>

OneButton _button = OneButton(PIN_Button, true, true);
MyTimer _halfSecondTimer;
MyGPS *_myGPS = new MyGPS(GMT_HOURS, GMT_MINUTES);
Context *_context = new Context(_myGPS);

void setup()
{
  DEBUG_PORT.begin(9600);
  while (!DEBUG_PORT)
    ;

  _context->Init();
  _button.attachClick([]() { _context->Run(Command::ButtonClickCommand); });
  _button.attachLongPressStart([]() { _context->Run(Command::ButtonLongPressCommand); });
  _halfSecondTimer.SetInterval(500);
  _halfSecondTimer.AttachOnTick([]() { _context->Run(Command::HalfSecondTimerTickCommand); });

  _halfSecondTimer.Start();
}

void loop()
{
  _myGPS->ReadWhileAvailable();
  _button.tick();
  _halfSecondTimer.Tick();
}