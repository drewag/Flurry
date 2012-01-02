#ifndef FL_Object
#define FL_Object

#include <string>

#define PRINT_OBJECT_TREE

namespace Flurry
{

class Category;
class Selector;
class Action;
class ConcreteObject;

class Object
{
    public:
        friend class Category;
        friend class Selector;
        friend class Action;

        //! Constructor
        Object
            (
            std::string title
            );

        //! Destructor
        virtual ~Object();

        //! Copy Constructor
        Object
            (
            const Object &other //!< Object to copy
            );

        //! Assignment operator
        Object &operator=
            (
            const Object &other //!< Object to copy
            );

        //! Less than operator
        //!
        //! @return true if this is less than rhs
        bool operator<
            (
            const Object &rhs //!< Object to compare
            ) const;

        //! Equality operator
        bool operator==
            (
            const Object &other //!< Object to compare to
            ) const;

        //! @return true if this object is of the given Category
        bool isOfCategory
            (
            const Category &cat //!< Category to test against
            ) const;

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

        //! @return the title of this Object
        const std::string &getTitle() const;

    protected:
        //! Constructor for subclasses where mConcrete is not set
        Object();

        ConcreteObject* mConcrete; //!< Shared actual instance of this object

}; // class Object

} // namespace Flurry

#endif // FL_Object
