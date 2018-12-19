/**
 * @file PQueue.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 1-21-14
 *
 * A priority queue using an array-based queue.
 */

#include <iostream>
using namespace std;

#include "PQueue.h"

PriorityQueue::PriorityQueue()
{
 front = 0;
 back = 0;
 count = 0;
}

void PriorityQueue::enqueue(QueueItemType& newItem)
{
 //place first item at front
 if(isEmpty())
    items[front] = newItem;
 else
 {
  //search for correct spot in queue
  int pointer = front;
  bool finishSearch = false;
  while (pointer <= back && !finishSearch)
  {
   //if correct spot is found move items down and insert newItem
   if (newItem > items[pointer])
   {
    int newItemSpot = pointer;
    pointer = back;

    while (pointer >= newItemSpot)
    {
     items[pointer + 1] = items[pointer];
     pointer--;
    }

    items[newItemSpot] = newItem;
    finishSearch = true;
   }
   else
      pointer++;
  }

  if (pointer > back)
      items[back + 1] = newItem;

  //incriment back pointer if more than one item is in the queue
  back++;
 }

 //incriment count
 count++;
}
