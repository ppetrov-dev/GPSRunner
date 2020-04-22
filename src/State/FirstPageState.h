#ifndef FirstPageStateH
#define FirstPageStateH

#include "StateBase.h"

class FirstPageState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    FirstPageState(Context *context) : StateBase(context)
    {
    }
};

void FirstPageState::Run(Command command)
{
}

#endif //FirstPageStateH