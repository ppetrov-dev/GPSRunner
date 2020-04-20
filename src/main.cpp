#include <Arduino.h>
#include "OneButton.h"
#include "MyTimer.h"

#include "InitializingTitle/InitializingTitle.h"
#include "StateMachine/StateMachine.h"
#include "MyOledDisplay/MyOledDisplay.h"
#include "MyGPS/MyGPS.h"

OneButton _button = OneButton(PIN_Button, true, true);
StateMachine _stateMachine;
MyTimer _halfSecondTimer;
MyGPS *_myGPS = new MyGPS(GMT_HOURS, GMT_MINUTES);
InitializingTitle _initializingTitle;
MyOledDisplay _myOledDisplay = MyOledDisplay(_myGPS, &_initializingTitle);

void OnStateChanged()
{
  auto state = _stateMachine.GetState();
  _myOledDisplay.Print(state);
}

void OnClick()
{
  _stateMachine.Run(Command::ButtonClickCommand);
}
void OnLongPress()
{
  _stateMachine.Run(Command::ButtonLongPressCommand);
}

void OnHalfSecondTimerTick()
{
  auto state = _stateMachine.GetState();
  if (state == State::Initializing)
  {
    _myOledDisplay.PrintInitalizingPage();

    if (_myGPS->GetIsValid())
      _stateMachine.Run(Command::GpsValidCommand);
  }
  if (state == State::Ready)
    _myOledDisplay.PrintReadyPage();
}
void setup()
{
  _myOledDisplay.Init();
  _button.attachClick(&OnClick);
  _button.attachLongPressStart(&OnLongPress);
  _stateMachine.AttachOnStateChanged(&OnStateChanged);
  _halfSecondTimer.SetInterval(500);
  _halfSecondTimer.AttachOnTick(&OnHalfSecondTimerTick);

  DEBUG_PORT.begin(9600);
  while (!DEBUG_PORT)
    ;

  _halfSecondTimer.Start();
}

void loop()
{
  _myGPS->ReadWhileAvailable();
  _button.tick();
  _halfSecondTimer.Tick();
}