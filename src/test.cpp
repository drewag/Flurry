#include "FL_Mod_ModuleManager.h"
#include "FL_Mod_Dialog.h"
#include "FL_Mod_Object.h"
#include "FL_Mod_Category.h"
#include "FL_Mod_Selector.h"
#include "FL_Mod_Action.h"

#include <iostream>
#include <vector>

void resultsGenerated( Mod_Dialog* dialog, const Mod_Object** results, unsigned int numResults );
void actionBegun( Mod_Dialog* dialog, const Mod_Action *action );
void actionFinished( Mod_Dialog* dialog, const Mod_Action *action );
void askForText( Mod_Dialog* dialog );

int main()
{
    Mod_ModuleManager* moduleManager = mod_module_manager_create();

    mod_module_manager_register_module( moduleManager, "operatingsystem" );

    Mod_Dialog* dialog = mod_dialog_create( moduleManager );

    mod_dialog_connect_results_generated( dialog, &resultsGenerated );
    mod_dialog_connect_action_begun( dialog, &actionBegun );
    mod_dialog_connect_action_finished( dialog, &actionFinished );

    askForText( dialog );
    mod_dialog_start( dialog );
}

void askForText
    (
    Mod_Dialog* dialog
    )
{
    std::cout << "Please enter a search term:" << std::endl;

    std::string input;
    std::cin >> input;

    mod_dialog_text_changed( dialog, input.c_str() );
}

void resultsGenerated
    (
    Mod_Dialog* dialog,
    const Mod_Object** results,
    unsigned int numResults
    )
{
    for( unsigned int i = 0; i < numResults; i++ )
    {
        std::cout << i + 1 << ".\t" << mod_object_get_title( results[i] ) << std::endl;
    }
    if( numResults > 0 )
    {
        unsigned int idx = 0;
        while( idx <= 0 || idx > numResults )
        {
            std::cout << "Please enter a number to indicate which result to choose" << std::endl;

            std::string input;
            std::cin >> input;

            idx = atoi( input.c_str() );
        }
        mod_dialog_result_selected( dialog, results[idx-1] );
    }

    askForText( dialog );
}

void actionBegun
    (
    Mod_Dialog *dialog,
    const Mod_Action *action
    )
{
    std::cout << mod_action_get_title( action ) << " started...";
}

void actionFinished
    (
    Mod_Dialog *dialog,
    const Mod_Action *action
    )
{
    std::cout << "finished.\n";
}

