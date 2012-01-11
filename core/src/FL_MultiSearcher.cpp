#include "FL_MultiSearcher.h"

#include "FL_Category.h"

#include <iostream>

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
    mSearchesLeftToComplete++;
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

    mResults.add( results );

    if( 0 == mSearchesLeftToComplete )
    {
        this->reportSearchDone( mResults );
    }
}

/* virtual */ void MultiSearcher::operator()()
{
    
    std::list<SharedSearcher>::iterator itr;
    for( itr = mSubSearchers.begin(); mSubSearchers.end() != itr; itr++ )
    {
        (**itr)();
    }
}

} // namespace Flurry
