/**
 * @file node.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-14-14
 *
 * A node.
 */


// ADT Binary Tree Node:
// Spec and implementation file
//    data object: a node for a dynamic binary tree
//    operations: two constructors
// Friend classes: BinaryTree
// Contract: the items for the node are defined in class ItemType
//           and ItemType has a GOOD copy constructor

//#include "itemtype.h"

#ifndef NODE_H
#define NODE_H
typedef int ItemType;
#include <cstddef>
class Node
{
private:

   // creates a node
   // post: the item of the node is empty and the kids are NULL
   // usage: newptr = new cnode();
   Node():mleftptr(NULL),mrightptr(NULL),leftHeight(0),rightHeight(0) {};

   // creates a node with a given item and kids
   // post: the item of the node is nodeItem, the kids are left and right
   // usage:aptr = new (nothrow) Node (thisone, NULL, NULL);
   // CAUTION: REQUIRES THAT COPY WORKS IN ItemType!!
   Node (const ItemType& nodeItem, 
          Node* left, Node* right,int lHeight,int rHeight):
          mitem (nodeItem), mleftptr (left), mrightptr (right), leftHeight(lHeight), rightHeight(rHeight) {}

   // implementation of data object
   //ItemType mitem;
   ItemType mitem;
   Node* mleftptr;
   Node* mrightptr;
   int leftHeight;
   int rightHeight;

   friend class BinaryTree;
   friend class AVLBinSearchTree;
};
#endif
