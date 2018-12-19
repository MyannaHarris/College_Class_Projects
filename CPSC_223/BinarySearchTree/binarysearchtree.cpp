/**
 * @file binarysearchtree.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 3-25-14
 *
 * A binary search tree implementation.
 */

#include <iostream>
#include "binarysearchtree.h"
using namespace std;

//binarysearchtree.cpp

//@creates a new binary search tree
//@post: an empty binary search tree object exists
//@usage: BinarySearchTree bst;
BinarySearchTree:: BinarySearchTree(): BinaryTree()
{
}

//@releases memory for a binary search tree
//@pre: binary search tree object exists
//@post: binary search tree object does not exist
//@usage: automatically done at end of scope
BinarySearchTree::~BinarySearchTree()
{
}

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

//@searches for a key in a binary search tree object and
//    retrieves the corresponding item
//@pre: key has been assigned.
//@post: theItem contains tkey with rest of the item if
//    tkey is found in the binary search tree object
//    else an exception is thrown
//@usage: bst.Retrieve (abbrev, meaning);
bool BinarySearchTree:: Search (const ItemType& theItem) const
{
   return lookup (mroot, theItem);
}

//@inserts a new item into the binary search tree
//@pre: newItem has been assigned
//@post: if the newItem's key is not already in the tree
//       and there is memory available
//         then the newItem is added to the tree
//       else an exception is thrown
//@usage: you do
void BinarySearchTree:: Insert (const ItemType& newItem) 
{
   insertItem (mroot, newItem);
}

//@recursively searches (modeling on binary search) for a key
//@pre: treeptr is assigned. newItem is assigned.
//@post: searches for tkey in the tree with treeptr's root.
//    If tkey is found, theItem is the key together with the other
//    parts of the item. Else an exception is thrown.
//@usage: retrieveItem (mroot, key, rest);
bool BinarySearchTree:: lookup (Node * treeptr, const ItemType& theItem) const
{
   if (treeptr == NULL){
      cout<<"BinarySearchTree in lookup: key has not been found! "<<endl;
      return false;}
   else if (theItem == (treeptr-> mitem))
      return true;
   else if (theItem < (treeptr -> mitem))
      return lookup (treeptr -> mleftptr, theItem);
   else
      return lookup (treeptr -> mrightptr, theItem);
}
   

// write the documentation
void BinarySearchTree:: insertItem (Node *& treeptr, const ItemType& newItem)
{
     if (treeptr == NULL)
       treeptr = new Node(newItem, NULL, NULL);
     if (!(newItem == treeptr -> mitem))
     {
      if (newItem < treeptr -> mitem)
        insertItem (treeptr -> mleftptr, newItem);
      
      else
        insertItem (treeptr -> mrightptr, newItem);
     }
}

void BinarySearchTree::remove (const ItemType& theItem)
{
 Node* treeptr = findItem(mroot, theItem);

 if (treeptr != NULL) 
 {
  removeItem(treeptr, theItem, NULL);
 }
}

ItemType BinarySearchTree::FindMin() const
{
 return lookforMin(mroot) -> mitem;
}

ItemType BinarySearchTree::FindMax() const
{
 return lookforMax(mroot) -> mitem;
}

void BinarySearchTree::removeItem (Node *& treeptr, const ItemType& theItem, Node * treeItem)
{
 Node* itemNode;
 bool isRightNode = false;

 if (treeItem != NULL)
    itemNode = treeItem;
 else if (theItem == treeptr -> mitem)
    itemNode = treeptr;
 else if (treeptr -> mleftptr != NULL && theItem == (treeptr -> mleftptr -> mitem))
    itemNode = treeptr -> mleftptr;
 else if (treeptr -> mrightptr != NULL && theItem == (treeptr -> mrightptr -> mitem))
 {
  isRightNode = true;
  itemNode = treeptr -> mrightptr;
 }

 if (itemNode -> mleftptr == NULL && itemNode -> mrightptr == NULL)
 {
  if (itemNode != treeptr)
  {
   if (isRightNode || treeptr -> mrightptr == treeItem)
      treeptr -> mrightptr = NULL;
   else
      treeptr -> mleftptr = NULL;
  }
  delete itemNode;
  itemNode = NULL;
 }
 else if ((itemNode -> mleftptr != NULL && itemNode -> mrightptr == NULL)||(itemNode -> mleftptr == NULL && itemNode -> mrightptr != NULL))
 {
  Node* temp;
  if (itemNode -> mleftptr != NULL)
     temp = itemNode -> mleftptr;
  else
     temp = itemNode -> mrightptr;

  if (isRightNode || treeptr -> mrightptr == treeItem)
      treeptr -> mrightptr = temp;
  else
      treeptr -> mleftptr = temp;

  delete itemNode;
  itemNode = NULL;
 }
 else
 {
  Node* next = itemNode -> mrightptr;
  while (next -> mleftptr != NULL)
       next = next -> mleftptr;
  Node* treeptrTemp = findItem(mroot, next -> mitem);
  itemNode -> mitem = next -> mitem;
  removeItem(treeptrTemp, next -> mitem, next);
 }
}

Node * BinarySearchTree::findItem(Node * treeptr, const ItemType& theItem) const
{
   if (treeptr == NULL || (theItem < (treeptr -> mitem) && treeptr -> mleftptr == NULL) || (theItem > (treeptr -> mitem) && treeptr -> mrightptr == NULL)){
      cout<<"BinarySearchTree in findItem: key has not been found! "<<endl;
      return NULL;}
   else if (theItem == (treeptr -> mitem))
      return treeptr;
   else if ((treeptr -> mleftptr != NULL && theItem == (treeptr -> mleftptr -> mitem))||(treeptr -> mrightptr != NULL && theItem == (treeptr-> mrightptr -> mitem)))
      return treeptr;
   else if (treeptr -> mleftptr != NULL && theItem < (treeptr -> mitem))
      return findItem (treeptr -> mleftptr, theItem);
   else if (treeptr -> mrightptr != NULL && theItem > (treeptr -> mitem))
      return findItem (treeptr -> mrightptr, theItem);
}

Node * BinarySearchTree::lookforMin(Node * treeptr) const
{
 while (treeptr -> mleftptr != NULL)
       treeptr = treeptr -> mleftptr;

 return treeptr;
}

Node * BinarySearchTree::lookforMax(Node * treeptr) const
{
 while (treeptr -> mrightptr != NULL)
       treeptr = treeptr -> mrightptr;

 return treeptr;
}
