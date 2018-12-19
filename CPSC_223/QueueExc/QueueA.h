/**
 * @file QueueA.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 1-23-14
 *
 * Queue that uses an array.
 */

#include "QueueException.h"
#ifndef QUEUEA_H
#define QUEUEA_H
//const int MAX_QUEUE = maximum-size-of-queue;
//typedef desired-type-of-queue-item QueueItemType;
const int MAX_QUEUE = 15;
typedef int QueueItemType;

/** @class Queue
 * ADT queue - Array-based implementation. */
class Queue
{
public:
// constructors and destructor:
   /** Default constructor. */
   Queue();
   // copy constructor and destructor are
   // supplied by the compiler

// Queue operations:

   /** Determines whether the queue is empty.
     * @pre None
     * @post None
     * @return True if this queue is empty; 
     *         otherwise returns false. */
   bool isEmpty() const;

   /** Inserts an item at the back of this queue.
     * @pre newItem is the item to be inserted.
     * @post If insertion is successful, newItem 
     *       is at the back of this queue.
     * @param newItem is the new item to be inserted. */
   virtual void enqueue(const QueueItemType& newItem) throw(QueueException);

   /** Dequeues the front of this queue.
     * @pre None.
     * @post If this queue is not empty, the item that
     *       was added to this queue earliest is deleted.
     * @param queueFront is the value of the item at the
     *        front of the queue. */
   //void dequeue();
   void dequeue(QueueItemType& queueFront) throw(QueueException);

   /** Retrieves the front of this queue.
     * @pre None.
     * @post If this queue is not empty, the item that was
     *       added to this queue earliest is returned.
     * @param queueFront is the value of the item at the
     *        front of the queue.  */
   void getFront(QueueItemType& queueFront) const throw(QueueException);

protected:
   /** the array that holds the items */
   QueueItemType items[MAX_QUEUE];

   /** the index of the front item */
   int front;

   /** the index of the back item */
   int back;

   /** the number of items in the queue */
   int count;
}; // end Queue
#endif
// End of header file.
