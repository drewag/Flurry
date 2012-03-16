#include "FL_Mod_ModuleManager.h"

#include "FL_ModuleManager.h"

using namespace Flurry;

Mod_ModuleManager* mod_module_manager_create()
{
    ModuleManager* manager = new ModuleManager();
    return (Mod_ModuleManager*)manager;
}

void mod_modulemanager_destroy
    (
    Mod_ModuleManager* manager
    )
{
    delete (ModuleManager*)manager;
}

void mod_module_manager_register_module
    (
    Mod_ModuleManager* manager,
    const char* module
    )
{
    ModuleManager* mngr = (ModuleManager*)manager;
    mngr->registerModule( std::string( module ) );
}
