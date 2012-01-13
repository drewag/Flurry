#include "FL_Dialog.h"

// Data Classes
#include "FL_Object.h"
#include "FL_Category.h"
#include "FL_Selector.h"
#include "FL_Action.h"
#include "FL_ObjectList.h"

// Modules
#include "FL_ModuleManager.h"
#include "FL_CoreModule.h"

// Searcher
#include "FL_Searcher.h"
#include "FL_MultiSearcher.h"
#include "FL_ObjectSearcher.h"
#include "FL_SelectorSearcher.h"

// Events
#include "FL_DialogResultsGeneratedEvent.h"

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <iostream>

namespace Flurry
{

Dialog::Dialog
    (
    Flurry::ModuleManager &moduleManager
    )
    : mModuleManager( &moduleManager )
    , mResultsGeneratedEmitter( this )
    , mActionBegunEmitter( this )
    , mActionFinishedEmitter( this )
    , mInputObjects( NULL )
    , mPreviouslySelected( NULL )
    , mActiveActions( NULL )
{
}

Dialog::~Dialog()
{
    delete mPreviouslySelected;
    delete mActiveActions;
    delete mInputObjects;
    for( unsigned int i = 0; i < mSearcherThreads.size(); i++ )
    {
        delete mSearcherThreads[i];
    }
}

void Dialog::start()
{
    while( true )
    {
        SharedEvent event = mEventQueue.pop();
        event->emmit();
    }
}

void Dialog::textChanged
    (
    std::string newText
    )
{
    MultiSearcher* searcher = new MultiSearcher();
    searcher->connectSearchDone( boost::bind( &Dialog::reportResultsGenerated, this, _1, _2 ) );

    bool selectedObjectsAreCategories = NULL != mPreviouslySelected
        && mPreviouslySelected->allObjectsAreOfCategory( Category::categoryCategory() );

    // Selectors appear in search if and only if all active objects are Categories
    if( NULL != mPreviouslySelected && selectedObjectsAreCategories )
    {
        searcher->addSearcher( new SelectorSearcher
            (
            newText,
            *mPreviouslySelected,
            mModuleManager->getAllSelectors()
            ) );
    }

    if( NULL == mActiveActions )
    {
        // We are preparing input for a future action
        // Actions appear in search if and only if no active Actions are selected
        // TODO: Add action to search

        if( !selectedObjectsAreCategories )
        {
            // Objects appear in search if and only if there is no active Category
            // Categories appear in search if and only if there is no active Category
            searcher->addSearcher( new ObjectSearcher
                (
                newText,
                CoreModule::namedSelector(),
                mModuleManager->getAllCategories()
                ) );
        }
    }
    else
    {
        // We have an action and we are just satisfying all of the required input
        // TODO: Add searches to satisfy requirments
    }

    boost::thread thread( boost::ref( *searcher ) );
}

void Dialog::resultSelected
    (
    const Object &res
    )
{
    if( NULL == mPreviouslySelected )
    {
        mPreviouslySelected = new ObjectList();
    }
    else
    {
        mPreviouslySelected->clear();
    }
    mPreviouslySelected->add( res );

    if( res.isOfCategory( Action::actionCategory() ) )
    {
        if( NULL == mActiveActions )
        {
            mActiveActions = new ObjectList();
        }
        else
        {
            mActiveActions->clear();
        }
        mActiveActions->add( res );
    }
    else
    {
        if( NULL == mInputObjects )
        {
            mInputObjects = new ObjectList();
        }
        mInputObjects->add( res );
    }
}

void Dialog::batchResultSelected
    (
    const Object &res
    )
{
}

boost::signals2::connection Dialog::connectToResultsGenerated
    (
    DialogResultsGeneratedEventEmitter::Signal::slot_type slot
    )
{
    return mResultsGeneratedEmitter.connect( slot );
}

boost::signals2::connection Dialog::connectToActionBegun
    (
    DialogActionBegunEventEmitter::Signal::slot_type slot
    )
{
    return mActionBegunEmitter.connect( slot );
}

boost::signals2::connection Dialog::connectToActionFinished
    (
    DialogActionFinishedEventEmitter::Signal::slot_type slot
    )
{
    return mActionFinishedEmitter.connect( slot );
}

void Dialog::reportResultsGenerated
    (
    const Searcher &searcher,
    const ObjectList results
    )
{
    delete &searcher;
    std::cout << "Generated" << std::endl;
    SharedEvent event( mResultsGeneratedEmitter.newEvent( results ) );
    mEventQueue.push( event );
}

} // namespace Flurry
