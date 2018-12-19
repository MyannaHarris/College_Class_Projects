/*
Class: cpsc122 - 01
Assignment: assignment 8
Team Leader: Jasmine Jans jjans@ada.gonzaga.edu
Developer: Cameron Anderson canderson10@ada.gonzaga.edu
QA: Myanna Harris mharris5@ada.gonzaga.edu
*/

#include<iostream>
#include<cctype>
using namespace std;

#include"asgn8.h"
#include"asgn7.h"

Calculator::Calculator(char* inFixIn)
{
 numVariables = 0;
 inFix = inFixIn;
 postFix = NULL;
 vars = NULL;
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
  if(inFix[i] != '(' && inFix[i] != ')' && inFix[i] != '+' && inFix[i] != '-' 
    && inFix[i] != '/' && inFix[i] != '*' && !isupper(inFix[i]))
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
  if(inFix[i] == '(')
  {
    stk->push(inFix[i]);
  }

  if(inFix[i] == ')')
  {
   if(!stk->isEmpty())
     stk->pop();
   else
     bal = false;
  }
  i++;
 }

 if(!stk->isEmpty() || !bal)
 {
  return false;
 }

 if(bal)
 {
  return true;
 }
}

void Calculator::displayInFix()
{
 cout << inFix << endl;
}
