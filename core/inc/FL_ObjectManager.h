#ifndef FL_ObjectManager
#define FL_ObjectManager

#include <map>

namespace Flurry
{

class Module;
class Category;
class ObjectList;

class ObjectManager
{
    public:
        //! Refresh the objects loaded from the given module
        bool refreshModule
            (
            Module &mod //!< The module to refresh
            );

        //! Unload module
        bool unloadModule
            (
            Module &mod //!< Module to unload
            );

        //! @returns list of all objects managed by this manager
        ObjectList getAllObjects();
        
    protected:
        //! Constructor
        ObjectManager();

        //! Destructor
        virtual ~ObjectManager();

        //! Get the category that this Manager is managing objects for
        virtual Category getCategory() const = 0;

        //! @return an object list of all objects to be managed by this manager
        virtual const ObjectList &loadObjectsFromMod
            (
            Module &mod
            ) = 0;

    protected:
        //! A Map of lists of objects
        typedef std::map<std::string,ObjectList> ObjectMap;

        ObjectMap* mObjectMap; //!< Map of object lists for each loaded module

};

} // namespace Flurry

#endif // FL_ObjectManager
