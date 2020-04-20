#include "InitializingTitle.h"

void InitializingTitle::Next()
{
    ++_counter;
    if (_counter > 3)
        _counter = 0;
}

char *InitializingTitle::GetTitle()
{
    if (_counter == 0)
        return "Searching   ";
    if (_counter == 1)
        return "Searching.  ";
    if (_counter == 2)
        return "Searching.. ";
    if (_counter == 3)
        return "Searching...";

    return "Unknown";
}