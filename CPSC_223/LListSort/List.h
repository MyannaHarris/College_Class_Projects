/**
 * @file List.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 3-2-14
 *
 * A linked list using nodes.
 */

#ifndef LIST_H
#define LIST_H

#include "Node.h"

//positions of nodes start at 1
class List
{

 public:
 // constructors and destructor:
   /** Default constructor. */
   List();
   /* Copy constructor.
    * @param newItem is the new item to be inserted. */
   List(const List * listIn);
   ~List();

   /** Checks if list is empty.
     * @pre An instance of List exists.
     * @post Return true if list is empty, false otherwise. */
   bool isEmpty() const;

   /** Returns the length of the linked list.
     * @pre An instance of List exists.
     * @post Return the length of the list. */
   int getSize() const; 

   /** Inserts newItem at pos in the linked list.
     * @pre An instance of List exists.
     * @post Insert item at position.
     * @param pos is the position starting at 1
     *        where the new Node is inserted.
     * @param newItem is the value in the new Node. */
   void insert(int pos, const itemType & newItem);

   /** Deletes Node at pos in the linked list.
     * @pre An instance of List exists.
     * @post Delete node at pos.
     * @param pos is the position starting at 1 of
     *        the Node to be deleted. */
   void remove(int pos);

   /** Displays the linked list.
     * @pre An instance of List exists.
     * @post Display value of each Node on separate lines. */
   void display();

   /** Sorts the linked list using merge sort.
     * @pre An instance of List exists.
     * @post List is sorted in ascending order using merge sort. */
   void sort_mergesort();

   /** Overloaded operator as friend. Inputs node item.
     * @pre None.
     * @post The item is added to head of list.
     * @param in is an object of istream (the input stream).
     * @param list is the list that is to have the item entered into.  */
   friend istream& operator >> (istream& in, List* list);

   /** Return pointer to head.
     * @pre An instance of List exists.
     * @post Return a pointer to the Node at head.
     * @return Pointer to head. */
   Node* getHead();

   /** Set head pointer to newNode.
     * @pre An instance of List exists.
     * @post Set head pointer to newHead.
     * @param newHead is the new Node to become head. */
   Node* setHead(Node* newHead);

 private:
   //number of nodes in the list
   int size;

   //pointer to the head of the list
   Node* head;

   /** Iterates through linked list.
     * @pre An instance of List exists.
     * @post Return a pointer to the Node at pos.
     * @param pos is the position starting at 1 of
     *        the Node to be pointed at. */
   Node* ptrTo(int pos);

   /** Sorts the linked list using merge sort.
     * @pre An instance of List exists.
     * @post List is sorted in ascending order using merge sort.
     * @param lhead is the node at the head of the list to be sorted.
     * @param lsize is the length of the list to be sorted. */
   Node* mergesort(Node* head, int size);

   /** Merges two lists.
     * @pre Two lists exist.
     * @post Lists are merged in sorted order.
     * @param lhead1 is the node at the head of the list1 to be merged.
     * @param lhead2 is the node at the head of the list2 to be merged. */
   Node* merge(Node* head1, Node* head2);
};
#endif
