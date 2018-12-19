/**
 * @file QueueA.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 1-21-14
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

bool Queue::isEmpty()
{
 if (count == 0)
    return true;
 return false;
}

void Queue::enqueue(QueueItemType& newItem)
{
 //place first item at front
 if(isEmpty())
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

void Queue::dequeue()
{
 if (!isEmpty())
 {
  //move the items left in the array forward
  int pointer = front;
  while (pointer < back)
  {
   items[pointer] = items[pointer + 1];
   pointer++;
  }

  //decrease back pointer
  back--;

  //decrease count
  count--;
 }
}

QueueItemType Queue::getFront()
{
 //get front item
 QueueItemType frontItem = items[front];
 return frontItem;
}
