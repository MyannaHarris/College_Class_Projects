#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#include "asgn4.h"

int main(int argc, char* argv[])
{
 int size = atoi(argv[1]);
 Array array(size);

 if (array.isEmpty())
    cout << "The array is empty" << endl;
 else
    cout << "The array is not empty" << endl;

 if (array.isFull())
    cout << "Full" << endl;
 else
    cout << "Not Full" << endl;

 for (int i = 0; i < array.len(); i++)
  array.put((rand() % 10) + 1,i); 

 if (array.isEmpty())
   cout << "The array is empty" << endl;
 else
    cout << "The array is not empty" << endl;

 if (array.isFull())
    cout << "Full" << endl;
 else
    cout << "Not Full" << endl;

 cout << "contents of the array" << endl;
 array.display();

 array.sortIt();

 cout << "Sorted contents of the array" << endl;
 array.display();

 cout << "number of items: " << array.getNumItems() << endl;

 if (array.isValid(0))
    cout << "first item: " << array.get(0) << endl;

 array.del(0);

 cout << "New array" << endl;
 array.display();

 cout << array.isIn(3) << endl;

 Array array2 = *array.copy();

 cout << "array original : " << endl;
 array.display();
 cout << "copy : " << endl;
 array2.display();
}
