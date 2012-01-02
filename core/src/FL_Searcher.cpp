#include "FL_Searcher.h"
#include "FL_ObjectList.h"

#include <iostream>

namespace Flurry
{

Searcher::Searcher
    (
    SigSearchDone::slot_type searchDoneSlot
    )
    : mSearchDoneSignal( NULL )
{
    mSearchDoneSignal = new SigSearchDone();
    mSearchDoneSignal->connect( searchDoneSlot );
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

void Searcher::reportSearchDone
    (
    const ObjectList results
    )
{
    (*mSearchDoneSignal)( results );
}

} // namespace Flurry
