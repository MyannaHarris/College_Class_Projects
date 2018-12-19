/**
 * @file Node.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 3-2-14
 *
 * A node that holds an item and a pointer to the next node.
 */

#ifndef NODE_H
#define NODE_H

typedef int itemType;

class Node
{

 public:
 // constructors and destructor:
   /** Default constructor and destructor. */
   Node();
   ~Node();

   /** Gets pointer to next node.
     * @pre An instance of Node exists.
     * @post Return pointer.
     * @return Pointer to a node. */
   Node* getNext();

   /** Gets item.
     * @pre An instance of Node exists.
     * @post Return value.
     * @return Value of item. */
   itemType getItem();

   /** Sets next pointer.
     * @pre An instance of Node exists.
     * @post Sets next pointer.
     * @param nextIn is the new next pointer. */
   void setNext(Node* nextIn);

   /** Sets next pointer.
     * @pre An instance of Node exists.
     * @post Sets item value.
     * @param newItem is the new item value. */
   void setItem(itemType newItem);

 //List is a friend class
 friend class List;

 protected:
   //value stored in each node
   itemType item;

   //pointer to the next node in the list
   Node* next;
};
#endif
