/*
Class: cpsc122 - 01
Assignment: assignment 4
Team Leader: Myanna Harris mharris5@ada.gonzaga.edu
Developer: Jasmine Jans jjans@ada.gonzaga.edu
QA: Cameron Anderson canderson10@ada.gonzaga.edu
*/

#ifndef LISTA_H 
#define LISTA_H 

#include "typesA.h"

class ListA 
{
 public:
  /*
  Pre: sizeIn is an integer > 0
  Post: An instance of ListA of size sizeIn is created
  */
  ListA(int sizeIn);

  ~ListA();
  
  /* 
  Pre: an instance of ListA exists
  Post: returns true if the list is empty, false otherwise
  */
  bool isEmpty();

  /*
  Pre: an instance of ListA exists
  Post: returns true if the list is full, false otherwise
  */
  bool isFull();

  /*
  Pre: an instance of ListA exists
  Post: if list is not full, value is inserted at the tail of the list 
        and true is returned, else false is returned
  */
  bool setT(itemType value);

  /*
  Pre: an instance of ListA exists.
  Post: if list is not empty, value is set to value of item at the tail 
        of the list and true is returned, else false is returned
  */
  bool getT(itemType& value);

  /*
  Pre: an instance of ListA exists
  Post: displays each element in the list, pos 0 through pos size - 1 
  */
  void display();

  //Assignment 5. These appear in approximately the order in which you should
  // write and test them.  

  /*
  Pre: an instance of ListA exists
  Post: returns the position in the list of the next item to be stored 
  */
  int getTail();

  /*
  Pre: an instance of ListA exists
  Post: returns size of the array (not the number of items) 
  */
  int getSize();
  
  
  /*
  Pre: an instance of ListA exists
  Post: if list is not empty, value at the tail of the list is deleted
        and true is returned, else false is returned
        (nothing has to be written to the array to accomplish this)
  */
  bool delT();
  
  /*
  Pre: an instance of ListA exists
  Post: if list is not full, value is inserted at the head of the list 
        and true is returned, else false is returned
	(think about what has to happen to the items already in the list)
  */
  bool setH(itemType value);

  /*
  Pre: an instance of ListA exists.  
  Post: if list is not empty, value is set to value of item at the head 
        of the list and true is returned, else false is returned
  */
  bool getH(itemType& value);

  /*
  Pre: an instance of ListA exists
  Post: If list is not empty, item stores the element in the ith position
        of the array and returns true, returns false otherwise
  */
  bool getAny(itemType& item, int pos);
  
  /*
  Pre: an instance of ListA exists
  Post: if list is not empty, value at the head of the list
        is deleted
        (nothing has to be written to the array to accomplish this)
  */
  bool delH();
  
  /*
  Pre: an instance of ListA exists
  Post: sorts the instance using selection sort 
  */
  void sortIt();

  /*
  Pre: listIn is pointer to an instance of ListA 
  Post: An instance of ListA that is identical to ListIn has been created 
  Usage: ListA* newLst = new ListA(listIn); 
         or     ListA newList(listIn);
  */
  ListA(ListA* listIn);
 
 private:
  int size;         //size of the list 
  int tail;         //position of the tail of the list
  itemType* stuff; //a pointer to the array holding list items 
};
#endif
