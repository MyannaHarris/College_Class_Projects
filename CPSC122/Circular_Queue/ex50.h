#ifndef QUEUE_H 
#define QUEUE_H 

typedef int itemType;

class Queue 
{
 public:
  Queue(int sizeIn);
  ~Queue();

  /*
  pre: queue exists and is not full
  post: item is added to the end of the queue 
  */
  void enqueue(itemType item);

  /*
  pre: queue exists and is not empty 
  post: item is removed from the front of the queue and returned 
  */
  itemType dequeue();

  /*
  pre: queue exists and is not empty 
  post: item at the front of the queue is returned.  queue is not disturbed 
  */
  //itemType getFront();

  /*
  pre: queue exists
  post: returns true if queue is empty, false otherwise 
  */
  bool isEmpty(); 


  /*
  pre: queue exists
  post: returns true if queue is full, false otherwise 
  */
  //bool isFull();  

  /*
  pre: queue exists
  post: displays stack top to bottom, an item per line 
  */
  void display();
  
 private:
  int size;         //size of the queue 
  int numItems;     //number of items currently in the queue 
  int back;        //index of end of queue
  int front;       //index of front of queue
  itemType* stuff;  //a pointer to the array that holds the contents 
};
#endif
