#ifndef CALCULATOR_H
#define CALCULATOR_H

//struct for the symbol table

struct symbols
{
 char symbolName;
 int symbolValue;
};

class Calculator 
{ 
  public: 
   /*
  pre:  inFixIn 
  post: inFixIn is copied to inFix. The other member variables are set 
        to Null or 0 as appropriate.  An instance of class Calculator is 
	created. Save yourselves some trouble by using strcpy.
  */
  Calculator(char* inFixIn); 
  
 ~Calculator();

  /*
  pre:  instance of calculator existes   
  post: true if the stored infix expresson uses only legal variables, 
        operators, and parens, false otherwise. Sets numVariables to the 
	number of the variables. Invoked from the test program.
	The variables are upper case alphabetic characters.
  */
  bool CheckTokens(); 


  /*
   pre: instance of calculator exists and all input tokens are legal
        A stack is available for use.  
   post: returns true if the parentheses are balanced, false otherwise. 
         Invoked from the test program.
  */
  bool CheckParens();

 /*
  pre: instance of calculator exists. 
  post: displays the infix expression
 */
  void displayInFix();

 /*
  pre: instance of calculator exists 
  post: symbol  table is created.  
        The constructor has already created an array of struct symbols.  See
        the top of this file for a description.
        If the input express is (A+B) with A = 7 and B = 12,
        the symbol table would look like this:
        A 7
        B 12 
 */
  void makeSymbolTable();

 /*
  pre: instance of calculator exists. symbol table has been loaded 
  post: postFix holds the postfix version of inFix   
 */
  void inFixtoPostFix();

 /*
  pre: instance of calculator exists. symbol table has been loaded. 
       infix expression has been converted to postfix 
  post: returns the value of the input expression evaluated using 
        the elicited corresponding values.  
 */
  int evalPostFix();

 /*
  pre: instance of calculator exists. postFix version has been stored
  post: displays the postfix expression
 */
  void displayPostFix();
 private: 

  bool isOper(char ch);  //will help out enormously in checkTokens
  bool isParen(char ch); //will help  out enormously in checkTokens

  int numVariables; //the number of variables in the expression  
  char*  inFix;     //pointer to the array holding the infix expression 
  char* postFix;    //pointer to the array holding the postfix  
  symbols* vars;   //symbol table to be used in assignment 9. Pointer to
                    //an array of structs (see the top of this file) 
};
#endif
