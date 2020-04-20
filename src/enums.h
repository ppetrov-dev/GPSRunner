#ifndef enumsH
#define enumsH

enum State
{
  Initializing,
  Ready,
  FirstPageState,
  SecondPageState,
  ThirdPageState,
  FourthPageState,
  InvalidState
};

enum Command
{
  ButtonClickCommand,
  ButtonLongPressCommand,
  GpsValidCommand,
};

#endif