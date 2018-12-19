/**
 * @file PQueue.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 1-23-14
 *
 * Priority queue that uses a queue.
 */

#include "QueueException.h"
#include "QueueA.h"

#ifndef PRIORITYQUEUEA_H
#define PRIORITYQUEUEA_H

//const int MAX_QUEUE = maximum-size-of-queue;
//typedef desired-type-of-queue-item QueueItemType;
//const int MAX_QUEUE = 15;
//typedef int QueueItemType;

/** @class Queue
 * ADT queue - Array-based implementation. */
class PriorityQueue: public Queue
{
public:
// constructors and destructor:
   /** Default constructor. */
   PriorityQueue();

   /** Inserts an item in the priority queue 
     *      in descending order so largest is in front.
     * @pre newItem is the item to be inserted.
     * @post If insertion is successful, newItem 
     *       is in the queue in order.
     * @param newItem is the new item to be inserted. */
   virtual void enqueue(QueueItemType& newItem) throw(QueueException);


}; // end Queue
#endif
// End of header file.
