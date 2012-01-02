#ifndef FL_DialogResultsGeneratedEvent
#define FL_DialogResultsGeneratedEvent

#include "FL_DialogEvent.h"
#include "FL_ObjectList.h"

namespace Flurry
{

class DialogResultsGeneratedEvent : public DialogEvent
{
    public:
        //! Constructor
        DialogResultsGeneratedEvent
            (
            DialogEventEmitter* emitter, //!< Emitter that calls callbacks
            const ObjectList &results //!< results generated
            );

        //! Create this element as a copy of other
        virtual DialogEvent* clone() const;
        
        //! Destructor
        virtual ~DialogResultsGeneratedEvent();

    private:
        //! Copy Constructor
        DialogResultsGeneratedEvent
            (
            const DialogResultsGeneratedEvent &other
            );

    public:
        ObjectList results; //!< generated results

}; // class DialogEvent

} // namespace Flurry

#endif // FL_DialogResultGeneratedEvent
