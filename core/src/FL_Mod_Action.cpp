#include "FL_Mod_Action.h"

#include "FL_Action.h"

using namespace Flurry;

Mod_Action* mod_action_create()
{
    // TODO: Set concrete action
    Action* action = new Action( NULL );
    return (Mod_Action*)action;
}

void mod_action_destroy
    (
    Mod_Action* action
    )
{
    delete (Action*)action;
}

const char* mod_action_get_title
    (
    const Mod_Action* action
    )
{
    Action* act = (Action*)act;
    return act->getTitle().c_str();
}
