#ifndef FL_ConcreteObject
#define FL_ConcreteObject

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
            std::string title //! Display title of the new object
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

        //! Make this object part of the given category
        void addCategory
            (
            const Category &cat //!< Category to add as a parent of this object
            );

        //! Make this object no longer part of the given category
        void removeCategory
            (
            const Category &cat //!< Category to remove as a parent of this object
            );

    protected:
        //! No other objects can destroy this
        ~ConcreteObject();

    private:
        //! Disable default constructor
        ConcreteObject();

    private:
        unsigned long mRetainCount; //!< Number of objects that own this

        ObjectList* mCategories; //!< Categories that this object belongs to

        std::string mTitle; //! Display title of this object

#ifdef DEBUG_OBJECT_LIFECYCLE
        unsigned long long mId;
#endif
};

} // namespace Flurry

#endif // FL_ConcreteObject
