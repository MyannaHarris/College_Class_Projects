/*
Class: cpsc122 - 01
Assignment: assignment 4
Team Leader: Myanna Harris mharris5@ada.gonzaga.edu
Developer: Jasmine Jans jjans@ada.gonzaga.edu
QA: Cameron Anderson canderson10@ada.gonzaga.edu
*/

//Array
#include <iostream>
using namespace std;

#include "asgn4.h"

Array::Array(int sizeIn)
{
 size = sizeIn;
 numItems = 0;
 stuff = new int[size];
 for (int i = 0; i < size; i++)
   stuff[i] = 0;
}

Array::~Array()
{
 delete [] stuff;
 stuff = NULL;
}

void Array::put(int num, int pos)
{
 if (stuff[pos] == 0)
    numItems++;
 stuff[pos] = num;
 if (num == 0)
    numItems--;
}

bool Array::isEmpty()
{
 if (numItems == 0)
    return true;
 else
    return false;
}

void Array::display()
{
 for (int i = 0; i < size; i++)
   cout << stuff[i] << endl;
}

int Array::len()
{
 return size;
}

void Array::del(int pos)
{
 stuff[pos] = 0;
 if (numItems != 0)
    numItems--;
}

int Array::getNum()
{
 return numItems;
}

int Array::get(int pos)
{
 return stuff[pos];
}

bool Array::isValid(int pos)
{
 if (0 <= pos && pos < (size - 1))
    return true;
 else
    return false;
}

bool Array::isIn(int elt)
{
 for (int i = 0; i < size; i++)
 {
  if (elt == stuff[i])
     return true;
 }
 
 return false;
}

bool Array::isFull()
{
 if (numItems == size)
    return true;
 else
    return false;
}

void Array::sortIt()
{
 for (int curr = 0; curr < (size - 1); curr++)
 {
  int smallest = curr;

  for (int i = curr; i < size; i++)
  {
   if (stuff[i] < stuff[smallest])
      smallest = i;
  }
  
  int temp = stuff[curr];
  stuff[curr] = stuff[smallest];
  stuff[smallest] = temp;
 }
}

Array* Array::copy()
{
 Array* arrayPt = new Array(size);
 for (int i = 0; i < size; i++)
   arrayPt -> put(stuff[i], i);
 
 return arrayPt;
}
