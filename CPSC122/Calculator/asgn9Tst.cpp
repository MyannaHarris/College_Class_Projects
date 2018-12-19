#include <iostream>
#include <cstdlib>
using namespace std;

#include"asgn9.h"

//command line arguments

int main(int argc, char* argv[])
{
 char* expr = argv[1];

 Calculator* calc = new Calculator(expr);

 calc->displayInFix();

 cout << calc->CheckTokens() << endl;

 cout << calc->CheckParens() << endl;

 calc->inFixtoPostFix();

 calc->displayPostFix();

 calc->makeSymbolTable();

 cout << calc->evalPostFix() << endl;

 return 0;
}
