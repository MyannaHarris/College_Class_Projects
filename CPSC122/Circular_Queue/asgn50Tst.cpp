#include <iostream>
using namespace std;

#include "ex50.h"

int main()
{
 Queue que(5);
 for (int i = 0; i < 4; i++)
   que.enqueue(i);
 que.display();
 cout << que.dequeue() << endl;
 cout << que.dequeue() << endl;
 cout << "new list" << endl;
 que.display();
}
