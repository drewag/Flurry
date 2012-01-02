#ifndef FL_ObjectSearcher
#define FL_ObjectSearcher

#include "FL_Searcher.h"

#include "FL_ObjectList.h"
#include "FL_Selector.h"

#include <boost/signal.hpp>

namespace Flurry
{

class ObjectList;
class ModuleManager;
class Selector;
class ObjectList;

class ObjectSearcher : public Searcher
{
    public:
        //! Constructor
        ObjectSearcher
            (
            SigSearchDone::slot_type searchDoneSlot, //!< slot to callback when the search is done
            const std::string &text,                 //!< text to match
            const Selector &sel,                     //!< selector to use for matching
            const ObjectList &categories             //!< categories to search within
            );

        //! Copy Constructor
        ObjectSearcher
            (
             const ObjectSearcher &other    //!< searcher to copy
            );

        //! Destructor
        ~ObjectSearcher();

        //! Main function of searcher thread
        virtual void operator()();

    private:
        //! Disabled empty constructor
        ObjectSearcher();

    private:
        std::string mSearchText;        //!< text to match

        Selector mSelector;             //!< selector to use for matching

        ObjectList mCategories;         //!< categories to search within

}; // class ObjectSearcher

} // namespace Flurry

#endif // FL_ObjectSearcher
