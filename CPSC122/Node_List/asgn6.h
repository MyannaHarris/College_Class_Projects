/*
Class: cpsc122 - 01
Assignment: assignment 6
Team Leader: Cameron Anderson canderson10@ada.gonzaga.edu
Developer: Myanna Harris mharris5@ada.gonzaga.edu
QA: Jasmine Jans jjans@ada.gonzaga.edu
*/

#ifndef LIST_H
#define LIST_H
#include "types.h"

class List
{
 public:
   List();
   List(List* listIn);
   ~List();

   /*
   Pre: an instance of List exists
   Post: returns true if empty, false otherwise
   */
   bool isEmpty();

   /*
   Pre: an instance of List exists
   Post: returns the length of the list 
   */
   int getLength();
  
   /*
   Pre: an instance of List exists
   Post: if pos < 1 or > size + 1, returns false, else inserts item 
         at position pos and true is returned
   */
   bool set(int pos, itemType newItem); 

   /*
   Pre: an instance of List exists
   Post: if pos < 1 or > size + 1, returns false, else item contains 
         value at position pos and true is returned 
   */
   bool get(int pos, itemType& item);

   /*
   Pre: an instance of List exists
   Post: if pos < 1 or > size + 1, returns false, else deletes node
         at position pos and true is returned 
   */
   bool del(int pos);

   /*
   Pre: an instance of List exists
   Post: displays value of each node on separate lines 
   */
   void display();

   //Assignment 6 Starts Here

   /*
   Pre: an instance of List exists
   Post: If list is empty or a new node cannot be created, returns false.
         Else stores newItem at the tail of the list and returns true.
   */
   bool setT(itemType newItem); 

   /*
   Pre: an instance of List exists
   Post: if list is empty return false, else item contains value at the 
         tail of the list and true is returned
   */
   bool getT(itemType& item); 

   /*
   Pre: an instance of List exists
   Post: if list is empty returns false, else tail of the list is 
         deleted and true is returned 
   */
   bool delT(); 

   /*
   Pre: an instance of List exists
   Post: list is sorted in ascending order using selection sort
   */
   void sortIt(); 
   
 private:
   //returns pointer to the node just before the node at pos
   node* ptrTo(int pos);
  
   //inserts newItem at the head of the list
   bool set(itemType newItem); 

   //number of nodes in the list
   int size;

   //pointer to the head of the list
   node* head;

   node* tail;

};
#endif
