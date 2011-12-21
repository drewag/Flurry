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

const ObjectList SelectorManager::findSelector
    (
    const Category &cat,
    std::string text
    )
{
    ObjectList ret;

    ObjectMap::const_iterator mapItr;
    mapItr = mObjectMap->begin();
    while( mObjectMap->end() != mapItr )
    {
        const ObjectList* list = &mapItr->second;
        ret.add( *list );
        mapItr++;
    }

    return ret;
} 

/* virtual */ const ObjectList &SelectorManager::loadObjectsFromMod
    (
    Module &mod
    )
{
    return mod.refreshSelectors();
}

} // namespace Fluffy
