#include "FL_SelectorSearcher.h"

#include "FL_Category.h"
#include "FL_CoreModule.h"

#include <iostream>

namespace Flurry
{

SelectorSearcher::SelectorSearcher
    (
    const std::string &text,
    const ObjectList &categories,
    const ObjectList &selectors
    )
    : mSearchText( text )
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
    #ifdef SEARCHER_DEBUG
        std::cout << "Selector Searcher Start" << std::endl;
    #endif
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
                #ifdef SEARCHER_DEBUG
                    std::cout << "Checking: " << sel.getTitle() << std::endl;
                #endif
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

    #ifdef SEARCHER_DEBUG
        std::cout << "Selector Searcher Done" << std::endl;
    #endif
    reportSearchDone( res );
}

} // namespace Flurry
