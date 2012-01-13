#ifndef FL_ConcreteCategory
#define FL_ConcreteCategory

#include "FL_ConcreteObject.h"
#include "FL_Mod_Category.h"
#include <string>

namespace Flurry
{

class Selector;
class ObjectList;
class Object;
class Category;

class ConcreteCategory : public ConcreteObject
{
    friend class Category;

    public:
        //! Constructor
        ConcreteCategory
            (
            std::string title,                //!< Display title of this category
            bool objectsAreSearchable = true  //!< If objects in this category should
                                              //!  show up in object searches
            );

        //! Destructor
        ~ConcreteCategory();

        //! Delete this object. Subclasses must override this to
        //! delete the pointer with a proper pointer type
        virtual void destroy();

        //! @return true if objects in this category should appear in object searches
        bool areObjectsSearchable() const;

        //! @return a list of objects that match the given selector
        //! and string
        const ObjectList filterWithSelector
            (
            const Selector &sel,    //!< Selector to filter with
            const std::string &str  //!< string to use as parameter to Selector
            ) const;

        //! Add an object to this category
        void addObject
            (
            Object &obj  //!< Object to add
            );

        //! Add a list of objects from this category
        void addObjects
            (
            ObjectList &list  //!< Objects to add
            );

        //! Remove a list of objects from this category
        void removeObjects
            (
            ObjectList &list  //!< Objects to remove
            );

    private:
        ObjectList* mObjects;   //!< List of objects within this category

        bool mObjectsAreSearchable; //! True if objects in this category
                                    //! should show up in object searches

}; // class ConcreteCategory

} // namespace Flurry

#endif // FL_Category
