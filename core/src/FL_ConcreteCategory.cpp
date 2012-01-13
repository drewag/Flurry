#include "FL_ConcreteCategory.h"

#include "FL_ObjectList.h"
#include "FL_Selector.h"
#include "FL_Category.h"

#include <set>
#include <iostream>

namespace Flurry
{

ConcreteCategory::ConcreteCategory
    (
    std::string title,
    bool objectsAreSearchable
    )
    : ConcreteObject( title )
    , mObjects( new ObjectList() )
    , mObjectsAreSearchable( objectsAreSearchable )
{
}

/* virtual */ void ConcreteCategory::destroy()
{
    delete this;
}

ConcreteCategory::~ConcreteCategory()
{
    delete mObjects;
}

bool ConcreteCategory::areObjectsSearchable() const
{
    return mObjectsAreSearchable;
}

const ObjectList ConcreteCategory::filterWithSelector
    (
    const Selector &sel,
    const std::string &str
    ) const
{
    ObjectList ret;
    
    ObjectList::const_iterator itr;
    itr = mObjects->begin();
    while( mObjects->end() != itr )
    {
        if( sel.doesObjectMatch( str, *itr ) )
        {
            ret.add( *itr );
        }
        itr++;
    }

    return ret;
}

void ConcreteCategory::addObject
    (
    Object &obj 
    )
{
   mObjects->add( obj ); 
}

void ConcreteCategory::addObjects
    (
    ObjectList &list
    )
{
    mObjects->add( list );
}

void ConcreteCategory::removeObjects
    (
    ObjectList &list
    )
{
    mObjects->remove( list );
}

} // namespace Flurry
