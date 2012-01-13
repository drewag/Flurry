#include "FL_ModuleManager.h"

#include "FL_ObjectManager.h"
#include "FL_CategoryManager.h"
#include "FL_ActionManager.h"
#include "FL_SelectorManager.h"
#include "FL_ObjectList.h"
#include "FL_Module.h"
#include "FL_CoreModule.h"

#include <iostream>

#include <dlfcn.h>

namespace Flurry
{

//-----------------------------------------------------------
// Public Functions
//-----------------------------------------------------------

ModuleManager::ModuleManager()
    : mCategoryManager( new CategoryManager() )
    , mActionManager( new ActionManager() )
    , mSelectorManager( new SelectorManager() )
    , mCoreModule( NULL )
{
    mCoreModule = new CoreModule();
    mModules[mCoreModule->getName()] = mCoreModule;
    this->loadModule( mCoreModule );
}

ModuleManager::~ModuleManager()
{
    ModuleMap::iterator itr = mModules.begin();
    while( mModules.end() != itr )
    {
        this->unloadModule( itr->second );
        itr++;
    }

    delete mCoreModule;
    delete mCategoryManager;
    delete mActionManager;
    delete mSelectorManager;
}

bool ModuleManager::refresh()
{
    return true;
}

ModuleManager::ModuleLoadStatus ModuleManager::registerModule
    (
    std::string name
    )
{
    std::cout << "Loading Module: " << name << "...";

    ModuleMap::iterator itr = mModules.find( name );
    if( mModules.end() != itr )
    {
        std::cerr << "Module " << name << " already loaded." << std::endl;
        return ModuleManager::MODULE_LOAD_STATUS_ALREADY_LOADED;
    }

    Module* module = new Module( name );
    ModuleLoadStatus status = module->load();
    if( MODULE_LOAD_STATUS_SUCCESSFUL == status )
    {
        mModules[name] = module;
        this->loadModule( module );

        std::cout << "done." << std::endl;
    }

    return status;
}

bool ModuleManager::unregisterModule
    (
    std::string name
    )
{
    std::cout << "Unloading Module " << name <<  "...";

    ModuleMap::iterator itr = mModules.find( name );
    if( mModules.end() == itr )
    {
        std::cerr << "Module " << name << " not found." << std::endl;
        return false;
    }

    Module* module = itr->second;
    this->unloadModule( module );
    mModules.erase( itr );

    std::cout << "done." << std::endl;

    return true;
}

const ObjectList ModuleManager::getAllCategories()
{
    return mCategoryManager->getAllObjects();
}

const ObjectList ModuleManager::getAllSelectors()
{
    return mSelectorManager->getAllObjects();
}

//-----------------------------------------------------------
// Private Functions
//-----------------------------------------------------------

bool ModuleManager::loadModule
    (
    Module* module
    )
{
    module->load();

    mCategoryManager->refreshModule( *module );
    mSelectorManager->refreshModule( *module );
    mActionManager->refreshModule( *module );

    return true;
}

bool ModuleManager::unloadModule
    (
    Module* module
    )
{
    mCategoryManager->unloadModule( *module );
    mSelectorManager->unloadModule( *module );
    mActionManager->unloadModule( *module );

    module->unload();

    return true;
}

} // namespace Flurry
