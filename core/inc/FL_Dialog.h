#ifndef FL_Dialog
#define FL_Dialog

#include <string>

namespace Flurry
{

class ModuleManager;
class ObjectList;
class Category;
class Selector;

class Dialog
{
    public:
        //! Constructor
        Dialog
            (
            Flurry::ModuleManager &moduleManager
            );

        //! Search for an object matching text
        //!
        //! @return list of matching objects
        const ObjectList &findObjectNamed
            (
            std::string text    //!< Text to search with
            );

        //! Search for an object matching text
        //!
        //! @return list of matching objects
        const ObjectList &findObjectWithSelector
            (
            std::string text,   //!< Text to search with
            Selector &sel       //!< Selector to filter objects with
            );

        //! Search for selectors that support
        //! the given category
        //!
        //! @returns list of selectors
        const ObjectList &findSelectorForCategory
            (
            const Category &cat, //!< Category to make sure is supported
            std::string text     //!< Text to match agains the name of the selector
            );

    private:
        ObjectList* mResults; //!< Most recent results

        ModuleManager* mModuleManager; //!< Object to manage all of the objects
                                       //!< loaded in modules

}; // class Dialog

} // namespace Flurry

#endif // FL_Dialog
