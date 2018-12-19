/**
 * @file Queue_Test.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 1-23-14
 *
 * Runs a priority queue where greater integers have priority.
 */

#include <iostream>
using namespace std;

#include"PQueue.h"

int main()
{
 PriorityQueue* pQueue = new PriorityQueue();

 try
 {
  //Test ordering for enqueue and dequeue
  cout << "" << endl;
  cout << "Test order: " << endl;
  cout << "" << endl;

  for (int i = 0; i <= 10; i++)
  {
   pQueue -> enqueue(i);
  }

  while(!pQueue -> isEmpty())
  {
   QueueItemType frontItem;
   pQueue -> getFront(frontItem);
   cout << frontItem << endl;
   pQueue -> dequeue(frontItem);
   cout << "dequeued : " << frontItem << endl;
  }
 }
 catch (QueueException e)
 {
  cout << e.what() << endl;
 }

 try
 {
  //test error for dequeueing empty queue
  cout << "" << endl;
  cout << "Test dequeue error: " << endl;
  cout << "" << endl;

  int i = 1;
  pQueue -> enqueue(i);

  QueueItemType frontItem;
  pQueue -> dequeue(frontItem);
  cout << "dequeued : " << frontItem << endl;
  pQueue -> dequeue(frontItem);
  cout << "dequeued : " << frontItem << endl;
 }
 catch (QueueException e)
 {
  cout << e.what() << endl;
 }

 try
 {
  //test error for getting front of empty queue
  cout << "" << endl;
  cout << "Test getFront() error: " << endl;
  cout << "" << endl;

  int i = 1;
  pQueue -> enqueue(i);

  QueueItemType frontItem;
  pQueue -> getFront(frontItem);
  cout << "front : " << frontItem << endl;
  pQueue -> dequeue(frontItem);
  cout << "dequeued : " << frontItem << endl;
  pQueue -> getFront(frontItem);
  cout << frontItem << endl;
 }
 catch (QueueException e)
 {
  cout << e.what() << endl;
 }

 try
 {
  //test error for enqueueing to full queue
  cout << "" << endl;
  cout << "Test enqueue error: " << endl;
  cout << "" << endl;

  for (int i = 0; i <= 15; i++)
  {
   pQueue -> enqueue(i);
  }
 }
 catch (QueueException e)
 {
  cout << e.what() << endl;
 }

 return 0;
}
