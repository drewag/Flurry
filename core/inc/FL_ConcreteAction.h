#ifndef FL_ConcreteAction
#define FL_ConcreteAction

#include "FL_ConcreteObject.h"
#include "FL_ObjectList.h"

#include <string>

namespace Flurry
{

class Object;

class ConcreteAction : public ConcreteObject
{
    public:
        //! Constructor
        ConcreteAction
            (
            std::string title,               //!< The title of this action
            const ObjectList inputCategories //!< The categories of input that this action needs
            );

        //! Destructor
        virtual ~ConcreteAction();

        //! Get the categories of input that this action needs
        virtual const ObjectList &getInputCategories();

        //! Delete this object. Subclasses must override this to
        //! delete the pointer with a proper pointer type
        virtual void destroy() = 0;

    private:
        const ObjectList mInputCategories; //!< The categories of input that this action needs

}; // class ConcreteAction

} // namespace Flurry

#endif // FL_ConcreteAction
