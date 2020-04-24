#ifndef LongPressButtonTextH
#define LongPressButtonTextH

class LongPressButtonText
{
private:
    bool _isOn = false;

public:
    void Next()
    {
        _isOn = !_isOn;
    }

    const char *GetText()
    {
        return (const char *)(_isOn
                                  ? "<Long press btn>"
                                  : "                ");
    }
};

#endif //LongPressButtonTextH