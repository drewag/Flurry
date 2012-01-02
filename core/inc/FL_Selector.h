#ifndef FL_Selector
#define FL_Selector

#include "FL_Object.h"

namespace Flurry
{

class ConcreteSelector;
class Category;

class Selector : public Object
{
    public:
        //! Constructor
        Selector
            (
            ConcreteSelector* sel   //!< Concrete Selector to use
            );

        //! Conversion constructor from Object
        Selector
            (
            const Object &other
            );

        //! Destructor
        ~Selector();
        
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

        //! @returns The Selector Category
        static Category selectorCategory();

    private:
        //! Disabled empty constructor
        Selector();

}; // class Selector

} // namespace Flurry

#endif // FL_Selector
