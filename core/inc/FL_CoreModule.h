#ifndef FL_CoreModule
#define FL_CoreModule

#include "FL_Module.h"

namespace Flurry
{

class ObjectList;
class Selector;

class CoreModule : public Module
{
    public:
        //! Constructor
        CoreModule();

        //! Destructor
        virtual ~CoreModule();

        //! @returns a fresh list of categories for this module
        virtual const ObjectList &refreshCategories();

        //! @returns a fresh list of actions for this module
        virtual const ObjectList &refreshActions();

        //! @returns a fresh list of selectors for this module
        virtual const ObjectList &refreshSelectors();

        static Selector &namedSelector();

    private:
        ObjectList* mCategoryList; //! Current list of categories

        ObjectList* mActionList; //! Current list of actions

        ObjectList* mSelectorList; //! Current list of selectors

}; // class CoreModule

} // namespace Flurry

#endif FL_CoreModule
