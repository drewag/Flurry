#ifndef FL_DialogActionBegunEvent
#define FL_DialogActionBegunEvent

#include "FL_DialogEvent.h"
#include "FL_Action.h"

namespace Flurry
{

class Action;
class DialogActionBegunEventEmitter;

class DialogActionBegunEvent : public DialogEvent
{
    friend class DialogActionBegunEventEmitter;

    public:
        //! Create this element as a copy of other
        virtual DialogEvent* clone
            (
            const DialogEvent* other
            );

    protected:
        //! Copy constructor
        DialogActionBegunEvent
            (
            const DialogActionBegunEvent &other
            );

        //! Constructor
        DialogActionBegunEvent
            (
            DialogEventEmitter* emitter, //!< Emitter that calls callbacks
            const Action &action         //!< results generated
            );

    private:
        Action action; //!< action that started

}; // class DialogActionBegunEvent

} // namespace Flurry

#endif // FL_DialogActionBegunEvent
