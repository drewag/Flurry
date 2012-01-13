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

        //! Load this module into memory
        virtual ModuleManager::ModuleLoadStatus load();

        //! Unload this module from memory
        virtual void unload();

        //! @returns a fresh list of categories for this module
        virtual const ObjectList &refreshCategories();

        //! @returns a fresh list of actions for this module
        virtual const ObjectList &refreshActions();

        //! @returns a fresh list of selectors for this module
        virtual const ObjectList &refreshSelectors();

        static Selector &namedSelector();

        //! @return true if the given object title and category title match with the given text
        static bool namedSelectorDoesObjectMatch
            (
            const char* text,            //!< text to match with
            const char* objTitle,        //!< title of obj to match
            const char* objCategoryTitle //!< title of category of obj to match
            );

}; // class CoreModule

} // namespace Flurry

#endif FL_CoreModule
