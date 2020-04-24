
#include <State/Context.h>
#include <State/SearchingPageState.h>

Context::Context(MyGPS *myGPS) : _state(nullptr), _myGPS(myGPS)
{
    _oled = new U8X8_SSD1306_128X64_NONAME_4W_SW_SPI(PIN_Display_Clock,
                                                     PIN_Display_Data,
                                                     PIN_Display_CS,
                                                     PIN_Display_DC,
                                                     PIN_Display_Reset);
}

void Context::SaveStartLocation()
{
    _startLocation = _myGPS->GetCurrentLocation();
}
void Context::Init()
{
    _oled->setContrast(255);
    _oled->setFont(u8x8_font_8x13B_1x2_f);
    _oled->begin();

    TransitionTo(new SearchingPageState);
}

Context::~Context()
{
    delete _oled;
    DisposeStateIfNeeded();
}
void Context::DisposeStateIfNeeded()
{
    if (_state == nullptr)
        return;

    delete _state;
}
void Context::Run(Command command)
{
    if (_state == nullptr)
        return;

    _state->Run(command);
}
void Context::TransitionTo(StateBase *state)
{
    DisposeStateIfNeeded();
    _state = state;
    if (_state == nullptr)
        return;
    _oled->clearDisplay();
    _state->SetContext(this);
    _state->Enter();
}
