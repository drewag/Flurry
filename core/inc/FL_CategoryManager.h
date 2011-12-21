#ifndef FL_CategoryManager
#define FL_CategoryManager

#include "FL_ObjectManager.h"

#include <string>

namespace Flurry
{

class Module;
class ObjectList;
class Category;
class Selector;

class CategoryManager : public ObjectManager
{
    public:
        //! Constructor
        CategoryManager();

        //! Destructor
        ~CategoryManager();

        //! Find an object in all of the loaded categories that matches
        //! the given text
        ObjectList findObject
            (
            std::string text,   //!< text to match
            Selector &sel       //! Selector to filter with
            );

    protected:
        //! Get the category that this Manager is managing objects for
        virtual Category getCategory() const;

        //! @return an object list of all objects to be managed by this manager
        virtual const ObjectList &loadObjectsFromMod
            (
            Module &mod
            );
};

} // namespace Flurry

#endif // FL_CategoryManager
