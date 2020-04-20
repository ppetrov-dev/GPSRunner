#include "StateMachine.h"

void StateMachine::Run(Command command)
{
    switch (command)
    {
    case Command::ButtonClickCommand:
        HandleButtonClick();
        break;
    case Command::ButtonLongPressCommand:
        HandleButtonLongPress();
    case Command::GpsValidCommand:
        HandleGpsValidCommand();
        break;
        break;
    default:
        break;
    }
}
State StateMachine::GetState()
{
    return _state;
}
void StateMachine::HandleGpsValidCommand()
{
    if (_state != State::Initializing)
        return;

    SetState(State::Ready);
}
void StateMachine::HandleButtonClick()
{
    MoveNextState();
}
void StateMachine::HandleButtonLongPress()
{
    if (_state != State::Ready)
        return;
    SetState(State::FirstPageState);
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
    case State::Initializing:
        return State::Initializing;
    case State::Ready:
        return State::Ready;

    case State::FirstPageState:
        return State::SecondPageState;
    case State::SecondPageState:
        return ThirdPageState;
    case State::ThirdPageState:
        return State::FourthPageState;
    case State::FourthPageState:
        return State::FirstPageState;
    }
    return State::InvalidState;
}
State StateMachine::GetPreviousState()
{
    switch (_state)
    {
    case State::Initializing:
        return State::Initializing;
    case State::Ready:
        return State::Ready;

    case State::FirstPageState:
        return State::FourthPageState;
    case State::SecondPageState:
        return State::FirstPageState;
    case State::ThirdPageState:
        return State::SecondPageState;
    case State::FourthPageState:
        return State::ThirdPageState;
    }
    return State::InvalidState;
}

void StateMachine::AttachOnStateChanged(callback callback)
{
    _onStateChangedCallback = callback;
}
