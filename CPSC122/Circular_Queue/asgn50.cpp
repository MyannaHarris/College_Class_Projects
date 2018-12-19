/*
Class: cpsc122 - 01
Assignment: Final Take-Home Question 1
Team Leader: Myanna Harris mharris5@ada.gonzaga.edu
Developer: Myanna Harris mharris5@ada.gonzaga.edu
QA: Myanna Harris mharris5@ada.gonzaga.edu
*/

#include<iostream>
using namespace std;

#include"ex50.h"

itemType Queue::dequeue()
{
 itemType temp = stuff[front];
 front = (front + 1) % size;
 return temp;
}

Queue::Queue(int sizeIn)
{
 size = sizeIn;
 back = size - 1; 
 front = 0;
 numItems = 0;
 stuff = new itemType[size];
}

Queue::~Queue()
{
 delete stuff;
 stuff = NULL;
}

bool Queue::isEmpty()
{
 if (numItems == 0)
    return true;
 return false;
}

void Queue::enqueue(itemType item)
{
   back = (back + 1) % size;
   stuff[back] = item;
   numItems++;
}

void Queue::display()
{
 int dispInd = front;
 int numOut = 0;
 while (numOut < numItems)
 {
   cout << stuff[dispInd] << endl;
   dispInd = (dispInd + 1) % size;
   numOut++;
 }
}
