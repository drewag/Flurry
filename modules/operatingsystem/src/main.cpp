#include "FL_OsModule.h"

#include <iostream>

extern "C"
Flurry::Module* create()
{
    return (Flurry::Module*)new Flurry::OsModule();
}

extern "C"
void destroy( Flurry::Module* module )
{
    delete module;
}
