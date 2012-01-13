#ifndef FL_ConcreteSelector
#define FL_ConcreteSelector

#include "FL_ConcreteObject.h"
#include "FL_Mod_Selector.h"
#include <string>

namespace Flurry
{

class Object;
class ObjectList;

class ConcreteSelector : public ConcreteObject
{
    public:
        //! Constructor
        ConcreteSelector
            (
            std::string title,
            MatchObjectFunc func,
            const ObjectList &supportedCategories
            );

        //! Destructor
        virtual ~ConcreteSelector();

        //! Delete this object. Subclasses must override this to
        //! delete the pointer with a proper pointer type
        virtual void destroy();

        //! @return true if selector matches the given object
        bool doesObjectMatch
            (
            std::string text,  //!< text to match with
            const Object &obj  //!< Object to check if it matches
            ) const;

        //! @return true if selector supports the given category
        bool doesSupportCategory
            (
            const Category &cat  //!< Object to check if it matches
            ) const;

    private:
        MatchObjectFunc mMatchObjectFunc; //! Function to call to match object

        ObjectList* mCategories; //!< List of supported categories

}; // class ConcreteSelector

} // namespace Flurry

#endif // FL_ConcreteSelector
