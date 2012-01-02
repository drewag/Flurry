#include "FL_NamedConcreteSelector.h"

#include "FL_Object.h"

namespace Flurry
{

NamedConcreteSelector::NamedConcreteSelector()
    : ConcreteSelector( "named" )
{
}

/* virtual */ void NamedConcreteSelector::destroy()
{
    delete this;
}

/* virtual */ bool NamedConcreteSelector::doesSupportCategory
    (
    const Category &cat
    ) const
{
    return true;
}

/* virtual */ bool NamedConcreteSelector::doesObjectMatch
    (
    std::string text,
    const Object &obj
    ) const
{
    std::string title = obj.getTitle();

    std::string::const_iterator textItr;
    textItr = text.begin();

    std::string::const_iterator titleItr;
    titleItr = title.begin();

    while( textItr != text.end()
           && titleItr != title.end() )
    {
        if( tolower( *textItr ) == tolower( *titleItr ) )
        {
            textItr++;
            titleItr++;
        }
        else
        {
            titleItr++;
        }
    }

    return textItr == text.end();
}

} // namespace Flurry
