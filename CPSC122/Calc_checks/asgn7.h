#ifndef STACK_H
#define STACK_H

typedef int itemType;

struct node
{
 itemType item;
 node* next;
};

class Stack 
{
 public:
   Stack();

   /*
   Pre: stackIn is pointer to an instance of Stack   
   Post: current stack is a copy of what stackIn points to. 
   */
   Stack(Stack* stackIn);
   ~Stack();

   /*
   Pre: an instance of Stack exists
   Post: returns true if stack is empty, false otherwise
   */
   bool isEmpty();

   /*
   Pre: an instance of Stack exists
   Post: returns the number of elements in the stack 
   */
   int getNum();
  
   /*
   Pre: an instance of Stack exists
   Post: item is pushed onto the stack 
   */
   void push(itemType item); 

   /*
   Pre: a non-empty instance of Stack exists. 
   Post: item at the top of the stack is removed and returned.
         An error message is diplayed and execution halts if 
         the stack is empty.  See SortIt(), below. 
   */
   itemType pop();

   /*
   Pre: a non-empty instance of Stack exists
   Post: item at the top of the stack is returned. Stack is unchanged. 
         An error message is diplayed and execution halts if 
         the stack is empty.  See SortIt(), below. 
   */
   itemType peek();

   /*
   Pre: a non-empty instance of Stack exists 
   Post: displays contents of the stack, top to bottom, on separate lines.
         An error message is diplayed and execution halts if 
         the stack is empty.  See SortIt(), below. 

   */
   void display();

   /*
   Pre: a non-empty instance of Stack exists. Parameter, 'order' indicates the 
        direction of the sort: 0 is ascending, 1 is descending. 
   Post: If parameter is valid, stack is sorted using selection sort. 
         If parameter is invalid, error is displayed and execution halts.
	 (To stop execution, use exit(1). Some systems will require that you
	 include <cstdlib>). 
   */
   void sortIt(int order); 
   
 private:
 
   //number of nodes in the list
   int size;

   //pointer to the top of the list
   node* top;

};
#endif
