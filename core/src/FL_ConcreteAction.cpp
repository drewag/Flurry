#include "FL_ConcreteAction.h"

namespace Flurry
{

ConcreteAction::ConcreteAction
    (
    std::string title,
    const ObjectList inputCategories
    )
    : ConcreteObject( title )
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
