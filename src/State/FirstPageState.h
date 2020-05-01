#ifndef FirstPageStateH
#define FirstPageStateH

#include <State/StateBase.h>

class FirstPageState : public StateBase
{
private:
    void PrintChangableData();
public:
    void Run(Command command) override;
    void Enter() override;
};

#endif //FirstPageStateH