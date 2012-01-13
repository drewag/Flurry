#include "FL_ActionSearcher.h"

#include "FL_Category.h"
#include "FL_Action.h"
#include "FL_CoreModule.h"

#ifdef SEARCHER_DEBUG
    #include <iostream>
#endif

namespace Flurry
{

ActionSearcher::ActionSearcher
    (
    const std::string &text,
    const ObjectList &actions,
    const ObjectList &input
    )
    : mSearchText( text )
    , mActions( actions )
    , mInput( input )
{
}

ActionSearcher::ActionSearcher
    (
    const ActionSearcher &other
    )
    : Searcher( other )
    , mSearchText( other.mSearchText )
    , mActions( other.mActions )
    , mInput( other.mInput )
{
}

ActionSearcher::~ActionSearcher()
{
}

/* virtual */ void ActionSearcher::operator()()
{
    #ifdef SEARCHER_DEBUG
        std::cout << "Action Searcher Start" << std::endl;
    #endif
    ObjectList res;

    ObjectList::const_iterator actItr;
    for( actItr = mActions.begin(); mActions.end() != actItr; actItr++ )
    {
        Action sel = *actItr;
    }

    #ifdef SEARCHER_DEBUG
        std::cout << "Action Searcher Done" << std::endl;
    #endif
    reportSearchDone( res );
}

} // namespace Flurry
