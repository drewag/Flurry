#include "FL_DialogResultsGeneratedEvent.h"

#include "FL_Object.h"

namespace Flurry
{

DialogResultsGeneratedEvent::DialogResultsGeneratedEvent
    (
    DialogEventEmitter* emitter, //!< Emitter that calls callbacks
    const ObjectList &newResults //!< results generated
    )
    : DialogEvent( emitter )
    , results( newResults )
{
}

DialogResultsGeneratedEvent::DialogResultsGeneratedEvent
    (
    const DialogResultsGeneratedEvent &other
    )
    : DialogEvent( other )
    , results( other.results )
{
}

/* virtual */ DialogEvent* DialogResultsGeneratedEvent::clone() const
{
    return new DialogResultsGeneratedEvent( *this );
}

/* virtual */ DialogResultsGeneratedEvent::~DialogResultsGeneratedEvent()
{
}

} // namespace Flurry
