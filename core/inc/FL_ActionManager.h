#ifndef FL_ActionManager
#define FL_ActionManager

#include "FL_ObjectManager.h"

namespace Flurry
{

class ActionManager : public ObjectManager
{
    public:
        //! Constructor
        ActionManager();

        //! Destructor
        ~ActionManager();

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

#endif // FL_ActionManager
