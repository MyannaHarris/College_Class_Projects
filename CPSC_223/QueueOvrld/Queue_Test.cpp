/**
 * @file Queue_Test.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 2-4-14
 *
 * Runs a priority queue where greater integers have priority.
 */

#include <iostream>
using namespace std;

#include"PQueue.h"

int main()
{
 PriorityQueue* pQueue1 = new PriorityQueue();
 PriorityQueue* pQueue2 = new PriorityQueue();

 try
 {

  //Test overloading operators
  cout << "" << endl;
  cout << "Test overloaded operators: " << endl;
  cout << "" << endl;

  for (int i = 0; i <= 10; i++)
  {
   pQueue1 -> enqueue(i);
  }

  for (int i = 0; i <= 5; i++)
  {
   pQueue2 -> enqueue(i);
  }

  cout << "queue1" << endl;
  display(*pQueue1);

  cout << "queue2" << endl;
  display(*pQueue2);

  cout << "queue1 < queue2 ?" << endl;
  cout << (pQueue1 < pQueue2) << endl;

  cout << "queue1 > queue2 ?" << endl;
  cout << (pQueue1 > pQueue2) << endl;

  //Test ordering for enqueue and dequeue
  cout << "" << endl;
  cout << "Test order: " << endl;
  cout << "" << endl;

  while(!pQueue1 -> isEmpty())
  {
   QueueItemType frontItem;
   pQueue1 -> getFront(frontItem);
   cout << "Front:" << frontItem << endl;
   pQueue1 -> dequeue(frontItem);
   cout << "dequeued : " << frontItem << endl;
  }
 }
 catch (QueueException e)
 {
  cout << e.what() << endl;
 }

 PriorityQueue* pQueue = new PriorityQueue();

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
