#ifndef FL_ActionSearcher
#define FL_ActionSearcher

#include "FL_Searcher.h"

#include "FL_ObjectList.h"
#include "FL_Selector.h"


#include <string>
#include <boost/signal.hpp>

namespace Flurry
{

class ObjectList;
class ModuleManager;

class ActionSearcher : public Searcher
{
    public:
        //! Constructor
        ActionSearcher
            (
            const std::string &text,                 //!< text to match
            const ObjectList &actions,               //!< actions to search
            const ObjectList &input                  //!< categories to search based on
            );

        //! Copy Constructor
        ActionSearcher
            (
            const ActionSearcher &other    //!< searcher to copy
            );

        //! Destructor
        ~ActionSearcher();

        //! Main function of searcher thread
        virtual void operator()();

    private:
        //! Disabled empty constructor
        ActionSearcher();

    private:
        std::string mSearchText; //!< text to match

        ObjectList mActions; //!< actions to search based on

        ObjectList mInput; //!< a list of objects to be used as input to the action

}; // class ActionSearcher

} // namespace Flurry

#endif // FL_ActionSearcher
