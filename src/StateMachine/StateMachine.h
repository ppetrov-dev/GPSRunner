#ifndef stateMachineH
#define stateMachineH

#include "enums.h"
#include "settings.h"

class StateMachine
{
private:
    callback _onStateChangedCallback;
    enum State _state = Initializing;

    State GetNextState();
    State GetPreviousState();
    void MoveNextState(void);
    void MovePreviousState(void);
    void SetState(State newState);
    void HandleButtonClick();
    void HandleButtonLongPress();
    void HandleGpsValidCommand();

public:
    void Run(Command command);
    State GetState();

    void AttachOnStateChanged(callback callback);
};

#endif //stateMachineH