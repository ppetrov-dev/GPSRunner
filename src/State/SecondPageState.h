#ifndef SecondPageStateH
#define SecondPageStateH

#include "StateBase.h"

class SecondPageState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    SecondPageState(Context *context) : StateBase(context)
    {
    }
};

void SecondPageState::Run(Command command)
{
}

#endif //SecondPageStateH