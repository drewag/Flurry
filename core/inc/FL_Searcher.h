#ifndef FL_Searcher
#define FL_Searcher

#include <boost/signals2.hpp>

namespace Flurry
{

class ObjectList;

class Searcher
{
    public:
        //! Signal for when the search finishes
        typedef boost::signals2::signal<void
            (
            const Searcher &searcher,   //!< Searcher that has finished
            const ObjectList results    //!< Results found by searcher
            )> SigSearchDone;

    public:
        //! Constructor
        Searcher();
        
        //! Copy Constructor
        Searcher
            (
            const Searcher &other   //!< searcher to copy
            );

        //! Register for callback to be called when the search is done
        boost::signals2::connection connectSearchDone
            (
            SigSearchDone::slot_type searchDoneSlot //!< slot to callback when the search is done
            );

        //! Destructor
        ~Searcher();

        //! Main function of searcher thread
        virtual void operator()() = 0;

    protected:
        //! Function for subclasses to report that they have finished searching
        void reportSearchDone
            (
            const ObjectList results
            );

    private:
        SigSearchDone* mSearchDoneSignal; //!< Signal for when search is complete

}; // class Searcher

} // namespace Flurry

#endif // FL_Searcher
