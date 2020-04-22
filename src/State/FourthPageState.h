#ifndef FourthPageStateH
#define FourthPageStateH

#include "StateBase.h"

class FourthPageState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    FourthPageState(Context *context) : StateBase(context)
    {
    }
};

void FourthPageState::Run(Command command)
{
}

#endif //FourthPageStateH