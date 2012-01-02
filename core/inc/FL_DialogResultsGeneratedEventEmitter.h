#ifndef FL_DialogResultsGeneratedEventEmitter
#define FL_DialogResultsGeneratedEventEmitter

#include "FL_DialogEventEmitter.h"

#include <boost/signals2.hpp>

namespace Flurry
{

class Dialog;
class ObjectList;

class DialogResultsGeneratedEventEmitter : public DialogEventEmitter
{
    public:
        //! Signal for when results are generated
        typedef boost::signals2::signal<void
            (
            Dialog &,     //!< Dialog that generated results
            ObjectList    //!< Generated results
            )> Signal;

    public:
        //! Constructor
        DialogResultsGeneratedEventEmitter
            (
            Dialog* dialog //!< dialog owner of this emitter
            );

        //! Create a new event instance
        //!
        //! (Must call delete on the pointer when done with it
        DialogEvent* newEvent
            (
            ObjectList results
            );

        //! Connect to this event
        boost::signals2::connection connect
            (
            Signal::slot_type slot
            );

    protected:
        //! Call callbacks registered for this event
        virtual void emmit
            (
            DialogEvent* event //!< Event instance to emmit
            );

    private:
        Signal mSignal; //!< Signal to call the callbacks

}; // class DialogResultsGeneratedEventEmitter

} // namespace Flurry

#endif // FL_DialogResultsGeneratedEventEmitter
