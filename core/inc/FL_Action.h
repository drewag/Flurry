#ifndef FL_Action
#define FL_Action

#include "FL_Object.h"

namespace Flurry
{

class ConcreteAction;
class ObjectList;
class Category;

class Action : public Object
{
    public:
        //! Constructor
        Action
            (
            ConcreteAction* sel   //!< Concrete Action to use
            );

        //! Conversion constructor from Object
        Action
            (
            const Object &other
            );

        //! Destructor
        ~Action();

        //! Get the categories of input that this action needs
        const ObjectList &getInputCategories();

        //! @returns The Action Category
        static Category actionCategory();

    private:
        //! Disabled empty constructor
        Action();

}; // class Action

} // namespace Flurry

#endif // FL_Action
