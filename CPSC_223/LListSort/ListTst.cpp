/**
 * @file ListTst.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 3-2-14
 *
 * Tests the linked list of nodes.
 */

#include <iostream>
using namespace std;

#include "List.h"

int main()
{
 List* lst = new List();
 itemType item1;

 //check isEmpty()
 if (lst -> isEmpty())
   cout << "The list is empty" << endl;
 else
    cout << "The list is not empty" << endl;

 //fill with integers 1-5
 for (int i = 1; i <= 5; i++)
     lst->insert(i,i);

 //check isEmpty()
 if (lst -> isEmpty())
   cout << "The list is empty" << endl;
 else
    cout << "The list is not empty" << endl;
 
 //display length
 cout << "length: " << lst -> getSize() << endl;

 //display list
 cout << "initial list" << endl; 
 lst->display();

 //test insert and remove
 cout << "insert 100 in the second position and delete the 3rd node" << endl;
 lst->insert(2,100);
 lst->remove(3);
 lst->display();

 //test of copy constructor
 List* myList = new List();
 for (int i = 1; i <=5; i++)
  myList->insert(i,i);
 
 cout << "mylist" << endl;
 myList->display();

 List* myListA = new List(myList);
 cout << "copy" << endl;
 myListA->display();

 //test >> overloader
 cout << "test >> operaor" << endl;
 cout << "before : " << endl;
 lst->display();
 cout << "enter new int" << endl;
 cin >> lst;
 cout << "with new item : " << endl;
 lst->display();

 //test merge sort
 cout << "merge sort" << endl;
 cout << "before : " << endl;
 lst->display();
 lst->sort_mergesort();
 cout << "sorted : " << endl;
 lst->display();

 return 0;
}
