#include "FL_Searcher.h"
#include "FL_ObjectList.h"

#include <iostream>

namespace Flurry
{

Searcher::Searcher()
{
    mSearchDoneSignal = new SigSearchDone();
}

Searcher::Searcher
    (
    const Searcher &other
    )
    : mSearchDoneSignal( other.mSearchDoneSignal )
{
}

Searcher::~Searcher()
{
}

boost::signals2::connection Searcher::connectSearchDone
    (
    SigSearchDone::slot_type searchDoneSlot
    )
{
    return mSearchDoneSignal->connect( searchDoneSlot );
}

void Searcher::reportSearchDone
    (
    const ObjectList results
    )
{
    (*mSearchDoneSignal)( *this, results );
}

} // namespace Flurry
