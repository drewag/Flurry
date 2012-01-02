#include "FL_ObjectManager.h"

#include "FL_ObjectList.h"
#include "FL_Category.h"
#include "FL_Module.h"

#include <iostream>

namespace Flurry
{

ObjectManager::ObjectManager()
    : mObjectMap( NULL )
{
    mObjectMap = new ObjectMap();
}

/* virtual */ ObjectManager::~ObjectManager()
{
    delete mObjectMap;
    mObjectMap = NULL;
}

bool ObjectManager::refreshModule
    (
    Module &mod
    )
{
    Category category = this->getCategory();

    // Create list for this module and if it already existed then clear it
    std::string name( mod.getName() );
    category.removeObjects( (*mObjectMap)[name] );
    (*mObjectMap)[name].clear();
    (*mObjectMap)[name].add( this->loadObjectsFromMod( mod ) );
    category.addObjects( (*mObjectMap)[name] );
    return true;
}

bool ObjectManager::unloadModule
    (
    Module &mod
    )
{
    std::string name( mod.getName() );

    ObjectMap::iterator itr;
    itr = mObjectMap->find( name );
    if( mObjectMap->end() == itr )
    {   
        return true;
    }

    Category category = this->getCategory();
    category.removeObjects( itr->second );

    mObjectMap->erase( itr );
    return true;
}

ObjectList ObjectManager::getAllObjects()
{
    ObjectList ret;

    ObjectMap::iterator itr;
    itr = mObjectMap->begin();
    while( mObjectMap->end() != itr )
    {   
        ret.add( itr->second );
        itr++;
    }

    return ret;
}

} // namespace Fluffy
