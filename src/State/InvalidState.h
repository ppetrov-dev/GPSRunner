#ifndef InvalidStateH
#define InvalidStateH

#include "StateBase.h"

class InvalidState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    InvalidState(Context *context) : StateBase(context)
    {
    }
};

void InvalidState::Run(Command command)
{
}

#endif //InvalidStateH