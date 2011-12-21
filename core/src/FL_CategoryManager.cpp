#include "FL_CategoryManager.h"

#include "FL_ObjectList.h"
#include "FL_Module.h"
#include "FL_Category.h"
#include "FL_Selector.h"
#include "FL_CoreModule.h"

#include <iostream>

namespace Flurry
{

CategoryManager::CategoryManager()
{
}

CategoryManager::~CategoryManager()
{
}

ObjectList CategoryManager::findObject
    (
    std::string text,
    Selector &sel
    )
{
    ObjectList ret;

    ObjectMap::const_iterator mapItr;
    mapItr = mObjectMap->begin();
    while( mObjectMap->end() != mapItr )
    {
        const ObjectList* list = &mapItr->second;

        ObjectList::const_iterator listItr;
        listItr = list->begin();
        while( list->end() != listItr )
        {
            Category cat = *listItr;
            if( cat.areObjectsSearchable() )
            {
                ret.add( cat.filterWithSelector( sel, text ) );
            }
            listItr++;
        }
        mapItr++;
    }

    return ret;
}

/* virtual */ Category CategoryManager::getCategory() const
{
    return Category::categoryCategory();
}

/* virtual */ const ObjectList &CategoryManager::loadObjectsFromMod
    (
    Module &mod
    )
{
    return mod.refreshCategories();
}

} // namespace Fluffy
