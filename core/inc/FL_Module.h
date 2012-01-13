#ifndef FL_Module
#define FL_Module

#include <string>
#include "FL_ModuleManager.h"

namespace Flurry
{

class ObjectList;

class Module
{
    public:
        //! Constructor
        Module
            (
            std::string name    //!< The name of the module to load
            );

        //! Destructor
        virtual ~Module();

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

        //! @return the name of this module
        std::string getName() const;

    protected:
        //! Constructor for subclasses that don't use a dll
        Module();

    protected:
        ObjectList* mCategories; //!< List of categoires in this module

        ObjectList* mActions; //!< List of categoires in this module

        ObjectList* mSelectors; //!< List of categoires in this module

        std::string mName; //!< The name of this module

    private:
        void* mLibHndl; //!< Handle of the dynamic library that
                        //!  this instance is within

};

} // namespace Flurry

#endif
