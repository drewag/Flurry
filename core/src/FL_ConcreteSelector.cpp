#include "FL_ConcreteSelector.h"

#include "FL_ObjectList.h"
#include "FL_Selector.h"
#include "FL_Category.h"

namespace Flurry
{

ConcreteSelector::ConcreteSelector
    (
    std::string title,
    MatchObjectFunc func,
    const ObjectList &supportedCategories
    )
    : ConcreteObject( title, Selector::selectorCategory() )
    , mMatchObjectFunc( func )
    , mCategories( new ObjectList( supportedCategories ) )
{
}

ConcreteSelector::~ConcreteSelector()
{
    delete mCategories;
}

/* virtual */ void ConcreteSelector::destroy()
{
    delete this;
}

bool ConcreteSelector::doesSupportCategory
    (
    const Category &cat
    ) const
{
    if( 0 == mCategories->size() )
    {
        // No categories in list indicates that all categories are supported
        return true;
    }

    return mCategories->containsObject( cat );
}

/* virtual */ bool ConcreteSelector::doesObjectMatch
    (
    std::string text,
    const Object &obj
    ) const
{
    if( NULL == mMatchObjectFunc )
    {
        return false;
    }
    const char* objTitle = obj.getTitle().c_str();
    const char* catTitle = obj.getCategory().getTitle().c_str();
    return mMatchObjectFunc( text.c_str(), objTitle, catTitle );
}

} // namespace Flurry
