#ifndef ThirdPageStateH
#define ThirdPageStateH

#include <State/StateBase.h>

class ThirdPageState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    void Enter() override;
};

#endif //ThirdPageStateH
