#include "FL_Mod_Connection.h"

#include <boost/signals2.hpp>

void mod_connection_close
    (
    Mod_Connection* connection
    )
{
    boost::signals2::connection* conn = (boost::signals2::connection*)connection;
    // TODO close connection
    delete conn;
}
