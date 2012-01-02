#ifndef FL_DialogEventEmitter
#define FL_DialogEventEmitter

#include <boost/signals2.hpp>

namespace Flurry
{

class Dialog;
class DialogEvent;

class DialogEventEmitter
{
    friend class DialogEvent;

    public:
        //! Constructor
        DialogEventEmitter
            (
            Dialog* dialog  //!< dialog owner of this emitter
            );

        //! Destructor
        virtual ~DialogEventEmitter();

    protected:
        //! Call callbacks registered for this event
        virtual void emmit
            (
            DialogEvent* event //!< Event instance to emmit
            ) = 0;

    protected:
        Dialog* mDialog;    //!< dialog owner of this emitter
}; // class DialogEventEmitter

} // namespace Flurry

#endif // FL_DialogEventEmitter
