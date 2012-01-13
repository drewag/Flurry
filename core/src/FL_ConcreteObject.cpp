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
    std::string title,
    Category cat
    )
    : mRetainCount( 1 )
    , mCategory( new Category( cat ) )
    , mTitle( title )
{
#ifdef DEBUG_OBJECT_LIFECYCLE
    createCount++;
    mId = createCount;
    std::cout << "Created: " << mId << std::endl;
#endif
}

ConcreteObject::ConcreteObject
    (
    std::string title
    )
    : mRetainCount( 1 )
    , mCategory( NULL )
    , mTitle( title )
{
#ifdef DEBUG_OBJECT_LIFECYCLE
    createCount++;
    mId = createCount;
    std::cout << "Created: " << mId << std::endl;
#endif
}

ConcreteObject::~ConcreteObject()
{
#ifdef DEBUG_OBJECT_LIFECYCLE
    std::cout << "Destroying " << mTitle << std::endl;
#endif
    delete mCategory;
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
    if( NULL == mCategory )
    {
        return cat == Category::categoryCategory();
    }
    return *mCategory == cat;
}

const std::string &ConcreteObject::getTitle()
{
    return mTitle;
}

Category ConcreteObject::getCategory() const
{
    if( NULL == mCategory )
    {
        return Category::categoryCategory();
    }
    return *mCategory;
}

} // namespace Flurry
