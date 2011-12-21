#ifndef FL_Module
#define FL_Module

#include <string>

namespace Flurry
{

class ObjectList;

class Module
{
    friend class ModuleManager;

    public:
        //! Constructor
        Module();

        //! Destructor
        virtual ~Module();

        //! @returns a fresh list of categories for this module
        virtual const ObjectList &refreshCategories() = 0;

        //! @returns a fresh list of actions for this module
        virtual const ObjectList &refreshActions() = 0;

        //! @returns a fresh list of selectors for this module
        virtual const ObjectList &refreshSelectors() = 0;

        //! Set the handle of the dynamic library that this instance
        //! is within
        void setLibHndl( void* hndl );

        //! @return the handle of the dynamic library that this
        //! instance is within
        void* getLibHndl();

        //! @return the name of this module
        std::string getName() const;

    protected:
        //! Set the name of this module
        void setName
            (
            std::string name
            );

    private:
        void* mLibHndl; //!< Handle of the dynamic library that
                        //!  this instance is within

        std::string mName; //!< The name of this module
};

//! Factory create function
typedef Module* (*ModuleMaker)();

//! Factory destroy function
typedef void (*ModuleDestroyer)( Module* );

} // namespace Flurry

#endif
