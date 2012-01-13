#include "FL_ObjectSearcher.h"

#include "FL_Category.h"

#ifdef SEARCHER_DEBUG
#include <iostream>
#endif

namespace Flurry
{

ObjectSearcher::ObjectSearcher
    (
    const std::string &text,
    const Selector &sel,
    const ObjectList &categories
    )
    : mSearchText( text )
    , mSelector( sel )
    , mCategories( categories )
{
}

ObjectSearcher::ObjectSearcher
    (
     const ObjectSearcher &other
    )
    : Searcher( other )
    , mSearchText( other.mSearchText )
    , mSelector( other.mSelector )
    , mCategories( other.mCategories )
{
}

ObjectSearcher::~ObjectSearcher()
{
}

/* virtual */ void ObjectSearcher::operator()()
{
    #ifdef SEARCHER_DEBUG
        std::cout << "Object Searcher Start" << std::endl;
    #endif
    ObjectList res;

    ObjectList::const_iterator catItr;
    catItr = mCategories.begin();
    while( mCategories.end() != catItr )
    {
        Category cat = *catItr;
        if( cat.areObjectsSearchable() )
        {
            #ifdef SEARCHER_DEBUG
                std::cout << "Checking category: " << cat.getTitle() << std::endl;
            #endif
            res.add( cat.filterWithSelector( mSelector, mSearchText ) );
        }
        catItr++;
    }

    #ifdef SEARCHER_DEBUG
        std::cout << "Object Searcher Done" << std::endl;
    #endif
    reportSearchDone( res );
}

} // namespace Flurry
