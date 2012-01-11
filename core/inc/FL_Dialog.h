#ifndef FL_Dialog
#define FL_Dialog

#include "FL_DialogEvent.h"
#include "FL_SynchronizedQueue.h"
#include "FL_DialogResultsGeneratedEventEmitter.h"
#include "FL_DialogActionBegunEventEmitter.h"
#include "FL_DialogActionFinishedEventEmitter.h"

#include <string>
#include <vector>

#include <boost/thread.hpp>
#include <boost/signals2.hpp>
#include <boost/shared_ptr.hpp>

namespace Flurry
{

class ModuleManager;
class ObjectList;
class Object; class Action;
class Selector;
class Searcher;
class Action;
class Category;
class Dialog;
class DialogEvent;

template<typename T>
class SynchronizedQueue;

class Dialog
{
    private:
        typedef boost::shared_ptr<DialogEvent> SharedEvent;

    public:
        //! Constructor
        Dialog
            (
            ModuleManager &moduleManager
            );

        //! Destructor
        ~Dialog();

        //! Start the dialog
        void start();

        //---------------------------------------------------------------------------------------
        // Event Generation
        //---------------------------------------------------------------------------------------

        //! Report that the input text has changed
        void textChanged
            (
            std::string newText //!< what the text changed to
            );

        //! Report that the user selected a result
        void resultSelected
            (
            const Object &res //!< result that was selected
            );

        //! Report that the user selected a result and want to search for another object of the
        //! same type.
        void batchResultSelected
            (
            const Object &res //!< result that was selected
            );

        //---------------------------------------------------------------------------------------
        // Event Registrations
        //---------------------------------------------------------------------------------------
        
        //! Connect to results generated event
        boost::signals2::connection connectToResultsGenerated
            (
            DialogResultsGeneratedEventEmitter::Signal::slot_type slot //!< callback to be called when event is raised
            );

        //! Connect to action started event
        boost::signals2::connection connectToActionBegun
            (
            DialogActionBegunEventEmitter::Signal::slot_type slot //!< callback to be called when event is raised
            );

        //! Connect to action finished event
        boost::signals2::connection connectToActionFinished
            (
            DialogActionFinishedEventEmitter::Signal::slot_type slot //!< callback to be called when event is raised
            );

    private:
        //! Signal that results have been generated
        void reportResultsGenerated
            (
            const Searcher &searcher,   //!< Searcher that has finished
            const ObjectList results    //!< Results found by searcher
            );

    private:
        ModuleManager* mModuleManager; //!< Object to manage all of the objects
                                       //!< loaded in modules

        DialogResultsGeneratedEventEmitter mResultsGeneratedEmitter; //!< Event emitter for when results are generated

        DialogActionBegunEventEmitter mActionBegunEmitter; //!< Event emitter for when an action begins processing

        DialogActionFinishedEventEmitter mActionFinishedEmitter; //!< Event emitter for when an action finished processing

        std::vector<boost::thread*> mSearcherThreads; //!< Background thread for searches

        ObjectList* mInputObjects; //!< List of the currently selected objects that will serve as input to the next search

        ObjectList* mPreviouslySelected; //!< The last objects to be selected that may need further clarification before becoming
                                         //!  input to the action. e.g. A category can have a selector applied to create multiple inputs

        ObjectList* mActiveActions; //!< Actions that is currently selected. All objects in mInputObjects will serve as input

        SynchronizedQueue<SharedEvent> mEventQueue; //!< Queue of events to be processed

}; // class Dialog

} // namespace Flurry

#endif // FL_Dialog
