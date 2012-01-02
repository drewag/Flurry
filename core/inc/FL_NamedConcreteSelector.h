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

        //! @return true if selector supports the given category
        virtual bool doesSupportCategory
            (
            const Category &cat  //!< Object to check if it matches
            ) const;

}; // class NamedConcreteSelector

} // namespace Flurry

#endif // FL_NamedConcreteSelector
