#ifndef SearchingStateH
#define SearchingStateH

#include "StateBase.h"

class SearchingState : public StateBase
{
private:
    /* data */
public:
    SearchingState(Context *context) : StateBase(context)
    {
    }
    void Run(Command command) override;
};

void SearchingState::Run(Command command)
{
}

#endif //SearchingStateH