#include <iostream>
using namespace std;

#include "asgn6.h"


int main()
{
 List* lst = new List();
 itemType item1;

 if (lst -> isEmpty())
   cout << "The list is empty" << endl;
 else
    cout << "The list is not empty" << endl;

 for (int i = 1; i <= 5; i++)
   lst->set(i,i);

 if (lst -> isEmpty())
   cout << "The list is empty" << endl;
 else
    cout << "The list is not empty" << endl;
 
 cout << "length: " << lst -> getLength() << endl;

 cout << "initial list" << endl; 
 lst->display();

 lst->get(1,item1);
 lst->del(1);

 cout << "display the first item" << endl;
 cout << item1 << endl;
 cout << "display the list with first item removed" << endl;
 lst->display();
 cout << "insert 100 in the first position and delete the 3rd node" << endl;
 lst->set(1,100);
 lst->del(3);
 lst->display();

 lst->setT(5);
 itemType temp;
 lst->getT(temp);
 cout << "getT: " << endl;
 cout << temp << endl;
 lst->display();

 lst->delT();
 cout << "delT" << endl;
 lst->display();

 lst->sortIt();
 cout << "sort" << endl;
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
