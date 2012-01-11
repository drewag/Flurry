#include "FL_ObjectSearcher.h"

#include "FL_Category.h"

#include <iostream>

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
    ObjectList res;

    ObjectList::const_iterator catItr;
    catItr = mCategories.begin();
    while( mCategories.end() != catItr )
    {
        Category cat = *catItr;
        if( cat.areObjectsSearchable() )
        {
            res.add( cat.filterWithSelector( mSelector, mSearchText ) );
        }
        catItr++;
    }

    reportSearchDone( res );
}

} // namespace Flurry
