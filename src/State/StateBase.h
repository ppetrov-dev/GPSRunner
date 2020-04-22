#ifndef stateBaseH
#define stateBaseH

#include <enums.h>
class Context;
class StateBase
{
protected:
    Context *_context;

public:
    virtual ~StateBase(){

    } 
    virtual void Run(Command command) = 0;
    virtual void Enter() = 0;
    void SetContext(Context *context)
    {
        _context = context;
    }
};
#endif //stateBaseH