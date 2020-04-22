#ifndef SearchingPageStateH
#define SearchingPageStateH

#include <State/StateBase.h>
#include <SearchingText.h>
class SearchingPageState : public StateBase
{
private:
    SearchingText *_searchingText;

public:
    SearchingPageState()
    {
        _searchingText = new SearchingText();
    }
    ~SearchingPageState()
    {
        delete _searchingText;
    }
    void Enter() override;
    void Run(Command command) override;
};

#endif //SearchingPageStateH
