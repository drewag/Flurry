#include "FL_DialogActionFinishedEvent.h"

namespace Flurry
{

DialogActionFinishedEvent::DialogActionFinishedEvent
    (
    DialogEventEmitter* emitter, //!< Emitter that calls callbacks
    const Action &action         //!< Action that has started
    )
    : DialogEvent( emitter )
    , action( action )
{
}

DialogActionFinishedEvent::DialogActionFinishedEvent
    (
    const DialogActionFinishedEvent &other
    )
    : DialogEvent( other )
    , action( other.action )
{
}

/* virtual */ DialogEvent* DialogActionFinishedEvent::clone() const
{
    return new DialogActionFinishedEvent( *this );
}

} // namespace Flurry
