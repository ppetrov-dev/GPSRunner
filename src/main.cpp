#include <OneButton.h>
#include <MyTimer.h>
#include <MyGPS/MyGPS.h>
#include <State/Context.h>

OneButton _button = OneButton(PIN_Button, true, true);
MyTimer _halfSecondTimer;
MyTimer _oneSecondTimer;
MyTimer _200msTimer;
MyGPS *_myGPS = new MyGPS(GMT_HOURS, GMT_MINUTES);
Context *_context = new Context(_myGPS);

void OnHalfSecondTimerElapsed()
{
  if (_myGPS->GetIsValid())
  {
    _context->UpdateData();
    _context->Run(Command::ValidGpsDataCommand);
  }
  else
    _context->Run(Command::InvalidGpsDataCommand);
  _context->Run(Command::HalfSecondTimerElapsedCommand);
}

void setup()
{
  DEBUG_PORT.begin(9600);
  while (!DEBUG_PORT)
    ;

  _context->Init();
  _button.attachClick([]() { _context->Run(Command::ButtonClickCommand); });
  _button.attachLongPressStart([]() { _context->Run(Command::ButtonLongPressCommand); });
  _button.attachDoubleClick([]() { _context->Run(Command::ButtonDoubleClickCommand); });
  _oneSecondTimer.SetInterval(1000);
  _oneSecondTimer.AttachOnElapsed([]() { _context->Run(Command::OneSecondTimerElapsedCommand); });
  _halfSecondTimer.SetInterval(500);
  _halfSecondTimer.AttachOnElapsed(&OnHalfSecondTimerElapsed);
  _200msTimer.SetInterval(200);
  _200msTimer.AttachOnElapsed([]() { _context->Run(Command::_200msTimerElapsedCommand); });

  _oneSecondTimer.Start();
  _halfSecondTimer.Start();
  _200msTimer.Start();
}

void loop()
{
  _myGPS->ReadWhileAvailable();
  _button.tick();
  _halfSecondTimer.Tick();
  _oneSecondTimer.Tick();
  _200msTimer.Tick();
}