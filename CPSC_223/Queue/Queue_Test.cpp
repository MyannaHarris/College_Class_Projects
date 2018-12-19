/**
 * @file Queue_Test.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 1-21-14
 *
 * Runs a priority queue where greater integers have priority.
 */

#include <iostream>
using namespace std;

#include"PQueue.h"

int main()
{
 PriorityQueue* pQueue = new PriorityQueue();

 for (int i = 0; i <= 10; i++)
 {
  pQueue -> enqueue(i);
 }

 while(!pQueue -> isEmpty())
 {
  cout << pQueue -> getFront() << endl;
  pQueue -> dequeue();
 }

 return 0;
}
