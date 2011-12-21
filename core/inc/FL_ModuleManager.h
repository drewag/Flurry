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
        bool registerModule
            (
            std::string name //!< name of the module to register
            );

        //! @returns a list of objects that match the given text
        ObjectList findObject
            (
            std::string text,   //!< Text to search with
            Selector &sel       //!< Selector to filter objects with
            );

        //! Search for selectors that support
        //! the given category
        //!
        //! @returns list of selectors
        const ObjectList findSelector
            (
            const Category &cat, //!< Category to make sure is supported
            std::string text     //!< Text to match agains the name of the selector
            );

        //! Unregister a module
        //!
        //! Delete module instance and unload library
        bool unregisterModule
            (
            std::string name //!< name of the module to unregister
            );

    private:
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
