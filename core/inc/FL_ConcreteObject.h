#ifndef FL_ConcreteObject
#define FL_ConcreteObject

#include "FL_Mod_Object.h"
#include <string>

namespace Flurry
{

class Category;
class ObjectList;

class ConcreteObject
{
    public:
        //! Constructor
        ConcreteObject
            (
            std::string title, //!< Display title of the new object
            Category cat       //!< Category this object is in
            );

        //! Take ownership of this Object
        void retain();

        //! Release ownership of this Object
        void release();

        //! @return true if this object is of the given Category
        bool isOfCategory
            (
            const Category &cat //!< Category to test against
            ) const;

        //! @return the title of this Object
        const std::string &getTitle();

        //! Delete this object. Subclasses must override this to
        //! delete the pointer with a proper pointer type
        virtual void destroy();

        //! @return the category of this object
        Category getCategory() const;

    protected:
        //! Constructor for object that has NULL for category indicating
        //! that it is a Category object.
        //!
        //! Note: this is needed to prevent circular creation when creating
        //! the object for the Category category.
        ConcreteObject
            (
            std::string title //!< Display title of the new object
            );

        //! No other objects can destroy this
        ~ConcreteObject();

    private:
        //! Disable default constructor
        ConcreteObject();

    private:
        unsigned long mRetainCount; //!< Number of objects that own this

        Category* mCategory; //!< Categories that this object belongs to

        std::string mTitle; //! Display title of this object

#ifdef DEBUG_OBJECT_LIFECYCLE
        unsigned long long mId;
#endif
};

} // namespace Flurry

#endif // FL_ConcreteObject
