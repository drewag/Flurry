#ifndef FL_ConcreteAction
#define FL_ConcreteAction

#include "FL_ConcreteObject.h"
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
            std::string title
            );

        //! Destructor
        virtual ~ConcreteAction();

        //! Delete this object. Subclasses must override this to
        //! delete the pointer with a proper pointer type
        virtual void destroy() = 0;

}; // class ConcreteAction

} // namespace Flurry

#endif // FL_ConcreteAction
