/*
Class: cpsc122 - 01
Assignment: assignment 9
Team Leader: Cameron Anderson canderson10@ada.gonzaga.edu
Developer: Myanna Harris mharris5@ada.gonzaga.edu
QA: Jasmine Jans jjans@ada.gonzaga.edu
*/

#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

#include"asgn9.h"
#include"asgn7.h"

Calculator::Calculator(char* inFixIn)
{
 numVariables = 0;
 inFix = new char[strlen(inFixIn)];
 inFix = inFixIn;
 postFix = new char[strlen(inFix)];
 CheckTokens();
 vars = new symbols[numVariables];
}

Calculator::~Calculator()
{
 delete inFix;
 delete postFix;
 delete vars;
 
 inFix = NULL;
 postFix = NULL;
 vars = NULL;
}

bool Calculator::CheckTokens()
{
 int i = 0;
 while(inFix[i] != '\0')
 {
  if(!isParen(inFix[i]) && !isOper(inFix[i]) && !isupper(inFix[i]))
    return false;
  
  if(isupper(inFix[i]))
    numVariables++;
  i++;
 }
 return true;
}

bool Calculator::CheckParens()
{
 Stack* stk = new Stack;
 int i = 0;
 bool bal = true;
 while(bal && inFix[i] != '\0')
 {
  if (inFix[i] == '(')
     stk->push(inFix[i]);

  if (inFix[i] == ')')
  {
   if (!stk->isEmpty())
      stk->pop();
   else
      bal = false;
  }
  i++;
 }

 if (!stk->isEmpty() || !bal)
 {
  delete stk;
  stk = NULL;
  return false;
 }

 if (bal)
 {
  delete stk;
  stk = NULL;
  return true;
 }
}

void Calculator::displayInFix()
{
 cout << inFix << endl;
}

void Calculator::makeSymbolTable()
{
 int i = 0;
 int v = 0;
 while(inFix[i] != '\0')
 {
  if(isupper(inFix[i]))
  {
   vars[v].symbolName = inFix[i];
   cout << "Enter value for " << inFix[i] << ":" << endl;
   cin >> vars[v].symbolValue;
   v++;
  }
  i++;
 }
}

void Calculator::inFixtoPostFix()
{
 Stack* stk = new Stack;
 int i = 0;
 int p = 0;
 while(inFix[i] != '\0')
 {
  if (inFix[i] == '(')
     stk -> push(inFix[i]);

  if (isupper(inFix[i]))
  {
   postFix[p] = inFix[i];
   p++;
  }

  if (isOper(inFix[i]))
     stk -> push(inFix[i]);

  if(inFix[i] == ')')
  {
   if(!stk->isEmpty())
   {
    char temp = stk -> pop();
    while (temp != '(')
    {
     postFix[p] = temp;
     temp = stk -> pop();
     p++;
    }
   }
  }
  i++;
 }

 delete stk;
 stk = NULL;
}

int Calculator::evalPostFix()
{
 Stack* stk = new Stack;
 int i = 0;
 int result = 0;
 while(postFix[i] != '\0')
 {
  if (isupper(postFix[i]))
  {
   int v = 0;
   while (vars[v].symbolName != postFix[i])
       v++;

   stk -> push(vars[v].symbolValue);
  }

  if (isOper(postFix[i]))
  {
   int op2 = stk -> pop();
   int op1 = stk -> pop();

   if (postFix[i] == '+')
      result = op1 + op2;
   if (postFix[i] == '-')
      result = op1 - op2;
   if (postFix[i] == '/')
      result = op1 / op2;
   if (postFix[i] == '*')
      result = op1 * op2;

   stk -> push(result);
  }

  i++;
 }

 result = stk -> pop();

 delete stk;
 stk = NULL;

 return result;
}

void Calculator::displayPostFix()
{
 cout << postFix << endl;
}

bool Calculator::isOper(char ch)
{
 if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    return true;
 else
    return false;
}

bool Calculator::isParen(char ch)
{
 if (ch == '(' || ch == ')')
    return true;
 else
    return false;
}
