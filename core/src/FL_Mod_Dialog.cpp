#include "FL_Mod_Dialog.h"

#include "FL_Dialog.h"
#include "FL_ObjectList.h"
#include "FL_Object.h"
#include <string>
#include <list>

using namespace Flurry;

//---------------------------------------------------------------------------------------
// Types
//---------------------------------------------------------------------------------------

// A private struct to store some extra information about the dialog
//
// Note: The first element of the struct must be the actual dialog. This
// allows the struct to be cast directly to a Dialog* (or Mod_Dialog*)
// without problems
typedef struct Mod_Dialog_prv
{
    Dialog dialog;
    ResultsGeneratedFunc resGenerated;
    ActionBegunFunc actionBegun;
    ActionFinishedFunc actionFinished;

    Mod_Dialog_prv( ModuleManager* manager ) : dialog( *manager ) {};
} Mod_Dialog_prv;

//---------------------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------------------

void mod_dialog_result_generated
    (
    Dialog &dialog,
    ObjectList results
    );

void mod_dialog_action_begun
    (
    Dialog &dialog,
    const Action &action
    );

void mod_dialog_action_finished
    (
    Dialog &dialog,
    const Action &action
    );

//---------------------------------------------------------------------------------------
// Variables
//---------------------------------------------------------------------------------------

std::list<Mod_Dialog_prv*> gActiveDialogs;


Mod_Dialog* mod_dialog_create
    (
    Mod_ModuleManager* manager
    )
{
    Mod_Dialog_prv* diag = new Mod_Dialog_prv( (ModuleManager*)manager );
    diag->resGenerated = NULL;
    diag->actionBegun = NULL;
    diag->actionFinished = NULL;
    gActiveDialogs.push_back( diag );

    diag->dialog.connectToResultsGenerated( &mod_dialog_result_generated );
    diag->dialog.connectToActionBegun( &mod_dialog_action_begun );
    diag->dialog.connectToActionFinished( &mod_dialog_action_finished );
    return (Mod_Dialog*)diag;
}

void mod_dialog_destroy
    (
    Mod_Dialog* dialog
    )
{
    std::list<Mod_Dialog_prv*>::iterator itr;
    for( itr = gActiveDialogs.begin(); gActiveDialogs.end() != itr; itr ++ )
    {
        if( *itr == dialog )
        {
            gActiveDialogs.erase( itr );
            break;
        }
    }
    delete (Dialog*)dialog;
}

void mod_dialog_result_generated
    (
    Dialog &dialog,
    ObjectList results
    )
{
    std::list<Mod_Dialog_prv*>::iterator itr;
    for( itr = gActiveDialogs.begin(); gActiveDialogs.end() != itr; itr ++ )
    {
        Mod_Dialog_prv* diag = (Mod_Dialog_prv*)*itr;
        if( &dialog == &diag->dialog )
        {
            if( NULL != diag->resGenerated )
            {
                unsigned int resCount = results.size();
                typedef const Mod_Object* ConstPointer;
                ConstPointer* objects = new ConstPointer[resCount];
                ObjectList::iterator itr;
                unsigned int count = 0;
                for( itr = results.begin(); results.end() != itr; itr++ )
                {
                    const Object* obj = &*itr;
                    objects[count] = (const Mod_Object*)obj;
                    count++;
                }

                diag->resGenerated( (Mod_Dialog*)diag, (const Mod_Object**)objects, resCount );
                delete[] objects;
            }
            break;
        }
    }
}

void mod_dialog_action_begun
    (
    Dialog &dialog,
    const Action &action
    )
{
    std::list<Mod_Dialog_prv*>::iterator itr;
    for( itr = gActiveDialogs.begin(); gActiveDialogs.end() != itr; itr ++ )
    {
        Mod_Dialog_prv* diag = (Mod_Dialog_prv*)*itr;
        if( &dialog == &diag->dialog )
        {
            if( NULL != diag->actionBegun )
            {
                diag->actionBegun( (Mod_Dialog*)diag, (Mod_Action*)&action );
            }
            break;
        }
    }
}

void mod_dialog_action_finished
    (
    Dialog &dialog,
    const Action &action
    )
{
    std::list<Mod_Dialog_prv*>::iterator itr;
    for( itr = gActiveDialogs.begin(); gActiveDialogs.end() != itr; itr ++ )
    {
        Mod_Dialog_prv* diag = (Mod_Dialog_prv*)*itr;
        if( &dialog == &diag->dialog )
        {
            if( NULL != diag->actionFinished )
            {
                diag->actionFinished( (Mod_Dialog*)diag, (Mod_Action*)&action );
            }
            break;
        }
    }
}

void mod_dialog_start
    (
    Mod_Dialog* dialog
    )
{
    Dialog* diag = (Dialog*)dialog;
    diag->start();
}

void mod_dialog_text_changed
    (
    Mod_Dialog* dialog,
    const char* newText
    )
{
    Dialog* diag = (Dialog*)dialog;
    diag->textChanged( std::string( newText ) );
}

void mod_dialog_result_selected
    (
    Mod_Dialog* dialog,
    const Mod_Object* res
    )
{
    Dialog* diag = (Dialog*)dialog;
    diag->resultSelected( *(const Object*)res );
}

void mod_dialog_batch_result_selected
    (
    Mod_Dialog* dialog,
    Mod_Object* res
    )
{
    Dialog* diag = (Dialog*)dialog;
    diag->batchResultSelected( *(Object*)res );
}

void mod_dialog_connect_results_generated
    (
    Mod_Dialog* dialog,
    ResultsGeneratedFunc func
    )
{
    Mod_Dialog_prv* diag = (Mod_Dialog_prv*)dialog;
    diag->resGenerated = func;
}

void mod_dialog_connect_action_begun
    (
    Mod_Dialog* dialog,
    ActionBegunFunc func
    )
{
    Mod_Dialog_prv* diag = (Mod_Dialog_prv*)dialog;
    diag->actionBegun = func;
}

void mod_dialog_connect_action_finished
    (
    Mod_Dialog* dialog,
    ActionFinishedFunc func
    )
{
    Mod_Dialog_prv* diag = (Mod_Dialog_prv*)dialog;
    diag->actionFinished = func;
}
