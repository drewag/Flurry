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
            ObjectList results
            );

        //! Search for an object matching text
        //!
        //! Report results through reportResultsGenerated
        void findInCategoriesWithSelector
            (
            std::string text,             //!< Text to search with
            const Selector &sel,          //!< Selector to filter objects with
            const ObjectList &categories  //!< Categories to search within
            );

        //! Search for selectors that support
        //! the given category
        //!
        //! Report results through reportResultsGenerated
        void findInSelectorsWithCategories
            (
            std::string text,               //!< Text to match agains the name of the selector
            const ObjectList &categories,   //!< Categories to make sure is supported
            const ObjectList &selectors     //!< Selectors to search within
            );

    private:
        ModuleManager* mModuleManager; //!< Object to manage all of the objects
                                       //!< loaded in modules

        DialogResultsGeneratedEventEmitter mResultsGeneratedEmitter; //!< Event emitter for when results are generated

        DialogActionBegunEventEmitter mActionBegunEmitter; //!< Event emitter for when an action begins processing

        DialogActionFinishedEventEmitter mActionFinishedEmitter; //!< Event emitter for when an action finished processing

        std::vector<boost::thread*> mSearcherThreads; //!< Background thread for searches

        ObjectList* mSelectedObjects; //!< List of the currently selected objects that will serve
                                      //!  as input to the next search

        SynchronizedQueue<SharedEvent> mEventQueue; //!< Queue of events to be processed

}; // class Dialog

} // namespace Flurry

#endif // FL_Dialog
