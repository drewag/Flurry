#include "FL_MultiSearcher.h"

#include "FL_Category.h"

#ifdef SEARCHER_DEBUG
#include <iostream>
#endif

namespace Flurry
{

MultiSearcher::MultiSearcher()
{
}

MultiSearcher::MultiSearcher
    (
     const MultiSearcher &other
    )
    : Searcher( other )
    , mSubSearchers( other.mSubSearchers )
    , mSearchesLeftToComplete( 0 )
{
}

MultiSearcher::~MultiSearcher()
{
}

void MultiSearcher::addSearcher
    (
    Searcher* searcher
    )
{
    searcher->connectSearchDone( boost::bind( &MultiSearcher::subSearchIsDone, this, _1, _2  ) );
    boost::shared_ptr<Searcher> ptr( searcher );
    mSubSearchers.push_front( ptr );
}

void MultiSearcher::subSearchIsDone
    (
    const Searcher &searcher,
    const ObjectList results
    )
{
    mSearchesLeftToComplete--;
    #ifdef SEARCHER_DEBUG
        std::cout << "Sub-search Done: " << mSearchesLeftToComplete << " left" << std::endl;
    #endif

    mResults.add( results );

    if( 0 == mSearchesLeftToComplete )
    {
        #ifdef SEARCHER_DEBUG
            std::cout << "Multi Searcher Done" << std::endl;
        #endif
        this->reportSearchDone( mResults );
    }
}

/* virtual */ void MultiSearcher::operator()()
{
    mSearchesLeftToComplete = mSubSearchers.size();
    #ifdef SEARCHER_DEBUG
        std::cout << "Multi Searcher Start: " << mSearchesLeftToComplete << " to search" << std::endl;
    #endif
    if( 0 == mSearchesLeftToComplete )
    {
        #ifdef SEARCHER_DEBUG
            std::cout << "No Searchers" << std::endl;
        #endif
        this->reportSearchDone( ObjectList() );
        return;
    }
    std::list<SharedSearcher>::iterator itr;
    for( itr = mSubSearchers.begin(); mSubSearchers.end() != itr; itr++ )
    {
        (**itr)();
    }
}

} // namespace Flurry
