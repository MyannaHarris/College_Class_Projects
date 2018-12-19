/*
Class: cpsc122 - 01
Assignment: Final Take-Home Question 2
Team Leader: Myanna Harris mharris5@ada.gonzaga.edu
Developer: Myanna Harris mharris5@ada.gonzaga.edu
QA: Myanna Harris mharris5@ada.gonzaga.edu
*/

#include<iostream>
using namespace std;

int myStrLen1(char*, int);
int myStrLen2(char*);

int main()
{
 char* str = new char[3];
 str[0] = 'a';
 str[1] = 'b';
 str[2] = 'c';
 cout << myStrLen1(str, 0) << endl;
 cout << myStrLen2(str) << endl;
 cout << str << endl;

 char* str1 = new char[0];
 cout << myStrLen1(str1, 0) << endl;
 cout << myStrLen2(str1) << endl;
 cout << str1 << endl;
}

int myStrLen1(char* str, int pos)
{
 if (str[pos] == '\0')
    return 0;

 int count = 0;
 while (str[pos] != '\0')
 {
  count++;
  pos++;
 }
 return count;
}

int myStrLen2(char* str)
{
 if (str[0] == '\0')
    return 0;

 int count = 0;
 int pos = 0;
 while (str[pos] != '\0')
 {
  count++;
  pos++;
 }
 return count;
}
