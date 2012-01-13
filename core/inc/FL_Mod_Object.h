#ifndef FL_Mod_Object
#define FL_Mod_Object

#ifdef __cplusplus
extern "C" {
#endif

typedef void Mod_Object;

//! Create an Object
//!
//! Need to call destroy when done with the Object.
Mod_Object* mod_object_create
    (
    const char* title,      //!< Title of the Object (will be copied)
    Mod_Object* category    //!< Category this object is in
    );

//! Destroy the given Object
//!
//! The pointer passed in will be set to NULL
void mod_object_destroy
    (
    Mod_Object* obj //!< Object to destroy
    );

#ifdef __cplusplus
}
#endif

#endif
