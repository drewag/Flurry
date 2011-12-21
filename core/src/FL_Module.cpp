#include "FL_Module.h"

namespace Flurry
{

Module::Module()
    : mLibHndl( NULL )
{
}

/* virtual */ Module::~Module()
{
}

void Module::setLibHndl
    (
    void* hndl
    )
{
    mLibHndl = hndl;
}

void* Module::getLibHndl()
{
    return mLibHndl;
}

std::string Module::getName() const
{
    return mName;
}

void Module::setName
    (
    std::string name
    )
{
    mName = name;
}

} // namespace Flurry
