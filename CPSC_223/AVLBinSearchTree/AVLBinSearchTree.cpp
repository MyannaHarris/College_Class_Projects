/**
 * @file AVLBinSearchTree.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-14-14
 *
 * An AVL tree implementation.
 */

#include <iostream>
#include<cmath>
#include "AVLBinSearchTree.h"
using namespace std;

//binarysearchtree.cpp

//@creates a new binary search tree
//@post: an empty binary search tree object exists
//@usage: AVLBinSearchTree avl;
AVLBinSearchTree:: AVLBinSearchTree(): BinaryTree()
{
}

//@releases memory for a binary search tree
//@pre: binary search tree object exists
//@post: binary search tree object does not exist
//@usage: automatically done at end of scope
AVLBinSearchTree::~AVLBinSearchTree()
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
//@usage: avl.Retrieve (abbrev, meaning);
bool AVLBinSearchTree:: Search (const ItemType& theItem) const
{
   return lookup (mroot, theItem);
}

//@inserts a new item into the binary search tree
//@pre: newItem has been assigned
//@post: if the newItem's key is not already in the tree
//       and there is memory available
//         then the newItem is added to the tree
//       else an exception is thrown
//@usage: insert (item);
void AVLBinSearchTree:: Insert (const ItemType& newItem) 
{
  if (mroot == NULL)
  {
   mroot = new Node(newItem, NULL, NULL, 0, 0);
  }
  else
  {
   //keeps track of path to inserted node
   //1 - left
   //2 - right
   int height;
   if (mroot -> leftHeight > mroot -> rightHeight)
      height = mroot -> leftHeight + 1;
   else
      height = mroot -> rightHeight + 1;
   int* takenPath = new int[height];
   insertItem (mroot, newItem, takenPath, 0);
   fixHeight(mroot, takenPath, 0);
   balance(mroot);
   checkHeight(mroot, newItem, 0);
  }
}

//@recursively searches (modeling on binary search) for a key
//@pre: treeptr is assigned. newItem is assigned.
//@post: searches for tkey in the tree with treeptr's root.
//    If tkey is found, theItem is the key together with the other
//    parts of the item. Else an exception is thrown.
//@usage: lookup (mroot, key);
bool AVLBinSearchTree:: lookup (Node * treeptr, const ItemType& theItem) const
{
   if (treeptr == NULL){
      cout<<"AVLBinSearchTree in lookup: key has not been found! "<<endl;
      return false;}
   else if (theItem == (treeptr-> mitem))
      return true;
   else if (theItem < (treeptr -> mitem))
      return lookup (treeptr -> mleftptr, theItem);
   else
      return lookup (treeptr -> mrightptr, theItem);
}
   

//@recursively finds a spot to insert a new node
//@pre: treeptr is assigned. newItem is assigned.
//@post: searches for the spot to insert at.
//    The new node is made and inserted.
//@usage: insertItem (mroot, item);
void AVLBinSearchTree:: insertItem (Node *& treeptr, const ItemType& newItem, int* takenPath, int index)
{
 if (treeptr == NULL)
    treeptr = new Node(newItem, NULL, NULL, 0, 0);

 if (!(newItem == treeptr -> mitem))
 {
  if (newItem < treeptr -> mitem)
  {
   takenPath[index] = 1;
   insertItem (treeptr -> mleftptr, newItem, takenPath, index + 1);
  }
  else
  {
   takenPath[index] = 2;
   insertItem (treeptr -> mrightptr, newItem, takenPath, index + 1);
  }
 }
}

int AVLBinSearchTree::fixHeight(Node* treeptr, int* takenPath, int index)
{
 int turn = takenPath[index];
  if (turn == 1)
  {
   return treeptr -> leftHeight = fixHeight(treeptr -> mleftptr, takenPath, index + 1) + 1;
  }
  else if (turn == 2)
  {
   return treeptr -> rightHeight = fixHeight(treeptr -> mrightptr, takenPath, index + 1) + 1;
  }
  else
     return 0;
}

void AVLBinSearchTree::checkHeight(Node* treeptr, const ItemType& theItem, int method)
{
 Node* tempPtr = NULL;

 if (method == 0)
    tempPtr = findItem(mroot, theItem);
 else
    tempPtr = treeptr;

 while (tempPtr != NULL)
 {
  if (tempPtr -> mleftptr != NULL && tempPtr -> mleftptr -> leftHeight > tempPtr -> mleftptr -> rightHeight)
     tempPtr -> leftHeight = tempPtr -> mleftptr -> leftHeight + 1;
  else if (tempPtr -> mleftptr != NULL)
     tempPtr -> leftHeight = tempPtr -> mleftptr -> rightHeight + 1;
  else
     tempPtr -> leftHeight = 0;

  if (tempPtr -> mrightptr != NULL && tempPtr -> mrightptr -> leftHeight > tempPtr -> mrightptr -> rightHeight)
     tempPtr -> rightHeight = tempPtr -> mrightptr -> leftHeight + 1;
  else if (tempPtr -> mrightptr != NULL)
     tempPtr -> rightHeight = tempPtr -> mrightptr -> rightHeight + 1;
  else
     tempPtr -> rightHeight = 0;

  if (tempPtr != mroot)
     tempPtr = findItem(mroot, tempPtr -> mitem);
  else
     tempPtr = NULL;
 }
}

void AVLBinSearchTree::balance(Node* treeptr)
{
 Node* unbalNode = checkBalance(treeptr);
 Node* prevNode = NULL;
 bool leftFlag = false;

 if (unbalNode != NULL)
 {
  prevNode = findItem(mroot, unbalNode -> mitem);
  if (unbalNode == prevNode -> mleftptr)
     leftFlag = true;
 }

 while (unbalNode != NULL)
 {
  if (unbalNode -> leftHeight - unbalNode -> rightHeight > 1)
  {
   if (unbalNode -> mleftptr != NULL && unbalNode -> mleftptr -> rightHeight > unbalNode -> mleftptr -> leftHeight)
      treeptr = dblRotateWithLeftChild(unbalNode);
   else
      treeptr = rotateWithLeftChild(unbalNode);
  }
  else if (unbalNode -> rightHeight - unbalNode -> leftHeight > 1)
  {
   if (unbalNode -> mrightptr != NULL && unbalNode -> mrightptr -> leftHeight > unbalNode -> mrightptr -> rightHeight)
      treeptr = dblRotateWithRightChild(unbalNode);
   else
      treeptr = rotateWithRightChild(unbalNode);
  }

   if (prevNode == mroot)
      mroot = treeptr;
   else if (leftFlag)
   {
    prevNode -> mleftptr = treeptr;
    if (treeptr -> leftHeight > treeptr -> rightHeight)
       prevNode -> leftHeight = treeptr -> leftHeight + 1;
    else
       prevNode -> leftHeight = treeptr -> rightHeight + 1;
   }
   else
   {
    prevNode -> mrightptr = treeptr;
    if (treeptr -> leftHeight > treeptr -> rightHeight)
       prevNode -> rightHeight = treeptr -> leftHeight + 1;
    else
       prevNode -> rightHeight = treeptr -> rightHeight + 1;
   }

  unbalNode = checkBalance(treeptr);
 }
}

Node* AVLBinSearchTree::checkBalance(Node* treeptr)
{
 if (treeptr -> leftHeight - treeptr -> rightHeight > 1)
 {
  if (abs(treeptr -> mleftptr -> leftHeight - treeptr -> mleftptr -> rightHeight) > 1)
     return checkBalance(treeptr -> mleftptr);
  else
     return treeptr;
 }
 else if (treeptr -> rightHeight - treeptr -> leftHeight > 1)
 {
  if (abs(treeptr -> mrightptr -> leftHeight - treeptr -> mrightptr -> rightHeight) > 1)
     return checkBalance(treeptr -> mrightptr);
  else
     return treeptr;
 }
 else
    return NULL;
}

Node* AVLBinSearchTree::rotateWithLeftChild (Node* k2)
{
 Node* k1 = k2 -> mleftptr;
 k2 -> mleftptr = k1 -> mrightptr;
 k2 -> leftHeight = k1 -> rightHeight;
 k1 -> mrightptr = k2;
 if (k2 -> leftHeight > k2 -> rightHeight)
    k1 -> rightHeight = k2 -> leftHeight + 1;
 else
    k1 -> rightHeight = k2 -> rightHeight + 1;
 return k1;
}

Node* AVLBinSearchTree::rotateWithRightChild (Node* k1)
{
 Node* k2 = k1 -> mrightptr;
 k1 -> mrightptr = k2 -> mleftptr;
 k1 -> rightHeight = k2 -> leftHeight;
 k2 -> mleftptr = k1;
 if (k1 -> leftHeight > k1 -> rightHeight)
    k2 -> leftHeight = k1 -> leftHeight + 1;
 else
    k2 -> leftHeight = k1 -> rightHeight + 1;
 return k2;
}

Node* AVLBinSearchTree::dblRotateWithLeftChild (Node* k3)
{
 k3 -> mleftptr = rotateWithRightChild(k3 -> mleftptr);
 return rotateWithLeftChild(k3);
}

Node* AVLBinSearchTree::dblRotateWithRightChild (Node* k3)
{
 k3 -> mrightptr = rotateWithLeftChild(k3 -> mrightptr);
 return rotateWithRightChild(k3);
}

void AVLBinSearchTree::remove (const ItemType& theItem)
{
 Node* treeptr = findItem(mroot, theItem);

 if (treeptr != NULL) 
 {
  //keeps track of path to inserted node
  //1 - left
  //2 - right
  int height;
  if (mroot -> leftHeight > mroot -> rightHeight)
     height = mroot -> leftHeight + 1;
  else
     height = mroot -> rightHeight + 1;
  int* takenPath = new int[height];
  findDelPath(mroot, theItem, takenPath, 0);
  removeItem (treeptr, theItem, NULL);
  fixHeight(mroot, takenPath, 0);
  balance(mroot);
  checkHeight(treeptr, treeptr -> mitem, 1);
 }
}

ItemType AVLBinSearchTree::FindMin() const
{
 return lookforMin(mroot) -> mitem;
}

ItemType AVLBinSearchTree::FindMax() const
{
 return lookforMax(mroot) -> mitem;
}

void AVLBinSearchTree::findDelPath(Node *& treeptr, const ItemType& theItem, int* takenPath, int index)
{
 if (!(theItem == treeptr -> mitem))
 {
  if (theItem < treeptr -> mitem)
  {
   takenPath[index] = 1;
   findDelPath (treeptr -> mleftptr, theItem, takenPath, index + 1);
  }
  else
  {
   takenPath[index] = 2;
   findDelPath (treeptr -> mrightptr, theItem, takenPath, index + 1);
  }
 }
 else
 {
  int i = index;
  Node* next = treeptr;
  if (next -> mrightptr != NULL)
  {
   i++;
   takenPath[i] = 2;
   next = next -> mrightptr;
   while (next -> mleftptr != NULL)
   {
    i++;
    takenPath[i] = 1;
    next = next -> mleftptr;
   }
   takenPath[i] = 0;
  }
  else
  {
   takenPath[i] = 0;
  }
 }
}

void AVLBinSearchTree::removeItem (Node *& treeptr, const ItemType& theItem, Node * treeItem)
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
   {
    treeptr -> mrightptr = NULL;
    treeptr -> rightHeight = 0;
   }
   else
   {
    treeptr -> mleftptr = NULL;
    treeptr -> leftHeight = 0;
   }
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
  {
   treeptr -> mrightptr = temp;
   if (temp -> leftHeight > temp -> rightHeight)
      treeptr -> rightHeight = temp -> leftHeight + 1;
   else
      treeptr -> rightHeight = temp -> rightHeight + 1;
  }
  else
  {
   treeptr -> mleftptr = temp;
   if (temp -> leftHeight > temp -> rightHeight)
      treeptr -> leftHeight = temp -> leftHeight + 1;
   else
      treeptr -> leftHeight = temp -> rightHeight + 1;
  }

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

Node * AVLBinSearchTree::findItem(Node * treeptr, const ItemType& theItem) const
{
   if (treeptr == NULL || (theItem < (treeptr -> mitem) && treeptr -> mleftptr == NULL) || (theItem > (treeptr -> mitem) && treeptr -> mrightptr == NULL)){
      cout<<"AVLBinSearchTree in findItem: key has not been found! "<<endl;
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

Node * AVLBinSearchTree::lookforMin(Node * treeptr) const
{
 while (treeptr -> mleftptr != NULL)
       treeptr = treeptr -> mleftptr;

 return treeptr;
}

Node * AVLBinSearchTree::lookforMax(Node * treeptr) const
{
 while (treeptr -> mrightptr != NULL)
       treeptr = treeptr -> mrightptr;

 return treeptr;
}
