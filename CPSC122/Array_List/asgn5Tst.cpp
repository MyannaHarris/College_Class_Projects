#include <iostream>
#include <cstdlib>
using namespace std;

#include "asgn5.h"

int main(int argc, char* argv[])
{
 int size = atoi(argv[1]);

 ListA* list =  new ListA(size);

 if (list -> isEmpty())
   cout << "The list is empty" << endl;
 else
    cout << "The list is not empty" << endl;

 if (list -> isFull())
   cout << "The list is full" << endl;
 else
    cout << "The list is not full" << endl;

 for (int i = size; i >= 1; i--)
  list->setT(i); 

 itemType value;
 if (list->getT(value))
   cout << "last item" << " " << value << endl; 
 else
   cout << "list is empty" << endl; 

 if (list->getH(value))
   cout << "First item" << " " << value << endl; 
 else
   cout << "list is empty" << endl; 

 if (list->isEmpty())
   cout << "The list is empty" << endl;
 else
    cout << "The list is not empty" << endl;

 if (list -> isFull())
   cout << "The list is full" << endl;
 else
    cout << "The list is not full" << endl;

 cout << "contents of the array" << endl;
 list->display();

 list -> delT();
 cout << "tail del" << endl;
 list->display();

 list -> setH(2);
 cout << "setH" << endl;
 list->display();

 list -> delH();
 cout << "H del" << endl;
 list->display();

 list -> sortIt();
 cout << "sort" << endl;
 list -> display();

 ListA* newlst = new ListA(list);
 cout << "copy" << endl;
 newlst -> display(); 

 delete list;
 list = NULL; 
 return 0;
}
