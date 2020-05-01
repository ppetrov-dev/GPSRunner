#ifndef enumsH
#define enumsH

enum Command
{
  ButtonClickCommand,
  ButtonDoubleClickCommand,
  ButtonLongPressCommand,
  HalfSecondTimerElapsedCommand,
  OneSecondTimerElapsedCommand,
  _200msTimerElapsedCommand,
  ValidGpsDataCommand,
  InvalidGpsDataCommand,
};

enum Page{
  FirstPage,
  SecondPage,
  ThirdPage,
  FourthPage
};

#endif