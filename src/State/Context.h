#ifndef contextH
#define contextH

#include <settings.h>
#include <U8g2lib.h>
#include <MyGPS/MyGPS.h>
#include <State/StateBase.h>
class Context
{
private:
    StateBase *_state;

    void DisposeStateIfNeeded();

public:
    Context(MyGPS *myGPS);
    ~Context();
    void TransitionTo(StateBase *state);
    void Init();
    void Run(Command command);

    MyGPS *_myGPS;
    U8X8_SSD1306_128X64_NONAME_4W_SW_SPI *_oled;
};

#endif //contextH
