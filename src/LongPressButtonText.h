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

    char *GetText()
    {
        if (_isOn)
            return "<Long press btn>";

        return "                ";
    }
};

#endif //LongPressButtonTextH