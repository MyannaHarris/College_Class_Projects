/*
Class: cpsc122 - 01
Assignment: assignment 4
Team Leader: Myanna Harris mharris5@ada.gonzaga.edu
Developer: Jasmine Jans jjans@ada.gonzaga.edu
QA: Cameron Anderson canderson10@ada.gonzaga.edu
*/

#ifndef ARRAY_H 
#define ARRAY_H 

class Array 
{
 public:
  //Pre: sizeIn is an integer > 0
  //An instance of Array of size sizeIn is created
  Array(int sizeIn);

  ~Array();

  //Pre: an instance of Array exists, num is an integer, 0<=pos<size
  //Post: num is inserted into position pos in stuff
  void put(int num, int pos);
 
  //Pre: an instance of Array exists
  //Post: returns true if the instance is empty, false otherwise
  bool isEmpty();

  //Pre: an instance of Array exists
  //Post: displays each element in the Array, pos 0 through pos size - 1  
  void display();
 
  //Asgn4

  //Pre: an instance of Array exists
  //Post: returns the number of items the instance can hold  
  int len();

  //Pre: an instance of Array exists; 0 <= pos < size
  //Post: inserts 0 in pos, decrements numItems  
  void del(int pos);
  
  //Pre: an instance of Array exists
  //Post: returns the number of items in the array
  int getNum();
 
  //Pre: an instance of Array exists, 0 <= pos < size
  //Post: returns the item in position
  int get(int pos);
 
  //Pre: an instance of Array exists
  //Post: returns true if 0 <= pos < size - 1, false otherwise 
  bool isValid(int pos);
 
  //Pre: an instance of Array exists
  //Post: returns true if the item is in the instance, false otherwise 
  bool isIn(int elt);
  
  //Pre: an instance of Array exists
  //Post: returns true if the array is full, false otherwise 
  bool isFull();

  //Pre: an instance of Array exists
  //Post: sorts the instance using selection sort (ex16)
  void sortIt();

  //Pre: an instance of Array exists
  //Post: returns a pointer to a new instance of Array.  The new instance is a 
  //      copy of the current instance
  Array* copy();

 private:
  int size;       //size of the instance 
  int numItems;   //the number of items in instance 
  int* stuff;  //a pointer to the array holding items of the instance 
};
#endif
