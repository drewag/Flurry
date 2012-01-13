#include "FL_CoreModule.h"

#include "FL_CategoryManager.h"
#include "FL_SelectorManager.h"
#include "FL_ActionManager.h"
#include "FL_ObjectList.h"
#include "FL_Category.h"
#include "FL_Selector.h"
#include "FL_Action.h"

namespace Flurry
{

CoreModule::CoreModule()
{
    mName = "FlurryCore";
}

/* virtual */ ModuleManager::ModuleLoadStatus CoreModule::load()
{
    // Setup Categories
    mCategories->add( Category::categoryCategory() );
    mCategories->add( Action::actionCategory() );
    mCategories->add( Selector::selectorCategory() );

    // Setup Actions

    // Setup Selectors
    mSelectors->add( CoreModule::namedSelector() );

    return ModuleManager::MODULE_LOAD_STATUS_SUCCESSFUL;
}

//! Unload this module from memory
/* virtual */ void CoreModule::unload()
{
}

/* static */ bool CoreModule::namedSelectorDoesObjectMatch
    (
    const char* text,
    const char* objTitle,
    const char*
    )
{
    std::string searchText( text );
    std::string title( objTitle );

    std::string::const_iterator textItr;
    textItr = searchText.begin();

    std::string::const_iterator titleItr;
    titleItr = title.begin();

    while( textItr != searchText.end()
           && titleItr != title.end() )
    {
        if( tolower( *textItr ) == tolower( *titleItr ) )
        {
            textItr++;
            titleItr++;
        }
        else
        {
            titleItr++;
        }
    }

    return textItr == searchText.end();
}

/* static */ Selector &CoreModule::namedSelector()
{
    static Selector named( "named", &CoreModule::namedSelectorDoesObjectMatch );
    
    return named;
}

/* virtual */ CoreModule::~CoreModule()
{
}

/* virtual */ const ObjectList &CoreModule::refreshCategories()
{
    return *mCategories;
}

/* virtual */ const ObjectList &CoreModule::refreshActions()
{
    return *mActions;
}

/* virtual */ const ObjectList &CoreModule::refreshSelectors()
{
    return *mSelectors;
}

} // namespace Flurry
