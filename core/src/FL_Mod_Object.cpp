#include "FL_Mod_Object.h"

#include <stdlib.h>
#include <string.h>

#include "FL_Object.h"
#include "FL_Category.h"

using namespace Flurry;

Mod_Object* mod_object_create
    (
    const char* title,
    Mod_Object* category
    )
{
    Object* obj = new Object( title, *((Category*)category) );
    return (Mod_Object*)obj;
}

void mod_object_destroy
    (
    Mod_Object* obj
    )
{
    delete (Object*)obj;
}
