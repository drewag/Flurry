#include "FL_SelectorManager.h"

#include "FL_Category.h"
#include "FL_ObjectList.h"
#include "FL_Module.h"
#include "FL_Selector.h"

namespace Flurry
{

SelectorManager::SelectorManager()
{
}

SelectorManager::~SelectorManager()
{
}

/* virtual */ Category SelectorManager::getCategory() const
{
    return Selector::selectorCategory();
}

/* virtual */ const ObjectList &SelectorManager::loadObjectsFromMod
    (
    Module &mod
    )
{
    return mod.refreshSelectors();
}

} // namespace Fluffy
