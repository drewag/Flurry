#include "FL_Selector.h"

#include "FL_ConcreteSelector.h"
#include "FL_SelectorManager.h"
#include "FL_Category.h"

namespace Flurry
{

Selector::Selector
    (
    ConcreteSelector* sel
    )
{
    mConcrete = sel;
    mConcrete->retain();
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

} // namespace Flurry
