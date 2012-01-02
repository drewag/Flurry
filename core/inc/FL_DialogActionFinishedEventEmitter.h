#ifndef FL_DialogActionFinishedEventEmitter
#define FL_DialogActionFinishedEventEmitter

#include "FL_DialogEventEmitter.h"

#include <boost/signals2.hpp>

namespace Flurry
{

class Dialog;
class Action;
class DialogEvent;

class DialogActionFinishedEventEmitter : public DialogEventEmitter
{
    public:
        //! Signal for when an action has finished performing
        typedef boost::signals2::signal<void
            (
            Dialog &,       //!< Dialog that finished action
            const Action &  //!< Action that finished
            )> Signal;

    public:
        //! Constructor
        DialogActionFinishedEventEmitter
            (
            Dialog* dialog //!< dialog owner of this emitter
            );

        //! Destructor
        ~DialogActionFinishedEventEmitter();

        //! Create a new event instance
        //!
        //! (Must call delete on the pointer when done with it
        DialogEvent* newEvent
            (
            const Action &action
            );

        //! Connect to this event
        boost::signals2::connection connect
            (
            Signal::slot_type slot
            );

    private:
        //! Call callbacks registered for this event
        virtual void emmit
            (
            DialogEvent* event //!< Event instance to emmit
            );

    private:
        Signal mSignal; //!< Signal to call the callbacks

}; // class DialogActionFinishedEventEmitter

} // namespace Flurry

#endif // FL_DialogActionFinishedEventEmitter
