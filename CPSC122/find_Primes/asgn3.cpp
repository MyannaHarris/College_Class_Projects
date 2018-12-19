/*
Class: cpsc122 - 01
Assignment: assignment 3
Team Leader: Jasmine Jans jjans@ada.gonzaga.edu
Developer: Myanna Harris mharris5@ada.gonzaga.edu
QA: Cameron Anderson canderson10@ada.gonzaga.edu
*/

//Find prime numbers
#include <iostream>
#include <cmath>
using namespace std;

//function prototypes to tell compiler
bool isPrime(int);
bool isValid(int, int);

//variables
int x = 0; //lower bound
int y = 0; //upper bound
bool primes = false; //flag to check if there are any primes

int main()
{
 bool checkValid = isValid(x, y)

 while (checkValid) //get valid numbers
 {
  cout << "Enter the lower bound greater than or equal to 2:" << endl;
  cin >> x;
  cout << "Enter the upper bound greater than the first number:" << endl;
  cin >> y;

  if (!checkValid)
     cout << "Error. Please enter valid numbers." << endl;
 }

 cout << "" << endl;
 cout << "Prime numbers between " << x << " and " << y << ":" << endl;

 for (int i = x; i <= y; i++) //check each number
 {
  if (isPrime(i) == true) //output number if it is prime
  {
   primes = true;
   cout << i << endl;
  }
 }

 if (primes == false)
    cout << "No primes" << endl;
}

/*
Pre: Number is between x and y
Post: If number is prime, function returns true, returns false otherwise
*/
bool isPrime(int number)
{
 for (int i = 2; i <= sqrt(number); i++) //check for odd factors
     if (number > i && number % i == 0)
        return false;

 return true;
}

/*
Pre: x and y are integers
Post: If x is 2 or greater and y is greater than x, function returns true,
      returns false otherwise
*/
bool isValid(int x, int y)
{
 if (x < 2 || x >= y)
    return false;

 return true;
}
