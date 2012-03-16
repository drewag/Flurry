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

Mod_Object* mod_object_copy
    (
    Mod_Object* object
    )
{
    Object* obj = new Object( *(Object*)object );
    return (Mod_Object*)obj;
}

const char* mod_object_get_title
    (
    const Mod_Object* object
    )
{
    Object* obj = (Object*)object;
    return obj->getTitle().c_str();
}

void mod_object_destroy
    (
    Mod_Object* obj
    )
{
    delete (Object*)obj;
}
