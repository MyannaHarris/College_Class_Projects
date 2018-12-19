/**
 * @file ListTst.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 2-23-14
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
   lst->set(i,i);

 //check isEmpty()
 if (lst -> isEmpty())
   cout << "The list is empty" << endl;
 else
    cout << "The list is not empty" << endl;
 
 //display length
 cout << "length: " << lst -> getLength() << endl;

 //display list
 cout << "initial list" << endl; 
 lst->display();

 //get an item then remove it
 lst->get(1,item1);
 lst->del(1);
 cout << "display the first item" << endl;
 cout << item1 << endl;
 cout << "display the list with first item removed" << endl;
 lst->display();

 //test set and delete
 cout << "insert 100 in the first position and delete the 3rd node" << endl;
 lst->set(1,100);
 lst->del(3);
 lst->display();

 //test set tail and get tail
 cout << "setT as 5" << endl;
 lst->setT(5);
 itemType temp;
 lst->getT(temp);
 cout << "getT: " << endl;
 cout << temp << endl;
 lst->display();

 //test delete tail
 lst->delT();
 cout << "delT" << endl;
 lst->display();

 //test sort
 cout << "Sort" << endl;
 cout << "before : " << endl;
 lst->display();
 lst->sortIt();
 cout << "after : " << endl;
 lst->display();

 //test of copy constructor
 List* myList = new List();
 for (int i = 1; i <=5; i++)
  myList->set(i,i);
 
 cout << "mylist" << endl;
 myList->display();

 List* myListA = new List(myList);
 cout << "copy" << endl;
 myListA->display();

 return 0;
}
