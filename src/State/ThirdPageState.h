#ifndef ThirdPageStateH
#define ThirdPageStateH

#include <State/StateBase.h>

class ThirdPageState : public StateBase
{
private:
    void PrintChangableData();
    void PrintStopWatch();

public:
    void Run(Command command) override;
    void Enter() override;
};
#endif //ThirdPageStateH