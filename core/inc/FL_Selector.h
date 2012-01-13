#ifndef FL_Selector
#define FL_Selector

#include "FL_Object.h"
#include "FL_ObjectList.h"
#include "FL_Mod_Selector.h"

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
            std::string title,                             //!< Display title of this selector
            MatchObjectFunc func,                          //!< Function to check if objects matches selector
            const ObjectList &categories = ObjectList()    //!< List of categories that this selector supports
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
