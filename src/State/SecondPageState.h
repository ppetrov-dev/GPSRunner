#ifndef SecondPageStateH
#define SecondPageStateH

#include <State/StateBase.h>

class SecondPageState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    void Enter() override;
};

#endif //SecondPageStateH