#ifndef SearchingPageStateH
#define SearchingPageStateH

#include <State/StateBase.h>
#include <AnimatedDots.h>
class SearchingPageState : public StateBase
{
private:
    AnimatedDots _animatedDots;

public:
    void PrintDots();
    void PrintSats();
    void Enter() override;
    void Run(Command command) override;
};

#endif //SearchingPageStateH
