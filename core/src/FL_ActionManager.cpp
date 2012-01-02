#include "FL_ActionManager.h"

#include "FL_Category.h"
#include "FL_Action.h"
#include "FL_Module.h"

namespace Flurry
{

ActionManager::ActionManager()
{
}

ActionManager::~ActionManager()
{
}

/* virtual */ Category ActionManager::getCategory() const
{
    return Action::actionCategory();
}

/* virtual */ const ObjectList &ActionManager::loadObjectsFromMod
    (
    Module &mod
    )
{
    return mod.refreshActions();
}

} // namespace Fluffy
