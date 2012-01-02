#include "FL_ModuleManager.h"
#include "FL_ObjectList.h"
#include "FL_Dialog.h"
#include "FL_Object.h"
#include "FL_Category.h"
#include "FL_Selector.h"
#include "FL_Action.h"

#include "FL_CategoryManager.h"

#include <iostream>
#include <vector>

void resultsGenerated( Flurry::Dialog &dialog, Flurry::ObjectList results );
void actionBegun( Flurry::Dialog &dialog, const Flurry::Action &action );
void actionFinished( Flurry::Dialog &dialog, const Flurry::Action &action );
void askForText( Flurry::Dialog &dialog );

int main()
{
    Flurry::ModuleManager moduleManager;

    moduleManager.registerModule( "operatingsystem" );

    Flurry::Dialog dialog
        (
        moduleManager
        );

    dialog.connectToResultsGenerated( &resultsGenerated );
    dialog.connectToActionBegun( &actionBegun );
    dialog.connectToActionFinished( &actionFinished );

    askForText( dialog );
    dialog.start();
}

void askForText
    (
    Flurry::Dialog &dialog
    )
{
    std::cout << "Please enter a search term:" << std::endl;

    std::string input;
    std::cin >> input;

    dialog.textChanged( input );
}

void resultsGenerated
    (
    Flurry::Dialog &dialog,
    Flurry::ObjectList results
    )
{
    std::vector<Flurry::Object> resDisplay;

    Flurry::ObjectList::const_iterator itr;
    itr = results.begin();
    unsigned int i = 0;
    while( results.end() != itr )
    {
        i++;
        std::cout << i << ".\t" << itr->getTitle() << std::endl;
        resDisplay.push_back( *itr );
        itr++;
    }
    if( results.size() > 0 )
    {
        unsigned int idx = 0;
        while( idx <= 0 || idx > results.size() )
        {
            std::cout << "Please enter a number to indicate which result to choose" << std::endl;

            std::string input;
            std::cin >> input;
            
            idx = atoi( input.c_str() );
        }
        dialog.resultSelected( resDisplay[idx-1] );
    }

    askForText( dialog );
}

void actionBegun
    (
    Flurry::Dialog &dialog,
    const Flurry::Action &action
    )
{
    std::cout << action.getTitle() << " started...";
}

void actionFinished
    (
    Flurry::Dialog &dialog,
    const Flurry::Action &action
    )
{
    std::cout << "finished.\n";
}

