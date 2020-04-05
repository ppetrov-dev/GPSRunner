#ifndef myOledDisplayH
#define myOledDisplayH

#include "enums.h"
#include "settings.h"
#include <U8g2lib.h>
#include "MyGPS/MyGPS.h"

class MyOledDisplay
{
private:
    MyGPS* _myGPS;
    U8X8_SSD1306_128X64_NONAME_4W_SW_SPI _oled;

    void PrintFirstPage();
    void PrintSecondPage();
    void PrintThirdPage();
    void PrintFourthPage();

public:
    MyOledDisplay(MyGPS* myGPS);
    void Init();

    void Print(State state);
};
#endif //myOledDisplayH