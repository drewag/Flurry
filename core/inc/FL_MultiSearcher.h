#ifndef FL_MultiSearcher
#define FL_MultiSearcher

#include "FL_Searcher.h"

#include "FL_ObjectList.h"

#include <boost/signal.hpp>
#include <list>

namespace Flurry
{

class MultiSearcher : public Searcher
{
    public:
        //! Constructor
        MultiSearcher();

        //! Copy Constructor
        MultiSearcher
            (
            const MultiSearcher &other    //!< searcher to copy
            );

        //! Destructor
        ~MultiSearcher();

        //! Add a searcher to be done alongside the other searches already added
        //!
        //! Note: This searcher will take ownership of the passed in searcher. When
        //! this searcher is deleted it will also delete the passed in searcher.
        void addSearcher
            (
            Searcher* searcher
            );

        //! Main function of searcher thread
        virtual void operator()();

    private:
        //! Search done
        void subSearchIsDone
            (
            const Searcher &searcher,   //!< Searcher that has finished
            const ObjectList results    //!< Results found by searcher
            );

    private:
        typedef boost::shared_ptr<Searcher> SharedSearcher;

        std::list<SharedSearcher> mSubSearchers; //!< A list of searches to perform together

        unsigned int mSearchesLeftToComplete; //!< The number of searches that still have to
                                              //!  be completed

        ObjectList mResults; //!< Results gathered from sub searches

}; // class MultiSearcher

} // namespace Flurry

#endif // FL_MultiSearcher
