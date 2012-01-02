#include "FL_DialogEvent.h"

namespace Flurry
{

DialogEvent::DialogEvent
    (
    DialogEventEmitter* emitter
    )
    : mEmitter( emitter )
{
    if( NULL == emitter )
    {
        //TODO: throw exception
    }
}

DialogEvent::DialogEvent
    (
    const DialogEvent &other
    )
{
    mEmitter = other.mEmitter;
}

/* virtual */ DialogEvent* DialogEvent::clone() const
{
    return new DialogEvent( *this );
}

DialogEvent::~DialogEvent()
{
    // Intentionally not deleting mEmitter
}

void DialogEvent::emmit()
{
    mEmitter->emmit( this );
}

} // namespace Flurry
