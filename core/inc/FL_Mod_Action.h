#ifndef FL_ModSelector
#define FL_ModSelector

#include "FL_Mod_Category.h"
#include "FL_Mod_Object.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void Mod_Action;

Mod_Action* mod_action_create();

void mod_action_destroy
    (
    Mod_Action* action
    );

const char* mod_action_get_title
    (
    const Mod_Action* action
    );

#ifdef __cplusplus
}
#endif

#endif
