#include "FL_Object.h"

#ifndef FL_Category
#define FL_Category

#include "FL_Mod_Category.h"
#include <string>

namespace Flurry
{

class Selector;
class ObjectList;

class Category : public Object
{
    public:
        //! Constructor
        Category
            (
            std::string title,               //!< Display title of this category
            bool objectsAreSearchable = true //!< If objects in this category should
                                             //!  show up in object searches
            );

        //! Constructor
        Category
            (
            Mod_Category* cat   //!< C category object to create this new category from
            );

        //! Conversion constructor from Object
        Category
            (
            const Object &other
            );

        //! Destructor
        ~Category();

        //! @returns an instance of a Category Category
        static Category categoryCategory();

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
        //! Disabled empty constructor
        Category();

}; // class Category

} // namespace Flurry

#endif // FL_Category
