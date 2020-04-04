#include "StateMachine.h"

void StateMachine::Run(Command command)
{
    switch (command)
    {
    case ButtonClickCommand:
        HandleButtonClick();
        break;
    default:
        break;
    }
}
State StateMachine::GetState()
{
    return _state;
}
void StateMachine::HandleButtonClick()
{
    MoveNextState();
}

void StateMachine::SetState(State newState)
{
    if (_state == newState)
        return;

    _state = newState;

    if (_onStateChangedCallback)
        _onStateChangedCallback();
}
void StateMachine::MoveNextState()
{
    SetState(GetNextState());
}
void StateMachine::MovePreviousState()
{
    SetState(GetPreviousState());
}
State StateMachine::GetNextState()
{
    switch (_state)
    {
    case FirstPageState:
        return SecondPageState;
    case SecondPageState:
        return ThirdPageState;
    case ThirdPageState:
        return FourthPageState;
    case FourthPageState:
        return FirstPageState;
    }
    return InvalidState;
}
State StateMachine::GetPreviousState()
{
    switch (_state)
    {
    case FirstPageState:
        return FourthPageState;
    case SecondPageState:
        return FirstPageState;
    case ThirdPageState:
        return SecondPageState;
    case FourthPageState:
        return ThirdPageState;
    }
    return InvalidState;
}

void StateMachine::AttachOnStateChanged(callback callback)
{
    _onStateChangedCallback = callback;
}
