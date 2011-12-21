#ifndef FL_NamedConcreteSelector
#define FL_NamedConcreteSelector

#include "FL_ConcreteSelector.h"

namespace Flurry
{

class NamedConcreteSelector : public ConcreteSelector
{
    public:
        //! Constructor
        NamedConcreteSelector();

        //! Delete this object. Subclasses must override this to
        //! delete the pointer with a proper pointer type
        virtual void destroy();

        //! @return true if selector matches the given object
        virtual bool doesObjectMatch
            (
            std::string text,  //!< text to match with
            const Object &obj  //!< Object to check if it matches
            ) const;

}; // class NamedConcreteSelector

} // namespace Flurry

#endif // FL_NamedConcreteSelector
