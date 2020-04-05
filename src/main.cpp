#include <Arduino.h>
#include "OneButton.h"
#include "MyTimer.h"

#include "StateMachine/StateMachine.h"
#include "MyOledDisplay/MyOledDisplay.h"
#include "MyGPS/MyGPS.h"

OneButton _button = OneButton(PIN_Button, true, true);
StateMachine _stateMachine;
MyTimer _myTimer;
MyGPS* _myGPS = new MyGPS(GMT_HOURS, GMT_MINUTES);
MyOledDisplay _myOledDisplay = MyOledDisplay(_myGPS);

void OnStateChanged()
{
  auto state = _stateMachine.GetState();
  _myOledDisplay.Print(state);
}

void OnLongPress()
{
}

void OnTmerTick()
{
}

void setup()
{
  _myOledDisplay.Init();
  _button.attachClick([]() { _stateMachine.Run(ButtonClickCommand); });
  _button.attachLongPressStart(&OnLongPress);
  _stateMachine.AttachOnStateChanged(&OnStateChanged);
  _myTimer.AttachOnTick(&OnTmerTick);

  DEBUG_PORT.begin(9600);
  while (!DEBUG_PORT)
    ;

  //_display.Print(_stateMachine.GetState());
}

void loop()
{
  _button.tick();
  _myTimer.Tick();
}