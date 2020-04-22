#ifndef InvalidStateH
#define InvalidStateH

#include <State/StateBase.h>

class InvalidState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    void Enter() override;
};
#endif //InvalidStateH
