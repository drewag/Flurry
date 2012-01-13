#include "FL_ObjectList.h"

#include "FL_Object.h"

namespace Flurry
{

ObjectList::ObjectList()
    : mObjects( NULL )
{
    mObjects = new std::set<Object>();
}

ObjectList::~ObjectList()
{
    delete mObjects;
}

ObjectList::ObjectList
    (
    const ObjectList &other
    )
{
    mObjects = new std::set<Object>( *other.mObjects );
}

void ObjectList::add
    (
    const Object &obj
    )
{
    mObjects->insert( obj );
}

void ObjectList::add
    (
    const ObjectList &other
    )
{
    mObjects->insert( other.mObjects->begin(), other.mObjects->end() );
}

void ObjectList::remove
    (
    const Object &obj
    )
{
    mObjects->erase( obj );
}

void ObjectList::remove
    (
    const ObjectList &list
    )
{
    ObjectList::const_iterator itr;
    itr = list.begin();
    while( list.end() != itr )
    {
        mObjects->erase( *itr );
        itr++;
    }
}

bool ObjectList::allObjectsAreOfCategory
    (
    const Category& cat
    )
{
    ObjectList::const_iterator itr;
    itr = mObjects->begin();
    while( mObjects->end() != itr )
    {
        if( !itr->isOfCategory( cat ) )
        {
            return false;
        }
        itr++;
    }
    return true;
}

bool ObjectList::containsObject
    (
    Object obj
    )
{
    ObjectList::const_iterator itr;
    itr = mObjects->find( obj );
    return mObjects->end() == itr;
}

ObjectList::iterator ObjectList::begin()
{
    return mObjects->begin();
}

ObjectList::iterator ObjectList::end()
{
    return mObjects->end();
}

ObjectList::const_iterator ObjectList::begin() const
{
    return mObjects->begin();
}

ObjectList::const_iterator ObjectList::end() const
{
    return mObjects->end();
}

unsigned int ObjectList::size() const
{
    return mObjects->size();
}

void ObjectList::clear()
{
    mObjects->clear();
}

} // namespace Flurry
