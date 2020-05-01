#ifndef InvalidStateH
#define InvalidStateH

#include <State/StateBase.h>
#include <AnimatedDots.h>

class InvalidState : public StateBase
{
private:
    Page _returnPage;
    AnimatedDots _animatedDots;
    StateBase* GetReturnPageState();
    void PrintAnimatedDots();

    public:
        InvalidState(Page returnPage);
        void Run(Command command) override;
        void Enter() override;
    };

#endif //InvalidStateH