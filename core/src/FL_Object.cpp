#include "FL_Object.h"

#include "FL_Category.h"
#include "FL_ConcreteObject.h"

#include <iostream>

namespace Flurry
{

Object::Object()
    : mConcrete( NULL )
{
    // mConcrete intentionally not set
}

Object::Object
    (
    std::string title
    )
{
    mConcrete = new ConcreteObject( title );
}

Object::Object
    (
    const Object &other
    )
{
    mConcrete = other.mConcrete;
    mConcrete->retain();
}

/* virtual */ Object::~Object()
{
    mConcrete->release();
    mConcrete = NULL;
}

Object &Object::operator=
    (
    const Object &other
    )
{
    mConcrete = other.mConcrete;
    mConcrete->retain();

    return *this;
}

bool Object::operator==
    (
    const Object &other //!< Object to compare to
    ) const
{
    return other.mConcrete == mConcrete;
}

bool Object::operator<
    (
    const Object &rhs
    ) const
{
    return mConcrete->getTitle() < rhs.mConcrete->getTitle();
}

bool Object::isOfCategory
    (
    const Category &cat
    ) const
{
    return mConcrete->isOfCategory( cat );
}

const std::string &Object::getTitle() const
{
    return mConcrete->getTitle();
}

void Object::addCategory
    (
    const Category &cat
    )
{
    return mConcrete->addCategory( cat );
}

void Object::removeCategory
    (
    const Category &cat
    )
{
    return mConcrete->removeCategory( cat );
}

} // namespace Flurry
