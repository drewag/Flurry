#include "FL_Selector.h"

#include "FL_ConcreteSelector.h"
#include "FL_SelectorManager.h"
#include "FL_Category.h"

namespace Flurry
{

Selector::Selector
    (
    std::string title,
    MatchObjectFunc func,
    const ObjectList &categories
    )
{
    mConcrete = new ConcreteSelector( title, func, categories );
}

Selector::Selector
    (
    const Object &other
    )
{
    if( !other.isOfCategory( Selector::selectorCategory() ) )
    {
        // TODO throw exception
    }

    mConcrete = other.mConcrete;
    mConcrete->retain();
}

Selector::~Selector()
{
}

/* static */ Category Selector::selectorCategory()
{
    static Category category( "Selector", false );
    return category;
}

/* virtual */ bool Selector::doesObjectMatch
    (
    std::string text,
    const Object &obj
    ) const
{
    return ((ConcreteSelector*)mConcrete)->doesObjectMatch( text, obj );
}

/* virtual */ bool Selector::doesSupportCategory
    (
    const Category &cat
    ) const
{
    return ((ConcreteSelector*)mConcrete)->doesSupportCategory( cat );
}

} // namespace Flurry
