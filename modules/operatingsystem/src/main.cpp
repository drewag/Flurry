#include "FL_Mod_Object.h"
#include "FL_Mod_Category.h"
#include "FL_Mod_Selector.h"
#include "FL_Mod_Action.h"

#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

Mod_Category* gCategories = NULL;
unsigned int gNumCategories = 0;

void load()
{
    gCategories = mod_category_create( "Application" );
    Mod_Object* obj = mod_object_create( "Photoshop", gCategories );
    obj = mod_object_create( "Illustrator", gCategories );
    obj = mod_object_create( "Finder", gCategories );
    gNumCategories = 1;
}

void unload()
{
    for( unsigned int i = 0; i < gNumCategories; i++ )
    {
        mod_category_destroy( &gCategories[i] );
    }
}

void refreshCategories
    (
    Mod_Category** &categories,
    unsigned int &numCategories
    )
{
    categories = &gCategories;
    numCategories = gNumCategories;
}

void refreshActions
    (
    Mod_Action** &actions,
    unsigned int &numActions
    )
{
    actions = NULL;
    numActions = 0;
}

void refreshSelectors
    (
    Mod_Selector** &selectors,
    unsigned int &numSelectors
    )
{
    selectors = NULL;
    numSelectors = 0;
}

#ifdef __cplusplus
}
#endif
