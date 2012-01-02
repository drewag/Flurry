#ifndef FL_DialogActionFinishedEvent
#define FL_DialogActionFinishedEvent

#include "FL_DialogEvent.h"
#include "FL_Action.h"

namespace Flurry
{

class Action;
class DialogActionFinishedEventEmitter;

class DialogActionFinishedEvent : public DialogEvent
{
    friend class DialogActionFinishedEventEmitter;

    public:
        //! Constructor
        DialogActionFinishedEvent
            (
            DialogEventEmitter* emitter, //!< Emitter that calls callbacks
            const Action &action         //!< action finished
            );

        //! Create this element as a copy of other
        virtual DialogEvent* clone() const;


    protected:
        //! Copy Constructor
        DialogActionFinishedEvent
            (
            const DialogActionFinishedEvent &other
            );

    public:
        Action action; //!< action that finished

}; // class DialogActionFinishedEvent

} // namespace Flurry

#endif // FL_DialogActionFinishedEvent
