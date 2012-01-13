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
    mConcrete = new ConcreteCategory
        (
        title,
        objectsAreSearchable
        );
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
}

void Category::removeObjects
    (
    ObjectList &list
    )
{
    ((ConcreteCategory*)mConcrete)->removeObjects( list );
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
}

} // namespace Flurry
