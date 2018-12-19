/*
Class: cpsc122 - 01
Assignment: assignment 7
Team Leader: Myanna Harris mharris5@ada.gonzaga.edu
Developer: Jasmine Jans jjans@ada.gonzaga.edu
QA: Cameron Anderson canderson10@ada.gonzaga.edu
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "asgn7.h"

Stack::Stack()
{
 size = 0;
 top = NULL;
}

Stack::Stack(Stack* stackIn)
{
 size = stackIn -> size;
 if (stackIn->top == NULL)
 {
  top = NULL;
 }  
 else
 {
  top = new node;
  size = 1;
  top->item = stackIn->top->item;
  node* newPtr = top;
  for(node* origPtr = stackIn->top->next; origPtr != NULL; origPtr = origPtr->next)
  {
   newPtr->next = new node;
   newPtr = newPtr->next;
   newPtr->item = origPtr->item;
 
   size++;
  }
  newPtr->next = NULL;
  newPtr = NULL;
 }
}

Stack::~Stack()
{
 while (size > 0)
    itemType temp = pop();
}

bool Stack::isEmpty()
{
 if (size == 0)
    return true;
 else
    return false;
}

int Stack::getNum()
{
 return size;
}

void Stack::push(itemType item)
{
 node* tempNode = new node;
 tempNode -> item = item;
 tempNode -> next = top;
 top = tempNode;
 tempNode = NULL;

 size++;
}

itemType Stack::pop()
{
 if (!isEmpty())
 {
  node* tempNode = top;
  top = tempNode -> next;
  itemType temp = tempNode -> item;
  delete tempNode;
  tempNode = NULL;

  size--;
  return temp;
 }
 else
 {
  cout << "Error: Trying to pop from empty stack" << endl;
  exit(1);
 }
}

itemType Stack::peek()
{
 if (!isEmpty())
 {
  return top -> item;
 }
 else
 {
  cout << "Error: Trying to peek at empty stack" << endl;
  exit(1);
 }
}

void Stack::display()
{
 if (!isEmpty())
 {
  node* tempNode = top;
  while (tempNode != NULL)
  {
   cout << tempNode -> item << endl;
   tempNode = tempNode -> next;
  }
  tempNode = NULL;
 }
 else
 {
  cout << "Error: Trying to display empty stack" << endl;
  exit(1);
 }
}

void Stack::sortIt(int order)
{
 if (order != 0 && order != 1)
 {
  cout << "Error: Invalid order input" << endl;
  exit(1);
 }

 node* start = top;

 while (start -> next != NULL)
 {
  node* tempPtr = start -> next;
  node* extremeNum = start;

  while (tempPtr != NULL)
  {
   //ascending
   if (order == 0)
   {
    if (tempPtr -> item < extremeNum -> item)
       extremeNum = tempPtr;
   }

   //descending
   if (order == 1)
   {
    if (tempPtr -> item > extremeNum -> item)
       extremeNum = tempPtr;
   }

   tempPtr = tempPtr -> next;
  }
  
  itemType temp = start -> item;
  start -> item = extremeNum -> item;
  extremeNum -> item = temp;

  tempPtr = NULL;
  extremeNum = NULL;
  start = start -> next;
 }

 start = NULL;
}
