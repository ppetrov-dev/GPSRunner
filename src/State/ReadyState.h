#ifndef readyStateH
#define readyStateH

#include "State/StateBase.h"
#include "State/Context.h"

class ReadyState : public StateBase
{
private:
    /* data */
public:
    ReadyState(Context *context) : StateBase(context)
    {
    }
    void Run(Command command) override;
};

void ReadyState::Run(Command command)
{
}

#endif //readyStateH