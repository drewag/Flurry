#ifndef FL_ConcreteSelector
#define FL_ConcreteSelector

#include "FL_ConcreteObject.h"
#include <string>

namespace Flurry
{

class Object;

class ConcreteSelector : public ConcreteObject
{
    public:
        //! Constructor
        ConcreteSelector
            (
            std::string title
            );

        //! Destructor
        virtual ~ConcreteSelector();

        //! Delete this object. Subclasses must override this to
        //! delete the pointer with a proper pointer type
        virtual void destroy() = 0;

        //! @return true if selector matches the given object
        virtual bool doesObjectMatch
            (
            std::string text,  //!< text to match with
            const Object &obj  //!< Object to check if it matches
            ) const = 0;

}; // class ConcreteSelector

} // namespace Flurry

#endif // FL_ConcreteSelector
