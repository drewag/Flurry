#include "FL_SelectorSearcher.h"

#include "FL_Category.h"
#include "FL_CoreModule.h"

#include <iostream>

namespace Flurry
{

SelectorSearcher::SelectorSearcher
    (
    SigSearchDone::slot_type searchDoneSlot,
    const std::string &text,
    const ObjectList &categories,
    const ObjectList &selectors
    )
    : Searcher( searchDoneSlot )
    , mSearchText( text )
    , mCategories( categories )
    , mSelectors( selectors )
{
}

SelectorSearcher::SelectorSearcher
    (
     const SelectorSearcher &other
    )
    : Searcher( other )
    , mSearchText( other.mSearchText )
    , mCategories( other.mCategories )
    , mSelectors( other.mSelectors )
{
}

SelectorSearcher::~SelectorSearcher()
{
}

/* virtual */ void SelectorSearcher::operator()()
{
    ObjectList res;

    ObjectList::const_iterator selItr;
    selItr = mSelectors.begin();
    while( mSelectors.end() != selItr )
    {
        Selector sel = *selItr;
        if( sel.doesObjectMatch( mSearchText, CoreModule::namedSelector() ) )
        {
            ObjectList::const_iterator catItr;
            catItr = mCategories.begin();
            while( mCategories.end() != catItr )
            {
                Category cat = *catItr;
                if( !sel.doesSupportCategory( cat ) )
                {
                    break;
                }
                catItr++;
            }

            if( mCategories.end() == catItr )
            {
                res.add( sel );
            }
        }
        selItr++;
    }

    reportSearchDone( res );
}

} // namespace Flurry
