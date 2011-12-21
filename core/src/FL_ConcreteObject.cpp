#include "FL_ConcreteObject.h"

#include "FL_ObjectList.h"
#include "FL_Category.h"
#include "FL_CategoryManager.h"

#include <iostream>

namespace Flurry
{

#ifdef DEBUG_OBJECT_LIFECYCLE
static unsigned long long createCount = 0;
#endif

ConcreteObject::ConcreteObject
    (
    std::string title
    )
    : mRetainCount( 1 )
    , mCategories( NULL )
    , mTitle( title )
{
#ifdef DEBUG_OBJECT_LIFECYCLE
    createCount++;
    mId = createCount;
    std::cout << "Created: " << mId << std::endl;
#endif
    mCategories = new ObjectList();
}

ConcreteObject::~ConcreteObject()
{
    delete mCategories;
}

void ConcreteObject::retain()
{
    mRetainCount++;
#ifdef DEBUG_OBJECT_LIFECYCLE
    std::cout << mId << " Retain: " << mRetainCount << std::endl;
#endif
}

/* virtual */ void ConcreteObject::destroy()
{
    delete this;
}

void ConcreteObject::release()
{
    mRetainCount--;
#ifdef DEBUG_OBJECT_LIFECYCLE
    std::cout << mId << " Release: " << mRetainCount << std::endl;
#endif
    if( 0 == mRetainCount )
    {
#ifdef DEBUG_OBJECT_LIFECYCLE
        std::cout << "Destroyed: " << mId << std::endl;
#endif
        this->destroy();
    }
}

bool ConcreteObject::isOfCategory
    (
    const Category &cat //!< Category to test against
    ) const
{
    ObjectList::const_iterator itr;
    itr = mCategories->begin();
    while( mCategories->end() != itr )
    {
        if( *itr == cat )
        {
            return true;
        }
        itr++;
    }
    return false;
}

const std::string &ConcreteObject::getTitle()
{
    return mTitle;
}

void ConcreteObject::addCategory
    (
    const Category &cat
    )
{
    mCategories->add( cat );
}

void ConcreteObject::removeCategory
    (
    const Category &cat
    )
{
    mCategories->remove( cat );
}

} // namespace Flurry
