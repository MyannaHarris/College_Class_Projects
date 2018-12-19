/**
 * @file List.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 2-23-14
 *
 * A linked list using nodes.
 */

#include <iostream>
using namespace std;

#include "List.h"

List::List()
{
 size = 0;
 head = NULL;
 tail = NULL;
}

//copy constructor
List::List(List* listIn)
{
 size = listIn->size;
 if (listIn->head == NULL)
 {
  //to copy empty list
  head = NULL;
  tail = NULL;
 }  
 else
    {
     //copy each Node
     head = new Node;
     head->item = listIn->head->item;
     Node* newPtr = head;
     for(Node* origPtr = listIn->head->next; origPtr != NULL; origPtr = origPtr->next)
     {
      newPtr->next = new Node;
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
 //use delT to empty list
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
 //inserts newItem at pos
 if (pos < 1 || pos > (size + 1))
    return false;

 Node* tempPtr = new Node();
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
  Node* passPtr = ptrTo(pos - 1);
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
 //sets value at item's address to value at pos
 if (pos < 1 || pos > size)
    return false;

 Node* tempPtr = ptrTo(pos);
 item = tempPtr -> item;

 tempPtr = NULL;
 return true;
}

bool List::del(int pos)
{
 //deletes Node at pos
 if (pos < 1 || pos > size)
    return false;

 if (pos == 1)
 {
  Node* tempPtr = head;
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
  Node* tempPtr = ptrTo(pos - 1);
  Node* nextPtr = tempPtr -> next;

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
 //cout each item
 Node* tempPtr = head;
 while (tempPtr != NULL)
 {
  cout << tempPtr -> item << endl;
  tempPtr = tempPtr -> next;
 }

 tempPtr = NULL;
}

bool List::setT(itemType newItem)
{
 //inserts a new Node at the end of the list
 Node* newPtr = new Node();
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
 //gets the value stored at the end of the list
 if (isEmpty())
    return false;

 item = tail -> item;
 return true;
}

bool List::delT()
{
 //deletes the Node at the end of the list
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

 Node* tempPtr = ptrTo(size - 1);
 tempPtr -> next = NULL;
 delete tail;
 tail = tempPtr;
 size--;
 return true;
}

//ascending
void List::sortIt()
{
 Node* start = head;

 while (start -> next != NULL)
 {
  Node* tempPtr = start -> next;
  Node* smallest = start;

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

Node* List::ptrTo(int pos)
{
 //iterates through linked list
 Node* tempPtr = head;
 for (int i = 1; i < pos; i++)
    tempPtr = tempPtr -> next;
 return tempPtr;
}

bool List::set(itemType newItem)
{
 //inserts Node at head of list
 if (isEmpty())
 {
  head = new Node();
  head -> item = newItem;
  head -> next = NULL;

  tail = head;
  return true;
 }
 
 Node* tempPtr = new Node();
 tempPtr -> item = newItem;
 tempPtr -> next = head;
 head = tempPtr;
 
 tempPtr = NULL;
 return true;
}
