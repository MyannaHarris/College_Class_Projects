/*
Class: cpsc122 - 01
Assignment: assignment 6
Team Leader: Cameron Anderson canderson10@ada.gonzaga.edu
Developer: Myanna Harris mharris5@ada.gonzaga.edu
QA: Jasmine Jans jjans@ada.gonzaga.edu
*/

#include <iostream>
using namespace std;

#include "asgn6.h"

List::List()
{
 size = 0;
 head = NULL;
 tail = NULL;
}

List::List(List* listIn)
{
 size = listIn->size;
 if (listIn->head == NULL)
 {
  head = NULL;
  tail = NULL;
 }  
 else
    {
     head = new node;
     head->item = listIn->head->item;
     node* newPtr = head;
     for(node* origPtr = listIn->head->next; origPtr != NULL; origPtr = origPtr->next)
     {
      newPtr->next = new node;
      newPtr = newPtr->next;
      newPtr->item = origPtr->item;
     }
     newPtr->next = NULL;
     tail = newPtr;
     newPtr = NULL;
    }
}

List::~List()
{
 while (size > 0)
    delT();
}

bool List::isEmpty()
{
 if (size > 0)
    return false;
 else
    return true;
}

int List::getLength()
{
 return size;
}

bool List::set(int pos, itemType newItem)
{
 if (pos < 1 || pos > (size + 1))
    return false;

 node* tempPtr = new node();
 tempPtr -> item = newItem;

 if (pos == 1)
 {
  tempPtr -> next = head;
  head = tempPtr;
  
  if (size < 1)
     tail = head;
 }
 else
 {
  node* passPtr = ptrTo(pos);
  tempPtr -> next = passPtr -> next;
  passPtr -> next = tempPtr;

  if (pos == (size + 1))
     tail = tempPtr;

  passPtr = NULL;
 }

 size++;
 tempPtr = NULL;
 return true;
}

bool List::get(int pos, itemType& item)
{
 if (pos < 1 || pos > size)
    return false;

 node* tempPtr = ptrTo(pos + 1);
 item = tempPtr -> item;

 tempPtr = NULL;
 return true;
}

bool List::del(int pos)
{
 if (pos < 1 || pos > size)
    return false;

 if (pos == 1)
 {
  node* tempPtr = head;
  head = tempPtr -> next;

  if (size == 1)
     tail = head;

  size--;
  delete tempPtr;
  tempPtr = NULL;
  return true;
 }
 else
 {
  node* tempPtr = ptrTo(pos);
  node* nextPtr = tempPtr -> next;

  if (pos == (size + 1))
     tail = tempPtr;

  tempPtr -> next = nextPtr -> next;

  size--;
  delete nextPtr;
  tempPtr = NULL;
  nextPtr = NULL;
  return true;
 }
}

void List::display()
{
 node* tempPtr = head;
 while (tempPtr != NULL)
 {
  cout << tempPtr -> item << endl;
  tempPtr = tempPtr -> next;
 }

 tempPtr = NULL;
}

bool List::setT(itemType newItem)
{
 node* newPtr = new node();
 if (isEmpty() || newPtr == NULL)
    return false;

 newPtr -> item = newItem;
 newPtr -> next = NULL;
 tail -> next = newPtr;
 tail = newPtr;

 newPtr = NULL;
 
 size++;
 return true;
}

bool List::getT(itemType& item)
{
 if (isEmpty())
    return false;

 item = tail -> item;
 return true;
}

bool List::delT()
{
 if (isEmpty())
    return false;

 if (size == 1)
 {
  head = NULL;
  delete tail;
  tail = NULL;
  size--;
  return true;
 }

 node* tempPtr = ptrTo(size);
 tempPtr -> next = NULL;
 delete tail;
 tail = tempPtr;
 size--;
 return true;
}

void List::sortIt()
{
 node* start = head;

 while (start -> next != NULL)
 {
  node* tempPtr = start -> next;
  node* smallest = start;

  while (tempPtr != NULL)
  {
   if (tempPtr -> item < smallest -> item)
      smallest = tempPtr;

   tempPtr = tempPtr -> next;
  }
  
  itemType temp = start -> item;
  start -> item = smallest -> item;
  smallest -> item = temp;

  tempPtr = NULL;
  smallest = NULL;
  start = start -> next;
 }

 start = NULL;
}

node* List::ptrTo(int pos)
{
 node* tempPtr = head;
 for (int i = 1; i < (pos - 1); i++)
    tempPtr = tempPtr -> next;
 return tempPtr;
}

bool List::set(itemType newItem)
{
 if (isEmpty())
 {
  head = new node();
  head -> item = newItem;
  head -> next = NULL;

  tail = head;
  return true;
 }
 
 node* tempPtr = new node();
 tempPtr -> item = newItem;
 tempPtr -> next = head;
 head = tempPtr;
 
 tempPtr = NULL;
 return true;
}
