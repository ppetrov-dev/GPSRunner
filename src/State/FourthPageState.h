#ifndef FourthPageStateH
#define FourthPageStateH

#include <State/StateBase.h>

class FourthPageState : public StateBase
{
private:
    /* data */
public:
    void Run(Command command) override;
    void Enter() override;
};
#endif //FourthPageStateH
