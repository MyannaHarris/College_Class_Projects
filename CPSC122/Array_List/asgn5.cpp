/*
Class: cpsc122 - 01
Assignment: assignment 4
Team Leader: Jasmine Jans jjans@ada.gonzaga.edu
Developer: Cameron Anderson canderson10@ada.gonzaga.edu
QA: Myanna Harris mharris5@ada.gonzaga.edu
*/

#include <iostream>
using namespace std;

#include "asgn5.h"

ListA::ListA(int sizeIn)
{
 size = sizeIn;
 tail = 0;
 stuff = new itemType[size];
}

ListA::~ListA()
{
 delete [] stuff;
 stuff = NULL;
}

bool ListA::isEmpty()
{
 if (tail == 0)
    return true;
 else
    return false;
}

bool ListA::isFull()
{
 if (tail == size)
    return true;
 else
    return false;
}

bool ListA::setT(itemType value)
{
 if (!isFull())
 {
  stuff[tail] = value;
  tail++;
  return true;
 }
 else
  return false;
}

bool ListA::getT(itemType& value)
{
 if (!isEmpty())
 {
  value = stuff[tail - 1];
  return true;
 }
 else
  return false;
}

void ListA::display()
{
 for (int i = 0; i < tail; i++)
   cout << stuff[i] << endl;
}

int ListA::getTail()
{
 return tail;
}

int ListA::getSize()
{
 return size;
}

bool ListA::delT()
{
 if (!isEmpty())
 {
  tail--;
  return true;
 }
 else
  return false;
}

bool ListA::setH(itemType value)
{
 if (!isFull())
 {
  for (int i = tail; i > 0; i--)
    stuff[i] = stuff[i-1];
  tail++;
  stuff[0] = value;
  return true;
 }
 else
  return false;
}

bool ListA::getH(itemType& value)
{
 if (!isEmpty())
 {
  value = stuff[0];
  return true;
 }
 else
  return false;
}

bool ListA::getAny(itemType& item, int pos)
{
 if (!isEmpty())
 {
  item = stuff[pos];
  return true;
 }
 else
  return false;
}

bool ListA::delH()
{
 if (!isEmpty())
 {
  for (int i = 0; i < (tail - 1); i++)
    stuff[i] = stuff[i+1];
  tail--;
  return true;
 }
 else
  return false;
}

void ListA::sortIt()
{
 for (int curr = 0; curr < (tail - 1); curr++)
 {
  int smallest = curr;

  for (int i = curr; i < tail; i++)
  {
   if (stuff[i] < stuff[smallest])
      smallest = i;
  }
  
  int temp = stuff[curr];
  stuff[curr] = stuff[smallest];
  stuff[smallest] = temp;
 }
}

ListA::ListA(ListA* listIn)
{
 size = listIn -> getSize();
 tail = listIn -> getTail();
 stuff = new itemType[size];
 for (int i = 0; i < tail; i++)
 {
  itemType item;
  listIn -> getAny(item, i);
  stuff[i] = item;
 }
}
