#ifndef FL_OsModule
#define FL_OsModule

#include "FL_Module.h"
#include "FL_ObjectList.h"
#include "FL_Category.h"

namespace Flurry
{

class OsModule : public Module
{
    public:
        //! Constructor
        OsModule();

        //! Destructor
        ~OsModule();

        //! @returns a fresh list of categories for this module
        virtual const ObjectList &refreshCategories();

        //! @returns a fresh list of actions for this module
        virtual const ObjectList &refreshActions();

        //! @returns a fresh list of selectors for this module
        virtual const ObjectList &refreshSelectors();

    private:
        ObjectList mCategoryList; //! Current list of categories

        ObjectList mActionList; //! Current list of actions

        ObjectList mSelectorList; //! Current list of selectors

        Category* mApplications; //! Applications category
};

} // namespace Flurry

#endif
