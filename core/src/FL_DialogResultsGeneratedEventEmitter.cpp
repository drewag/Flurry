#include "FL_DialogResultsGeneratedEventEmitter.h"

#include "FL_ObjectList.h"
#include "FL_DialogResultsGeneratedEvent.h"

namespace Flurry
{

DialogResultsGeneratedEventEmitter::DialogResultsGeneratedEventEmitter
    (
    Dialog* dialog
    )
    : DialogEventEmitter( dialog )
{
}

DialogEvent* DialogResultsGeneratedEventEmitter::newEvent
    (
    ObjectList results
    )
{
    return new DialogResultsGeneratedEvent( this, results );
}

boost::signals2::connection DialogResultsGeneratedEventEmitter::connect
    (
    Signal::slot_type slot
    )
{
    return mSignal.connect( slot );
}

/* virtual */ void DialogResultsGeneratedEventEmitter::emmit
    (
    DialogEvent* event
    )
{
    mSignal( *mDialog, ((DialogResultsGeneratedEvent*)event)->results );
}

} // namespace Flurry
