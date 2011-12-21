#ifndef FL_ObjectList
#define FL_ObjectList

#include <set>

namespace Flurry
{

class Object;

class ObjectList
{
    public:
        typedef std::set<Object>::iterator iterator;
        typedef std::set<Object>::const_iterator const_iterator;

    public:
        //! Constructor
        ObjectList();

        //! Copy Constructor
        ObjectList
            (
            const ObjectList &other //!< List to copy
            );

        //! Destructor
        ~ObjectList();

        //! Add Object to end list
        void add
            (
            const Object &obj   //!< Object to add
            );

        //! Append a list onto this list
        void add
            (
            const ObjectList &other //!< List to append onto this one 
            );

        //! Remove Object to end list
        void remove
            (
            const Object &obj   //!< Object to remove
            );

        //! Remove a list of objects
        void remove
            (
            const ObjectList &list //!< list of objects to remove
            );

        //! @returns the number of Objects in list
        unsigned int size() const;

        //! Delete all elements
        void clear();

        //! @returns an iterator pointing at the beginning of the list
        iterator begin();

        //! @returns an iterator pointing at the end of the list
        iterator end();

        //! @returns an iterator pointing at the beginning of the list
        const_iterator begin() const;

        //! @returns an iterator pointing at the end of the list
        const_iterator end() const;

    private:
        std::set<Object>* mObjects;   //!< internal list of objects

};

} // namespace Flurry

#endif

