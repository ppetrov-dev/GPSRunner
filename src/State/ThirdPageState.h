#ifndef ThirdPageStateH
#define ThirdPageStateH

#include "StateBase.h"

class ThirdPageState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    ThirdPageState(Context *context) : StateBase(context)
    {
    }
};

void ThirdPageState::Run(Command command)
{
}

#endif //ThirdPageStateH