#ifndef FL_DialogEvent
#define FL_DialogEvent

#include "FL_DialogEventEmitter.h"

#include <boost/signals2.hpp>

namespace Flurry
{

class SynchronisedEventQueue;
class Dialog;
class DialogEventEmitter;

class DialogEvent
{
    friend class Dialog;
    friend class DialogEventEmitter;

    public:
        //! Destructor
        virtual ~DialogEvent();

        //! Create this element as a copy of other
        virtual DialogEvent* clone() const;

    protected:
        //! Constructor
        DialogEvent
            (
            DialogEventEmitter* emitter
            );

        //! Call callbacks registered for this event
        void emmit();

        //! Copy Constructor
        //!
        //! Public classes should use clone instead
        DialogEvent
            (
            const DialogEvent &other
            );

    private:
        //! Disabled default constructor
        DialogEvent();

    private:
        DialogEventEmitter* mEmitter;    //!< dialog owner of this emitter

}; // class DialogEvent

} // namespace Flurry

#endif // FL_DialogEvent
