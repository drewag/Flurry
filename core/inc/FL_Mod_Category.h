#ifndef FL_Mod_Category
#define FL_Mod_Category

#include "FL_Mod_Object.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void Mod_Category;

//! Create a Category
//!
//! The Objects array will grow as necessary but you should provide
//! the correct number of objects during construction for efficiency
//!
//! Need to call destroy when done with the Category.
Mod_Category* mod_category_create
    (
    const char* title,                //!< the title of this Category
    bool objectsAreSearchable = true  //!< If the Objects in this Category should show up in 
                                      //!  Object searches
    );

//! Destroy the given Category
//!
//! The pointer passed in will be set to NULL
void mod_category_destroy
    (
    Mod_Category* cat
    );

#ifdef __cplusplus
}
#endif

#endif
