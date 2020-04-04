#include <Arduino.h>
#include "OneButton.h"
#include "MyTimer.h"

#include "StateMachine/StateMachine.h"
#include "Display/Display.h"
#include "MyGPS/MyGPS.h"

Display _display;
OneButton _button = OneButton(PIN_Button, true, true);
StateMachine _stateMachine;
MyTimer _myTimer;
MyGPS *_myGPS = new MyGPS(GMT_HOURS, GMT_MINUTES);

void OnStateChanged()
{
  auto state = _stateMachine.GetState();
  _display.Print(state);
}

void OnLongPress()
{
}

void OnTmerTick()
{
}

void setup()
{
  _display.Init();
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