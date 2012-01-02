#include "FL_Action.h"

#include "FL_ConcreteAction.h"
#include "FL_ActionManager.h"
#include "FL_Category.h"

namespace Flurry
{

Action::Action
    (
    ConcreteAction* sel
    )
{
    mConcrete = sel;
    mConcrete->retain();
}

Action::Action
    (
    const Object &other
    )
{
    if( !other.isOfCategory( Action::actionCategory() ) )
    {
        // TODO throw exception
    }

    mConcrete = other.mConcrete;
    mConcrete->retain();
}

Action::~Action()
{
}

/* static */ Category Action::actionCategory()
{
    static Category category( "Action", true );
    return category;
}

} // namespace Flurry
