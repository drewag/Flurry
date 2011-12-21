#include "FL_ActionManager.h"

#include "FL_Category.h"
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
    return ActionManager::actionCategory();
}

/* static */ Category ActionManager::actionCategory()
{
    static Category category( "Action", false );
    return category;
}

/* virtual */ const ObjectList &ActionManager::loadObjectsFromMod
    (
    Module &mod
    )
{
    return mod.refreshActions();
}

} // namespace Fluffy
