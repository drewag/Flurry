#include "FL_ModuleManager.h"
#include "FL_ObjectList.h"
#include "FL_Dialog.h"
#include "FL_Object.h"
#include "FL_Category.h"
#include "FL_Selector.h"

#include "FL_CategoryManager.h"

#include <iostream>
#include <vector>

Flurry::Object askForObject
    (
    Flurry::Dialog dialog
    )
{
    std::vector<Flurry::Object> resDisplay;
    Flurry::ObjectList results;

    while( 0 == resDisplay.size() )
    {
        std::cout << "Please enter an Object search term:" << std::endl;

        std::string input;
        std::cin >> input;

        results = dialog.findObjectNamed( input );
        if( 0 == resDisplay.size() )
        {
            std::cout << "No Results Found." << std::endl;
        }

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
    }
    unsigned int idx = 0;
    while( idx <= 0 || idx > results.size() )
    {
        std::cout << "Please enter a number to indicate which result to choose" << std::endl;

        std::string input;
        std::cin >> input;
        
        idx = atoi( input.c_str() );
    }
    return resDisplay[idx-1];
}

Flurry::Object askForSelector
    (
    Flurry::Dialog dialog,
    Flurry::Category cat
    )
{
    std::vector<Flurry::Object> resDisplay;
    Flurry::ObjectList results;

    while( 0 == resDisplay.size() )
    {
        std::cout << "Please enter an Selector search term:" << std::endl;

        std::string input;
        std::cin >> input;

        Flurry::ObjectList results = dialog.findSelectorForCategory( cat, input );
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
    }
    unsigned int idx = 0;
    while( idx <= 0 || idx > results.size() )
    {
        std::cout << "Please enter a number to indicate which result to choose" << std::endl;

        std::string input;
        std::cin >> input;
        
        idx = atoi( input.c_str() );
    }
    return resDisplay[idx-1];
}

int main()
{
    Flurry::ModuleManager moduleManager;

    moduleManager.registerModule( "operatingsystem" );

    Flurry::Dialog dialog
        (
        moduleManager
        );

    Flurry::Object res = askForObject( dialog );
    std::cout << "Selected: " << res.getTitle() << std::endl;
    if( res.isOfCategory( Flurry::Category::categoryCategory() ) )
    {
        Flurry::Category cat = res;
        res = askForSelector( dialog, (Flurry::Category)res );
        std::cout << "Selected: " << res.getTitle() << std::endl;
    }

    moduleManager.unregisterModule( "operatingsystem" );
}
