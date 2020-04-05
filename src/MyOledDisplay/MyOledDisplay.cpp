#include "MyOledDisplay.h"

MyOledDisplay::MyOledDisplay() : _oled(PIN_Display_Clock, PIN_Display_Data, PIN_Display_CS, PIN_Display_DC, PIN_Display_Reset)
{
}

void MyOledDisplay::Init()
{
    _oled.begin();
    _oled.setContrast(255);
    _oled.setFont(u8x8_font_8x13B_1x2_f);
}

void MyOledDisplay::PrintFirstPage()
{
    _oled.drawString(0, 0, "04.04");
    _oled.drawString(6, 0, "16:10");
    _oled.drawString(13, 0, "1/4");

    _oled.drawString(0, 2, "Spd: 123");
    _oled.drawString(11, 2, "(123)");

    _oled.drawString(0, 4, "Odo: 1234");

    _oled.drawString(0, 6, "Dst: 1.23");
    _oled.drawString(10, 6, "(1.23)");
}

void MyOledDisplay::PrintSecondPage()
{
    _oled.drawString(0, 0, "Avg: 45");
    _oled.drawString(13, 0, "2/4");

    _oled.draw2x2String(0, 2, "Spd: 123");
    _oled.drawString(0, 6, "Max: 123 km/h");
}
void MyOledDisplay::PrintThirdPage()
{
    _oled.drawString(0, 0, "Odo: 1234");
    _oled.drawString(13, 0, "3/4");

    _oled.draw2x2String(0, 2, "t: 2m 3s");
    _oled.drawString(0, 6, "Dst: 1234");
}

void MyOledDisplay::PrintFourthPage()
{
    _oled.drawString(13, 0, "4/4");
}

void MyOledDisplay::Print(State state)
{
    _oled.clearDisplay();
    switch (state)
    {
    case FirstPageState:
        PrintFirstPage();
        break;
    case SecondPageState:
        PrintSecondPage();
        break;
    case ThirdPageState:
        PrintThirdPage();
        break;
    case FourthPageState:
        PrintFourthPage();
        break;
    default:
        break;
    }
}