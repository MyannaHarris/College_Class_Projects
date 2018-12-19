/**
 * @file QueueA.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 2-4-14
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

   /** Returns queue's size count
     * @pre None
     * @post None
     * @return queue's count */
   int getCount() const;

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

   /** Overloaded operator as member. Compares queue size.
     * @pre None.
     * @post None.
     * @return If queue param is greater than this queue, return true;
     *         otherwise return false.
     * @param queue is the queue whose size will be compared to */
   bool operator <(const Queue& queue);

   /** Overloaded operator as friend. Outputs queue items.
     * @pre None.
     * @post The items in queue are displayed.
     * @param os is an object of ostream (the output stream).
     *        queue is the queue to be displayed.  */
   friend ostream& operator <<(ostream& os, const Queue& queue);

   /** friend function. Displays queue.
     * @pre None.
     * @post The items in queue are displayed.
     * @param queue is the queue to be displayed. */
   friend void display(const Queue& queue);

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

/** Overloaded operator as non-member. Compares queue size.
  * @pre None.
  * @post None.
  * @return If queue1 is less than queue2, return true;
  *         otherwise return false.
  * @param queue1 is the queue that is asked about being larger
  *        queue2 is the queue that is asked about being smaller*/
bool operator >(const Queue& queue1, const Queue& queue2);

#endif
// End of header file.
