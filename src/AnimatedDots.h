#ifndef AnimatedDotsH
#define AnimatedDotsH

class AnimatedDots
{
private:
    char _counter = 0;

public:
    void Next()
    {
        ++_counter;
        if (_counter > 3)
            _counter = 0;
    }

    const char *Get()
    {
        if (_counter == 0)
            return (const char *)"   ";
        if (_counter == 1)
            return (const char *)".  ";
        if (_counter == 2)
            return (const char *)".. ";

        return (const char *)"...";
    }
};

#endif //AnimatedDotsH