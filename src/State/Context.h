#ifndef contextH
#define contextH

#include "State/StateBase.h"
#include "enums.h"

class Context
{
private:
    StateBase *_state;
    void DisposeStateIfNeeded();

public:
    Context();
    ~Context();
    void TransitionTo(StateBase *state);
    void Run(Command command);
};

Context::Context() : _state(nullptr)
{
}

Context::~Context()
{
    DisposeStateIfNeeded();
}
void Context::DisposeStateIfNeeded()
{
    if (_state == nullptr)
        return;
        
    delete _state;
}
void Context::Run(Command command)
{
    if(_state == nullptr)
        return;

    _state->Run(command);
}
void Context::TransitionTo(StateBase *state)
{
    DisposeStateIfNeeded();
    _state = state;
}
#endif //contextH
