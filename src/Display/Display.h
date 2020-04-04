#ifndef displayH
#define displayH

#include <U8g2lib.h>
#include "enums.h"
#include "settings.h"

class Display
{
private:
    U8X8_SSD1306_128X64_NONAME_4W_SW_SPI _oled;

    void PrintFirstPage();
    void PrintSecondPage();
    void PrintThirdPage();
    void PrintFourthPage();

public:
    Display();
    void Init();

    void Print(State state);
};
#endif