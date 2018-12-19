/**
 * @file List.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 3-2-14
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
}

//copy constructor
List::List(const List* listIn)
{
 size = listIn->size;
 if (listIn->head == NULL)
 {
  //to copy empty list
  head = NULL;
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
     newPtr = NULL;
    }
}

List::~List()
{
 //empty list
 while (size > 0)
    remove(1);
}

bool List::isEmpty() const
{
 if (size > 0)
    return false;
 else
    return true;
}

int List::getSize() const
{
 return size;
}

void List::insert(int pos, const itemType & newItem)
{
 //inserts newItem at pos
 if (!(pos < 1 || pos > (size + 1)))
 {
  Node* tempPtr = new Node();
  tempPtr -> item = newItem;

  if (pos == 1)
  {
   tempPtr -> next = head;
   head = tempPtr;
  }
  else
  {
   Node* passPtr = ptrTo(pos - 1);
   tempPtr -> next = passPtr -> next;
   passPtr -> next = tempPtr;
   passPtr = NULL;
  }

  size++;
  tempPtr = NULL;
 }
}

void List::remove(int pos)
{
 //deletes Node at pos
 if (!(pos < 1 || pos > size))
 {
  if (pos == 1)
  {
   Node* tempPtr = head;
   head = tempPtr -> next;

   size--;
   delete tempPtr;
   tempPtr = NULL;
  }
  else
  {
   Node* tempPtr = ptrTo(pos - 1);
   Node* nextPtr = tempPtr -> next;

   tempPtr -> next = nextPtr -> next;

   size--;
   tempPtr = NULL;
   nextPtr = NULL;
  }
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
}

//ascending
void List::sort_mergesort()
{
 head = mergesort(head, size);
}

Node* List::ptrTo(int pos)
{
 //iterates through linked list
 Node* tempPtr = head;
 for (int i = 1; i < pos; i++)
    tempPtr = tempPtr -> next;
 return tempPtr;
}

Node* List::getHead()
{
 return head;
}

Node* List::setHead(Node* newHead)
{
 head = newHead;
}

istream& operator >>(istream& in, List* list)
{
 //input new node
 Node* newNode = new Node();
 itemType item;
 in >> item;
 newNode -> setItem(item);
 newNode -> setNext(list -> getHead());
 list -> setHead(newNode);
 
 return in;
}

//sort using merge sort
Node* List::mergesort(Node* head, int size)
{
 Node* headNode;

 //recursive merge sort
 int length1;
 int length2;

 if (head -> next != NULL)
 {
  if (size % 2 != 0)
  {
   length1 = (int)size/2;
   length2 = size - length1;
  }
  else
  {
   length1 = size/2;
   length2 = length1;
  }

  Node* head1 = head;
  Node* head2;
  Node* beforeHead = head;

  for (int i = 1; i < length1; i++)
      beforeHead = beforeHead -> next;

  head2 = beforeHead -> next;
  beforeHead -> next = NULL;

  head1 = mergesort(head, length1);
  head2 = mergesort(head2, length2);

  headNode = merge(head1, head2); 
 }
 else
    headNode = head;

 return headNode;
}

//merge two lists
Node* List::merge(Node* head, Node* head2)
{
 Node* headNode;
 Node* savedNode;
 Node* savedNode2;
 if (head -> item <= head2 -> item)
 {
  headNode = head;
  Node* tempPtr = head;
  while (tempPtr != NULL && tempPtr -> item <= head2 -> item)
  {
   savedNode = tempPtr;

   tempPtr = tempPtr -> next;
  }

  while (savedNode != NULL)
  {
   while (head2 != NULL && savedNode -> next != NULL && savedNode -> next -> item >= head2 -> item)
   {
    //save current node and incriment head2 to next node in list
    Node* tempNode = head2;
    head2 = head2 -> next;

    //insert tempNode (current node) from head2
    tempNode -> next = savedNode -> next;
    savedNode -> next = tempNode;
   }

   if (savedNode -> next == NULL)
      savedNode2 = savedNode;

   savedNode = savedNode -> next;
  }

  if (savedNode == NULL && head2 != NULL)
  {
   savedNode = savedNode2;

   //insert rest of head2
   savedNode -> next = head2;
  }
 }
 else
 {
  headNode = head2;
  Node* tempPtr = head2;
  while (tempPtr != NULL && tempPtr -> item <= head -> item)
  {
   savedNode = tempPtr;

   tempPtr = tempPtr -> next;
  }

  while (savedNode != NULL)
  {
   while (head != NULL && savedNode -> next != NULL && savedNode -> next -> item >= head -> item)
   {
    //save current node and incriment head to next node in list
    Node* tempNode = head;
    head = head -> next;

    //insert tempNode (current node) from head
    tempNode -> next = savedNode -> next;
    savedNode -> next = tempNode;
   }

   if (savedNode -> next == NULL)
      savedNode2 = savedNode;

   savedNode = savedNode -> next;
  }

  if (savedNode == NULL && head != NULL)
  {
   savedNode = savedNode2;

   //insert rest of head
   savedNode -> next = head;
  }
 }

 return headNode;
}

/*
ListNode* ListP::merge(ListNode* lhead1, ListNode* lhead2)
{
  if (lhead1 == NULL)
  {
   return lhead2;
  }
  else if (lhead2 == NULL)
  {
   return lhead1;
  }
  else if (lhead1->getItem() > lhead2->getItem())
  {
     lhead2->setNext(merge(lhead1, lhead2->getNext()));
     return lhead2;
  }
  else if (lhead1->getItem() < lhead2->getItem())
  {
     lhead1->setNext(merge(lhead1->getNext(), lhead2));
     return lhead1;
  }
  else
  {
     lhead1->setNext(merge(lhead1->getNext(), lhead2));
     return lhead1;
  }
       
}
*/
