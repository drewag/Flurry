#include "FL_ConcreteAction.h"

#include "FL_Action.h"
#include "FL_Category.h"

namespace Flurry
{

ConcreteAction::ConcreteAction
    (
    std::string title,
    const ObjectList inputCategories
    )
    : ConcreteObject( title, Action::actionCategory() )
    , mInputCategories( inputCategories )
{
}

ConcreteAction::~ConcreteAction()
{
}

/* virtual */ const ObjectList &ConcreteAction::getInputCategories()
{
    return mInputCategories;
}

} // namespace Flurry
