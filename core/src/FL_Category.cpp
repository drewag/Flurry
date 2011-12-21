#include "FL_Category.h"

#include "FL_ConcreteCategory.h"
#include "FL_CategoryManager.h"
#include "FL_ObjectList.h"

#include <iostream>

namespace Flurry
{

Category::Category
    (
    std::string title,
    bool objectsAreSearchable
    )
{
    mConcrete = new ConcreteCategory( title, objectsAreSearchable );
}

Category::Category
    (
    const Object &other
    )
{
    if( !other.isOfCategory( Category::categoryCategory() ) )
    {
        // TODO throw exception
    }

    mConcrete = other.mConcrete;
    mConcrete->retain();
}

Category::~Category()
{
}

bool Category::areObjectsSearchable() const
{
    return ((ConcreteCategory*)mConcrete)->areObjectsSearchable();
}

/* static */ Category Category::categoryCategory()
{
    static Category category( "Category" );
    return category;
}

void Category::addObjects
    (
    ObjectList &list
    )
{
    ((ConcreteCategory*)mConcrete)->addObjects( list );

    ObjectList::iterator itr;
    itr = list.begin();
    while( list.end() != itr )
    {
        Object obj = *itr;
        obj.addCategory( *this );
        itr++;
    }
}

void Category::removeObjects
    (
    ObjectList &list
    )
{
    ((ConcreteCategory*)mConcrete)->removeObjects( list );
    
    ObjectList::iterator itr;
    itr = list.begin();
    while( list.end() != itr )
    {
        Object obj = *itr;
        obj.removeCategory( *this );
        itr++;
    }
}

const ObjectList Category::filterWithSelector
    (
    const Selector &sel,
    const std::string &str
    ) const
{
    return ((ConcreteCategory*)mConcrete)->filterWithSelector( sel, str );
}

void Category::addObject
    (
    Object &obj 
    )
{
    ((ConcreteCategory*)mConcrete)->addObject( obj );
    obj.addCategory( *this );
}

} // namespace Flurry
