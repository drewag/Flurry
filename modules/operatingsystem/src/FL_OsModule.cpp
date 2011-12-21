#include "FL_OsModule.h"
#include "FL_Object.h"
#include "FL_Category.h"

#include <iostream>

namespace Flurry
{

OsModule::OsModule()
    : mApplications( NULL )
{
    mApplications = new Category( "Application" );

    Object* obj = new Object( "Photoshop" );
    mApplications->addObject( *obj );
    delete obj;
    obj = new Object( "Illustrator" );
    mApplications->addObject( *obj );
    delete obj;
    obj = new Object( "Finder" );
    mApplications->addObject( *obj );
    delete obj;
    obj = NULL;

    mCategoryList.add( *mApplications );
}

OsModule::~OsModule()
{
    delete mApplications;
}

/* virtual */ const ObjectList &OsModule::refreshCategories()
{
    return mCategoryList;
}

/* virtual */ const ObjectList &OsModule::refreshActions()
{
    return mActionList;
}

/* virtual */ const ObjectList &OsModule::refreshSelectors()
{
    return mSelectorList;
}

} // namespace Flurry
