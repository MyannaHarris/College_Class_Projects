/*
Class: cpsc122 - 01
Assignment: assignment 2
Team Leader: Myanna Harris mharris5@ada.gonzaga.edu
Developer: Cameron Anderson canderson10@ada.gonzaga.edu
QA: Jasmine Jans jjans@ada.gonzaga.edu
*/

//Calculate monthly payment on credit card
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
 //int = interest, pay = payment
 double costCar;
 double monthInt;
 int numPay;

 double monthPay;
 double totalPay;
 double intPay;
 double intFraction;

 //input
 cout << "Enter the cost of the car: " << endl;
 cin >> costCar;
 cout << "Enter the monthly interest (%): " << endl; //Have to change percent to decimal
 cin >> monthInt;
 monthInt /= 100; //change interest to decimal form
 cout << "Enter the number of payments: " << endl;
 cin >> numPay;

 //calculations
 monthPay = (monthInt * pow(1 + monthInt, numPay)) / (pow(1 + monthInt, numPay) - 1) * costCar;
 totalPay = monthPay * numPay;
 intPay = totalPay - costCar;
 intFraction = (intPay / costCar) * 100;
 monthInt *= 100; //return interest to percent form

 //output
 cout << "Cost of car: " << setw(32) << "$ " << setprecision(2) << fixed << setw(9) << costCar << endl;
 cout << "Monthly interest rate: " << setw(21) << "  " << setprecision(2) << fixed << setw(9) << monthInt << "%" << endl;
 cout << "Number of Payments: " << setw(25) << "  " << setw(9)  << numPay << endl;
 cout << "Monthly payment: " << setw(28) << "$ " << setprecision(2) << fixed << setw(9) << monthPay << endl;
 cout << "Amount to be paid: " << setw(26) << "$ " << setprecision(2) << fixed << setw(9) << totalPay << endl;
 cout << "Interest paid: " << setw(30) << "$ " << setprecision(2) << fixed << setw(9) << intPay << endl;
 cout << "Interest as a fraction of the cost: " << setw(8) << "  " << setprecision(2) << fixed << setw(9) << intFraction << "%" << endl;
}
