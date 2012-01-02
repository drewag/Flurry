#include "FL_DialogEventEmitter.h"

#include "FL_Dialog.h"

namespace Flurry
{

DialogEventEmitter::DialogEventEmitter
    (
    Dialog* dialog
    )
    : mDialog( dialog )
{
}

DialogEventEmitter::~DialogEventEmitter()
{
    // Intentionally not deleting mDialog
}

} // namespace Flurry

