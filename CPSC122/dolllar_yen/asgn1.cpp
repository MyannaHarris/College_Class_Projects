/*
Class: cpsc122 - 01
Assignment: assignment 1
Team Leader: Myanna Harris mharris5@ada.gonzaga.edu
Developer: Cameron Anderson canderson10@ada.gonzaga.edu
QA: Jasmine Jans jjans@ada.gonzaga.edu
*/

//Convert from dollar to yen (1 = 98.17)
#include <iostream>
#include <iomanip>
using namespace std;

//Yen/Dollar constant (1 dolar = 98.17 yen)
const double YEN_CONST = 98.17;

int main()
{
 double yenCost;
 double dollarCost;

 cout << "Please input the cost per night of your room in yen:" << endl; //Get yen cost from user
 cin >> yenCost;
 dollarCost = yenCost / YEN_CONST; //calculate dollar equivalent
 cout << "Your room will cost " << setprecision(2) << fixed << dollarCost << " dollar(s)." << endl;
}
