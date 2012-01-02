#include "FL_DialogActionBegunEventEmitter.h"

#include "FL_DialogActionBegunEvent.h"

namespace Flurry
{

DialogActionBegunEventEmitter::DialogActionBegunEventEmitter
    (
    Dialog * dialog
    )
    : DialogEventEmitter( dialog )
{
}

DialogActionBegunEventEmitter::~DialogActionBegunEventEmitter()
{
}

DialogEvent* DialogActionBegunEventEmitter::newEvent
    (
    const Action &action
    )
{
    return new DialogActionBegunEvent( this, action );
}

boost::signals2::connection DialogActionBegunEventEmitter::connect
    (
    Signal::slot_type slot
    )
{
    return mSignal.connect( slot );
}

/* virtual */ void DialogActionBegunEventEmitter::emmit
    (
    DialogEvent* event
    )
{
    mSignal( *mDialog, ((DialogActionBegunEvent*)event)->action );
}

} // namespace Flurry
