#ifndef FL_Mod_Module
#define FL_Mod_Module

#include "FL_Mod_Category.h"
#include "FL_Mod_Action.h"
#include "FL_Mod_Selector.h"

#ifdef __cplusplus
extern "C" {
#endif

//! Factory create function
typedef void (*ModuleLoad)();

//! Factory destroy function
typedef void (*ModuleUnload)();

//! @return the list of categories in this module
typedef void (*RefreshCategoriesFunc)
    (
    Mod_Category** &categories,  //!< [out] List of all categories
    unsigned int &numCategories  //!< [out] The number of all categories
    );

//! @return the list of actions in this module
typedef void (*RefreshActionsFunc)
    (
    Mod_Action** &actions,      //!< [out] List of all actions
    unsigned int &numActions    //!< [out] The number of all selectors
    );

//! @return the list of selectors in this module
typedef void (*RefreshSelectorsFunc)
    (
    Mod_Selector** &selectors,  //!< [out] List of all selectors
    unsigned int &numSelectors  //!< [out] The number of all selectors
    );

#ifdef __cplusplus
}
#endif

#endif
