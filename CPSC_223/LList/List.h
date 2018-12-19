/**
 * @file List.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 2-23-14
 *
 * A linked list using nodes.
 */

#ifndef LIST_H
#define LIST_H

#include"Node.h"

class List
{
 //positions of nodes start at 1
 public:
 // constructors and destructor:
   /** Default constructor. */
   List();
   /* Copy constructor.
    * @param newItem is the new item to be inserted. */
   List(List* listIn);
   ~List();

   /** Checks if list is empty.
     * @pre An instance of List exists.
     * @post Return true if list is empty, false otherwise. */
   bool isEmpty();

   /** Returns the length of the linked list.
     * @pre An instance of List exists.
     * @post Return the length of the list. */
   int getLength();

   /** Inserts newItem at pos in the linked list.
     * @pre An instance of List exists.
     * @post If pos < 1 or > (size + 1), return false, else 
     *       insert item at position pos and return true.
     * @param pos is the position starting at 1
     *        where the new Node is inserted.
     * @param newItem is the value in the new Node. */
   bool set(int pos, itemType newItem); 

   /** Gets the value of the Node at pos in the linked list.
     * @pre An instance of List exists.
     * @post If pos < 1 or > size + 1, return false, else 
     *       item will contain value at position pos and return true.
     * @param pos is the position starting at 1 of
     *        the Node whose value is returned.
     * @param item is the address to which the value is sent. */
   bool get(int pos, itemType& item);

   /** Deletes Node at pos in the linked list.
     * @pre An instance of List exists.
     * @post If pos < 1 or > size + 1, return false, else 
     *       delete Node at position pos and return true.
     * @param pos is the position starting at 1 of
     *        the Node to be deleted. */
   bool del(int pos);

   /** Displays the linked list.
     * @pre An instance of List exists.
     * @post Display value of each Node on separate lines. */
   void display();

   /** Inserts newItem at end of the linked list.
     * @pre An instance of List exists.
     * @post If list is empty or a new Node cannot be created, return false.
     *       Else store newItem at the tail of the list and return true.
     * @param newItem is the value in the new Node. */
   bool setT(itemType newItem); 

   /** Gets value at end of the linked list.
     * @pre An instance of List exists.
     * @post If list is empty return false, else item contains value at the 
     *       tail of the list and return true.
     * @param item is the address to which the value at
     *        the end of the list is sent. */
   bool getT(itemType& item); 

   /** Deletes last Node of the linked list.
     * @pre An instance of List exists.
     * @post If list is empty return false, else
     *       delete tail of list and return true. */
   bool delT(); 

   /** Sorts the linked list using selection sort.
     * @pre An instance of List exists.
     * @post List is sorted in ascending order using merge sort. */
   void sortIt();

   /** Iterates through linked list.
     * @pre An instance of List exists.
     * @post Return a pointer to the Node at pos.
     * @param pos is the position starting at 1 of
     *        the Node to be pointed at. */
   Node* ptrTo(int pos);
   
 private:
   /** Inserts newItem at head of the linked list.
     * @pre An instance of List exists.
     * @post If a new Node cannot be created, return false.
     *       Else store newItem at the head of the list and return true.
     * @param newItem is the value in the new Node. */
   bool set(itemType newItem); 

   //number of nodes in the list
   int size;

   //pointer to the head of the list
   Node* head;

   //pointer to the tail of the list
   Node* tail;

};
#endif
