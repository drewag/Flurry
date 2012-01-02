#include "FL_DialogActionBegunEvent.h"

namespace Flurry
{

DialogActionBegunEvent::DialogActionBegunEvent
    (
    DialogEventEmitter* emitter, //!< Emitter that calls callbacks
    const Action &action         //!< Action that has started
    )
    : DialogEvent( emitter )
    , action( action )
{
}

DialogActionBegunEvent::DialogActionBegunEvent
    (
    const DialogActionBegunEvent &other
    )
    : DialogEvent( other )
    , action( other.action )
{
}

/* virtual */ DialogEvent* DialogActionBegunEvent::clone
    (
    const DialogEvent* other
    )
{
    return new DialogActionBegunEvent( *this );
}

} // namespace Flurry
