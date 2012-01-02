#include "FL_Dialog.h"

#include "FL_ObjectList.h"
#include "FL_ModuleManager.h"
#include "FL_Object.h"
#include "FL_Category.h"
#include "FL_Selector.h"
#include "FL_CoreModule.h"
#include "FL_Searcher.h"
#include "FL_ObjectSearcher.h"
#include "FL_SelectorSearcher.h"
#include "FL_ObjectList.h"
#include "FL_DialogResultsGeneratedEvent.h"

#include <boost/thread.hpp>
#include <boost/bind.hpp>

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
    , mSelectedObjects( NULL )
{
}

Dialog::~Dialog()
{
    delete mSelectedObjects;
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
    if( NULL == mSelectedObjects )
    {
        // On the first search look for an object in any category
        this->findInCategoriesWithSelector
            (
            newText,
            CoreModule::namedSelector(),
            mModuleManager->getAllCategories()
            );
    }
    else if( mSelectedObjects->allObjectsAreOfCategory( Category::categoryCategory() ) )
    {
        // If everything is a category then we can find an Action or Selector
        this->findInSelectorsWithCategories
            (
            newText,
            *mSelectedObjects,
            mModuleManager->getAllSelectors()
            ); 
    }
}

void Dialog::resultSelected
    (
    const Object &res
    )
{
    if( NULL == mSelectedObjects )
    {
        mSelectedObjects = new ObjectList();
    }
    else
    {
        mSelectedObjects->clear();
    }
    mSelectedObjects->add( res );
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
    ObjectList results
    )
{
    SharedEvent event( mResultsGeneratedEmitter.newEvent( results ) );
    mEventQueue.push( event );
}

void Dialog::findInCategoriesWithSelector
    (
    std::string text,
    const Selector &sel,
    const ObjectList &categories
    )
{
    ObjectSearcher searcher
        (
        boost::bind( &Dialog::reportResultsGenerated, this, _1 ),
        text,
        sel,
        categories
        );
    boost::thread newThread( searcher );
}

void Dialog::findInSelectorsWithCategories
    (
    std::string text,
    const ObjectList &categories,
    const ObjectList &selectors
    )
{
    SelectorSearcher searcher
        (
        boost::bind( &Dialog::reportResultsGenerated, this, _1 ),
        text,
        categories,
        selectors
        );
    boost::thread newThread( searcher );
}

} // namespace Flurry
