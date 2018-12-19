//struct for a symbol table to be used in assignment 9
struct symbols
{
 char symbolName;
 int symbolValue;
};

class Calculator 
{ 
  public: 
   /*
  pre: inFixIn 
  post: inFixIn is copied to inFix. The other member variables are set 
        to Null or 0 as appropriate.  An instance of class Calculator is 
	created.
  */
  Calculator(char* inFixIn);

  ~Calculator();
  /*
  pre:  instance of calculator existes   
  post: true if the stored infix expresson uses only legal variables, 
        operators, and parens, false otherwise. Sets numVariables to the 
	number of the variables. Will be invoked from the test program.
  */
  bool CheckTokens(); 


  /*
   pre: instance of calculator exists and all input tokens are legal
   post: returns true if the parentheses are balanced, false otherwise. 
         Will be invoked from the test program.
  */

  bool CheckParens();

 /*
  pre: instance of calculator exists. 
  post: displays the infix expression
 */
  void displayInFix();

 private: 

  int numVariables; //the number of variables in the expression.  
  char*  inFix;     //holds the infix expression 
  char* postFix;    //holds the postfix expression 
  symbols* vars;    //symbol table to be used in assignment 9. Pointer to
                    //an array of structs (see the very top of this file) 
}; 
