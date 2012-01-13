#ifndef FL_Mod_Selector
#define FL_Mod_Selector

//#include "FL_Mod_Object.h"
//#include "FL_Mod_Category.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef void Mod_Selector;

typedef bool (*MatchObjectFunc)
    (
    const char* text,            //!< text to match with
    const char* objTitle,        //!< title of obj to match
    const char* objCategoryTitle //!< title of category of obj to match
    );

/*Mod_Selector* mod_selector_create
    (
    char* title,
    MatchObjectFunc matchObjectFunc,

    );
    */

#ifdef __cplusplus
}
#endif

#endif
