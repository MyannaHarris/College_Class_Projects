#include <iostream>
using namespace std;

#include "asgn7.h"

int main()
{
 Stack* stk = new Stack;
 
 if (stk -> isEmpty())
   cout << "The stack is empty" << endl;
 else
    cout << "The stack is not empty" << endl;

 for (int i = 1; i <= 5; i++)
   stk->push(i);

 if (stk -> isEmpty())
   cout << "The stack is empty" << endl;
 else
    cout << "The stack is not empty" << endl;

 stk->display();

 cout << "size: " << stk->getNum() << endl;

 cout << "peek: " << stk->peek() << endl;

 cout << "pop: " << stk->pop() << endl;

 stk->sortIt(0);
 cout << "sorted asc" << endl;
 stk->display();

 stk->sortIt(1);
 cout << "sorted desc" << endl;
 stk->display();

 Stack* stk2 = new Stack(stk);
 cout << "copied" << endl;
 stk2->display();

 stk->sortIt(3);
 cout << "Not to be displayed" << endl;
}
