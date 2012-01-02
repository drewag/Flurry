#ifndef FL_SynchronizedQueue
#define FL_SynchronizedQueue

#include "FL_DialogEvent.h"

#include <queue>
#include <boost/thread.hpp>

namespace Flurry
{

template<typename T>
class SynchronizedQueue
{
    public:
        //! Put new event onto queue
        void push
            (
            const T &event    //!< Event to add to queue
            );

        //! Take event off of queue
        //!
        //! This will block until there is something on the queue
        T pop();

    private:
        std::queue<T> mQueue;   //!< Queue to store elements

        boost::mutex mMutex;   //!< Lock for internal queue

        boost::condition_variable mCond;

}; // class SynchronizedQueue

template<typename T>
void SynchronizedQueue<T>::push
    (
    const T &element
    )
{
    boost::unique_lock<boost::mutex> lock( mMutex );

    mQueue.push( element );

    mCond.notify_one();
} // Lock is automatically released here

template<typename T>
T SynchronizedQueue<T>::pop()
{
    boost::unique_lock<boost::mutex> lock( mMutex );

    while( 0 == mQueue.size() ) mCond.wait( lock );

    T result = mQueue.front();
    mQueue.pop();

    return result;
} // Lock is automatically released here

} // namespace Flurry

#endif // FL_SynchronizedQueue
