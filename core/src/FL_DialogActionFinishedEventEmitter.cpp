#include "FL_DialogActionFinishedEventEmitter.h"

#include "FL_DialogActionFinishedEvent.h"

namespace Flurry
{

DialogActionFinishedEventEmitter::DialogActionFinishedEventEmitter
    (
    Dialog * dialog
    )
    : DialogEventEmitter( dialog )
{
}

DialogActionFinishedEventEmitter::~DialogActionFinishedEventEmitter()
{
}

DialogEvent* DialogActionFinishedEventEmitter::newEvent
    (
    const Action &action
    )
{
    return new DialogActionFinishedEvent( this, action );
}

boost::signals2::connection DialogActionFinishedEventEmitter::connect
    (
    Signal::slot_type slot
    )
{
    return mSignal.connect( slot );
}

/* virtual */ void DialogActionFinishedEventEmitter::emmit
    (
    DialogEvent* event
    )
{
    mSignal( *mDialog, ((DialogActionFinishedEvent*)event)->action );
}

} // namespace Flurry
