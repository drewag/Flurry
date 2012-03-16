#ifndef FL_Mod_Connection
#define FL_Mod_Connection

#ifdef __cplusplus
extern "C" {
#endif

typedef void Mod_Connection;

void mod_connection_close
    (
    Mod_Connection* connection
    );

#ifdef __cplusplus
}
#endif

#endif
