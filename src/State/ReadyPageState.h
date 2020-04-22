#ifndef ReadyPageStateH
#define ReadyPageStateH

#include <State/StateBase.h>
#include <LongPressButtonText.h>

class ReadyPageState : public StateBase
{
private:
    LongPressButtonText *_longPressButtonText = new LongPressButtonText();
    void PrintLongPressButtonText();
    public:
        ~ReadyPageState()
        {
            delete _longPressButtonText;
        }
        void Run(Command command) override;
        void Enter() override;
    };
#endif //ReadyPageStateH