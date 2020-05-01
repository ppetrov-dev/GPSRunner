#ifndef LongPressButtonTextH
#define LongPressButtonTextH

class LongPressButtonText
{
private:
    int _counter = 0;
    const char **_animatingArray;

public:
    LongPressButtonText()
    {
        _animatingArray = new const char *[28] {
            "Long press butto",
                "ong press button",
                "ng press button ",
                "g press button t",
                " press button to",
                "press button to ",
                "ress button to s",
                "ess button to st",
                "ss button to sta",
                "s button to star",
                " button to start",
                "button to start.",
                "utton to start. ",
                "tton to start. L",
                "ton to start. Lo",
                "on to start. Lon",
                "n to start. Long",
                " to start. Long ",
                "to start. Long p",
                "o start. Long pr",
                " start. Long pre",
                "start. Long pres",
                "tart. Long press",
                "art. Long press ",
                "rt. Long press b",
                "t. Long press bu",
                ". Long press but",
                " Long press butt",
        };
    }
    ~LongPressButtonText()
    {
        delete[] _animatingArray;
    }
    void Next()
    {
        _counter++;
        if (_counter >= 28)
            _counter = 0;
    }

    const char *GetText()
    {
        return _animatingArray[_counter];
    }
};

#endif //LongPressButtonTextH