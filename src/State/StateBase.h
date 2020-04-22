#ifndef stateBaseH
#define stateBaseH

#include "State/Context.h"
class Context;
class StateBase
{
protected:
    Context *_context;

public:
    virtual void Run(Command command) = 0;
    StateBase(Context *context) : _context(context)
    {
    }
};
#endif //stateBaseH