#include "FL_Dialog.h"

#include "FL_ObjectList.h"
#include "FL_ModuleManager.h"
#include "FL_Object.h"
#include "FL_CoreModule.h"

namespace Flurry
{

Dialog::Dialog
    (
    Flurry::ModuleManager &moduleManager
    )
    : mResults( NULL )
    , mModuleManager( &moduleManager )
{
}

const ObjectList &Dialog::findObjectNamed
    (
    std::string text
    )
{
    return this->findObjectWithSelector( text, CoreModule::namedSelector() );
}

const ObjectList &Dialog::findObjectWithSelector
    (
    std::string text,
    Selector &sel
    )
{
    if( NULL != mResults )
    {
        delete mResults;
    }
    mResults = new ObjectList( mModuleManager->findObject( text, sel ) );
    return *mResults;
}

const ObjectList &Dialog::findSelectorForCategory
    (
    const Category &cat,
    std::string text
    )
{
    if( NULL != mResults )
    {
        delete mResults;
    }
    mResults = new ObjectList( mModuleManager->findSelector( cat, text ) );
    return *mResults;
}

} // namespace Flurry
