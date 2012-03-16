#ifndef FL_Mod_Dialog
#define FL_Mod_Dialog

#include "FL_Mod_ModuleManager.h"
#include "FL_Mod_Object.h"
#include "FL_Mod_Action.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void Mod_Dialog;

typedef void (*ResultsGeneratedFunc)
    (
    Mod_Dialog* dialog,         //!< Dialog that generated event
    const Mod_Object** results, //!< List of results
    unsigned int numResults
    );

typedef void (*ActionBegunFunc)
    (
    Mod_Dialog* dialog,       //!< Dialog that generated event
    const Mod_Action* action  //!< Action that started
    );

typedef void (*ActionFinishedFunc)
    (
    Mod_Dialog* dialog,       //!< Dialog that generated event
    const Mod_Action* action  //!< Action that started
    );

Mod_Dialog* mod_dialog_create
    (
    Mod_ModuleManager* manager
    );

void mod_dialog_destroy
    (
    Mod_Dialog* dialog
    );

void mod_dialog_start
    (
    Mod_Dialog* dialog
    );

void mod_dialog_text_changed
    (
    Mod_Dialog* dialog,
    const char* newText
    );

void mod_dialog_result_selected
    (
    Mod_Dialog* dialog,
    const Mod_Object* res
    );

void mod_dialog_batch_result_selected
    (
    Mod_Dialog* dialog,
    Mod_Object* res
    );

void mod_dialog_connect_results_generated
    (
    Mod_Dialog* dialog,
    ResultsGeneratedFunc func
    );

void mod_dialog_connect_action_begun
    (
    Mod_Dialog* dialog,
    ActionBegunFunc func
    );

void mod_dialog_connect_action_finished
    (
    Mod_Dialog* dialog,
    ActionFinishedFunc func
    );

#ifdef __cplusplus
}
#endif

#endif
