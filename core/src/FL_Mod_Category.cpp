#include "FL_Mod_Category.h"

#include "FL_Category.h"

using namespace Flurry;

Mod_Category* mod_category_create
    (
    const char* title,
    bool objectsAreSearchable
    )
{
    Category* cat = new Category( title, objectsAreSearchable );
    return (Mod_Category*)cat;
}

void mod_category_destroy
    (
    Mod_Category* cat
    )
{
    delete (Category*)cat;
}
