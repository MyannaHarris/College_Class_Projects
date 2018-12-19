/**
 * @file QueueA.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 1-23-14
 *
 * A queue using an array.
 */

#include <iostream>
using namespace std;

#include "QueueA.h"

Queue::Queue()
{
 front = 0;
 back = 0;
 count = 0;
}

bool Queue::isEmpty() const
{
 if (count == 0)
    return true;
 return false;
}

void Queue::enqueue(const QueueItemType& newItem) throw(QueueException)
{
 if (count == MAX_QUEUE)
 {
    throw QueueException("enqueue() called on full queue");
 }
 else
 {
  //place first item at front
  if (isEmpty())
     items[front] = newItem;
  else
  {
   //place items at back
   items[back + 1] = newItem;

   //incriment back pointer if more than one item is in the queue
   back++;
  }

  //incriment count
  count++;
 }
}

void Queue::dequeue(QueueItemType& queueFront) throw(QueueException)
{
 if (isEmpty())
    throw QueueException("dequeue() called on empty queue");
 else
 {
  //put the front item in the passed variable
  queueFront = items[front];

  //move the items left in the array forward
  int pointer = front;
  while (pointer < back)
  {
   items[pointer] = items[pointer + 1];
   pointer++;
  }

  //decrease back pointer
  if (back != 0)
     back--;

  //decrease count
  count--;
 }
}

void Queue::getFront(QueueItemType& queueFront) const throw(QueueException)
{
 if (isEmpty())
    throw QueueException("getFront() called on empty queue");
 else
 {
  //put the front item in the passed variable
  queueFront = items[front];
 }
}
