#include "FL_CoreModule.h"

#include "FL_CategoryManager.h"
#include "FL_SelectorManager.h"
#include "FL_ActionManager.h"
#include "FL_ObjectList.h"
#include "FL_Category.h"
#include "FL_Selector.h"
#include "FL_Action.h"
#include "FL_NamedConcreteSelector.h"

namespace Flurry
{

CoreModule::CoreModule()
    : mCategoryList( NULL )
    , mActionList( NULL )
    , mSelectorList( NULL )
{
    // Setup Categories
    mCategoryList = new ObjectList();
    mCategoryList->add( Category::categoryCategory() );
    mCategoryList->add( Action::actionCategory() );
    mCategoryList->add( Selector::selectorCategory() );

    // Setup Actions
    mActionList = new ObjectList();

    // Setup Selectors
    mSelectorList = new ObjectList();
    mSelectorList->add( CoreModule::namedSelector() );
}

/* static */ Selector &CoreModule::namedSelector()
{
    static Selector* named = NULL;
    
    if( NULL == named )
    {
        NamedConcreteSelector* concreteNamed = new NamedConcreteSelector();
        named = new Selector( concreteNamed );
        concreteNamed->release();
        concreteNamed = NULL;
    }

    return *named;
}

/* virtual */ CoreModule::~CoreModule()
{
    delete mCategoryList;
    delete mActionList;
    delete mSelectorList;
}

/* virtual */ const ObjectList &CoreModule::refreshCategories()
{
    return *mCategoryList;
}

/* virtual */ const ObjectList &CoreModule::refreshActions()
{
    return *mActionList;
}

/* virtual */ const ObjectList &CoreModule::refreshSelectors()
{
    return *mSelectorList;
}

} // namespace Flurry
