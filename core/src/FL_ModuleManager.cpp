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
    mCoreModule->setName( "FlurryCore" );
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

bool ModuleManager::registerModule
    (
    std::string name
    )
{
    std::cout << "Loading Module: " << name << "...";

    ModuleMap::iterator itr = mModules.find( name );
    if( mModules.end() != itr )
    {
        std::cerr << "Module " << name << " already loaded." << std::endl;
        return false;
    }

    std::string filePath = "modules/" + name + ".so";

    void* lib = dlopen( filePath.c_str(), RTLD_NOW );
    if( NULL == lib )
    {
        std::cerr << dlerror() << std::endl;
        return false;
    }

    ModuleMaker create = (ModuleMaker)dlsym( lib, "create" );
    if( NULL == create )
    {
        std::cerr << dlerror() << std::endl;
        return false;
    }

    Module* module = create();
    module->setLibHndl( lib );
    module->setName( name );

    this->loadModule( module );

    std::cout << "done." << std::endl;

    return true;
}

bool ModuleManager::unregisterModule
    (
    std::string name
    )
{
    ModuleMap::iterator itr = mModules.find( name );
    if( mModules.end() == itr )
    {
        std::cerr << "Module " << name << " not found." << std::endl;
        return false;
    }

    Module* module = itr->second;
    this->unloadModule( module );
    mModules.erase( itr );

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
    mModules[module->getName()] = module;
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
    std::cout << "Unloading Module " << module->getName() <<  "...";

    mCategoryManager->unloadModule( *module );
    mSelectorManager->unloadModule( *module );
    mActionManager->unloadModule( *module );

    void* lib = module->getLibHndl();
    if( NULL != lib )
    {
        ModuleDestroyer destroy = (ModuleDestroyer)dlsym( lib, "destroy" );
        if( NULL == destroy )
        {
            std::cerr << dlerror() << std::endl;
            return false;
        }
        destroy( module );
        module = NULL;

        dlclose( lib );
    }

    std::cout << "done." << std::endl;

    return true;
}

} // namespace Flurry
