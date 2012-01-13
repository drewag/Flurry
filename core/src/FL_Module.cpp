#include "FL_Module.h"
#include "FL_Mod_Module.h"
#include "FL_ObjectList.h"
#include "FL_Category.h"
#include "FL_Selector.h"

#include <dlfcn.h>
#include <iostream>

#define MODULE_DIRECTORY "modules/"

namespace Flurry
{

Module::Module
    (
    std::string name
    )
    : mCategories( NULL )
    , mActions( NULL )
    , mSelectors( NULL )
    , mName( name )
    , mLibHndl( NULL )
{
    mCategories = new ObjectList();
    mActions = new ObjectList();
    mSelectors = new ObjectList();
}

Module::Module()
    : mCategories( NULL )
    , mActions( NULL )
    , mSelectors( NULL )
    , mLibHndl( NULL )
{
    mCategories = new ObjectList();
    mActions = new ObjectList();
    mSelectors = new ObjectList();
}

/* virtual */ Module::~Module()
{
    this->unload();
}

/* virtual */ ModuleManager::ModuleLoadStatus Module::load()
{
    if( NULL != mLibHndl )
    {
        return ModuleManager::MODULE_LOAD_STATUS_ALREADY_LOADED;
    }

    std::string filePath = MODULE_DIRECTORY + mName + ".so";
    mLibHndl = dlopen( filePath.c_str(), RTLD_NOW );
    if( NULL == mLibHndl )
    {
        std::cerr << dlerror() << std::endl;
        return ModuleManager::MODULE_LOAD_STATUS_FAILED;
    }

    ModuleLoad loadFunc = (ModuleLoad)dlsym( mLibHndl, "load" );
    if( NULL == loadFunc )
    {
        std::cerr << dlerror() << std::endl;
        return ModuleManager::MODULE_LOAD_STATUS_MISSING_FUNCTION;
    }

    loadFunc();

    return ModuleManager::MODULE_LOAD_STATUS_SUCCESSFUL;
}

/* virtual */ void Module::unload()
{
    if( NULL == mLibHndl )
    {
        return;
    }

    ModuleUnload unloadFunc = (ModuleUnload)dlsym( mLibHndl, "unload" );
    if( NULL == unloadFunc )
    {
        std::cerr << dlerror() << std::endl;
    }
    else
    {
        unloadFunc();
    }
    dlclose( mLibHndl );

    delete mCategories;
    mCategories = NULL;
    delete mActions;
    mActions = NULL;
    delete mSelectors;
    mSelectors = NULL;
}

std::string Module::getName() const
{
    return mName;
}

/* virtual */ const ObjectList &Module::refreshCategories()
{
    mCategories->clear();

    RefreshCategoriesFunc refresh = NULL;
    refresh = (RefreshCategoriesFunc)dlsym( mLibHndl, "refreshCategories" );

    Mod_Category** categories = NULL;
    unsigned int numCategories = 0;
    refresh( categories, numCategories );

    for( unsigned int i = 0; i < numCategories; i++ )
    {
        Mod_Category* cat = categories[i];
        mCategories->add( *(Category*)cat );
    }

    return *mCategories;
}

/* virtual */ const ObjectList &Module::refreshActions()
{
    mActions->clear();

    RefreshActionsFunc refresh = NULL;
    refresh = (RefreshActionsFunc)dlsym( mLibHndl, "refreshActions" );

    Mod_Action** actions = NULL;
    unsigned int numActions = 0;
    refresh( actions, numActions );

    for( unsigned int i = 0; i < numActions; i++ )
    {
        // TODO: Turn Mod_Action into action and add it to mActions
    }

    return *mActions;
}

/* virtual */ const ObjectList &Module::refreshSelectors()
{
    mSelectors->clear();

    RefreshSelectorsFunc refresh = NULL;
    refresh = (RefreshSelectorsFunc)dlsym( mLibHndl, "refreshSelectors" );

    Mod_Selector** selectors = NULL;
    unsigned int numSelectors = 0;
    refresh( selectors, numSelectors );

    for( unsigned int i = 0; i < numSelectors; i++ )
    {
        Mod_Selector* sel = &selectors[i];
        mSelectors->add( *(Selector*)sel );
    }

    return *mSelectors;
}

} // namespace Flurry
