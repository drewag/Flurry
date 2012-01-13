#ifndef FL_ModuleManager
#define FL_ModuleManager

#include <string>
#include <map>

namespace Flurry
{

class CategoryManager;
class ObjectList;
class ObjectManager;
class ActionManager;
class SelectorManager;
class Module;
class Category;
class Selector;

class ModuleManager
{
    public:
        enum ModuleLoadStatus
        {
            MODULE_LOAD_STATUS_SUCCESSFUL,
            MODULE_LOAD_STATUS_FAILED,
            MODULE_LOAD_STATUS_ALREADY_LOADED,
            MODULE_LOAD_STATUS_NOT_FOUND,
            MODULE_LOAD_STATUS_MISSING_FUNCTION
        };

    public:
        //! Constructor
        ModuleManager();

        //! Destructor
        ~ModuleManager();

        //! Update cache of existing modules
        //!
        //! @returns true if successful
        bool refresh();

        //! Register a module
        //!
        //! Load the library and module instance
        ModuleLoadStatus registerModule
            (
            std::string name //!< name of the module to register
            );

        //! @return a list of all loaded categories
        const ObjectList getAllCategories();

        //! @return a list of all loaded selectors
        const ObjectList getAllSelectors();

        //! Unregister a module
        //!
        //! Delete module instance and unload library
        bool unregisterModule
            (
            std::string name //!< name of the module to unregister
            );

    private:
        //! Disable copy constructor
        ModuleManager
            (
            const ModuleManager& other
            );

        //! Load the given module
        bool loadModule
            (
            Module* module //!< Module to load
            );

        //! Delete the given module and unload its dynamic library
        //!
        //! @returns true if successful
        bool unloadModule
            (
            Module* module //!< Module to unload
            );

    private:
        //! A Map of modules keyed by their names
        typedef std::map<std::string, Module*> ModuleMap;

        ModuleMap mModules; //!< Currently registered modules

        CategoryManager* mCategoryManager;  //!< Manager to load categories

        ActionManager* mActionManager;      //!< Manager to load actions

        SelectorManager* mSelectorManager;  //!< Manager to load selectors

        Module* mCoreModule; //! The module that is for the core
};

} // namespace Flurry

#endif
