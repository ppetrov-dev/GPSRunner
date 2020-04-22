#ifndef SearchingTextH
#define SearchingTextH

class SearchingText
{
private:
    int _counter = 0;

public:
    void Next()
    {
        ++_counter;
        if (_counter > 3)
            _counter = 0;
    }

    char *GetText()
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
};

#endif //SearchingTextH