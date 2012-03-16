#ifndef FL_DialogActionBegunEventEmitter
#define FL_DialogActionBegunEventEmitter

#include "FL_DialogEventEmitter.h"

namespace Flurry
{

class Action;
class Dialog;
class DialogEvent;

class DialogActionBegunEventEmitter : public DialogEventEmitter
{
    public:
        //! Signal for when an action has begun performing
        typedef boost::signals2::signal<void
            (
            Dialog &,       //!< Dialog that began action
            const Action &  //!< Action that began
            )> Signal;

    public:
        //! Constructor
        DialogActionBegunEventEmitter
            (
            Dialog * dialog
            );

        //! Destructor
        ~DialogActionBegunEventEmitter();

        //! Create a new event instance
        //!
        //! (Must call delete on the pointer when done with it
        DialogEvent* newEvent
            (
            const Action &action    //!< Action that has begun
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

}; // class DialogActionBegunEventEmitter

} // namespace Flurry

#endif // FL_DialogActionBegunEventEmitter
