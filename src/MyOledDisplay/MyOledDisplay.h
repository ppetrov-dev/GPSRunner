#ifndef myOledDisplayH
#define myOledDisplayH

#include "enums.h"
#include "settings.h"
#include <U8g2lib.h>
#include "MyGPS/MyGPS.h"
#include "InitializingTitle/InitializingTitle.h"
#include "MyConverter.h"

class MyOledDisplay
{
private:
    MyGPS* _myGPS;
    InitializingTitle *_initializingTitle;
    U8X8_SSD1306_128X64_NONAME_4W_SW_SPI _oled;
    void PrintFirstPage();
    void PrintSecondPage();
    void PrintThirdPage();
    void PrintFourthPage();

public:
    MyOledDisplay(MyGPS *myGPS, InitializingTitle *initializingTitle);
    void Init();

    void PrintReadyPage();
    void PrintInitalizingPage();
    void Print(State state);
};
#endif //myOledDisplayH