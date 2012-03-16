#ifndef FL_Mod_ModuleManager
#define FL_Mod_ModuleManager

#ifdef __cplusplus
extern "C" {
#endif

typedef void Mod_ModuleManager;

Mod_ModuleManager* mod_module_manager_create();

void mod_module_manager_destroy
    (
    Mod_ModuleManager* manager
    );

void mod_module_manager_register_module
    (
    Mod_ModuleManager* manager,
    const char* module
    );

#ifdef __cplusplus
}
#endif

#endif
