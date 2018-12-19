/**
 * @file Node.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 2-23-14
 *
 * A node that holds an item and a pointer to the next node.
 */

#ifndef NODE_H
#define NODE_H

typedef int itemType;

class Node
{
 // constructors and destructor:
   /** Default constructor. */
   Node();

 //List is a friend class
 friend class List;

 protected:
   //value stored in each node
   itemType item;

   //pointer to the next node in the list
   Node* next;
};
#endif
