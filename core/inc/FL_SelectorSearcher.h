#ifndef FL_SelectorSearcher
#define FL_SelectorSearcher

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

class SelectorSearcher : public Searcher
{
    public:
        //! Constructor
        SelectorSearcher
            (
            SigSearchDone::slot_type searchDoneSlot, //!< slot to callback when the search is done
            const std::string &text,                 //!< text to match
            const ObjectList &categories,            //!< categories to search based on
            const ObjectList &selectors              //!< selectors to search
            );

        //! Copy Constructor
        SelectorSearcher
            (
            const SelectorSearcher &other    //!< searcher to copy
            );

        //! Destructor
        ~SelectorSearcher();

        //! Main function of searcher thread
        virtual void operator()();

    private:
        //! Disabled empty constructor
        SelectorSearcher();

    private:
        std::string mSearchText;        //!< text to match

        ObjectList mCategories;         //!< categories to search based on

        ObjectList mSelectors;         //!< selectors to search

}; // class SelectorSearcher

} // namespace Flurry

#endif // FL_SelectorSearcher
