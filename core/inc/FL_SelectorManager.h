#ifndef FL_SelectorManager
#define FL_SelectorManager

#include "FL_ObjectManager.h"

namespace Flurry
{

class Category;
class Module;

class SelectorManager : public ObjectManager
{
    public:
        //! Constructor
        SelectorManager();

        //! Destructor
        ~SelectorManager();

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

#endif // FL_SelectorManager
