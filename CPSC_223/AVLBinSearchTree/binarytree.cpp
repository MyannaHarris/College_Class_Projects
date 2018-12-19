/**
 * @file binarytree.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-14-14
 *
 * A binary tree implementation.
 */

#include <iostream>
#include "binarytree.h"
using namespace std;

// creates an empty binary tree
// post: object is an empty binary tree
// usage: BinaryTree zags;
BinaryTree::BinaryTree(): mroot(NULL)
{
}

BinaryTree::BinaryTree(const ItemType& rootItem){
   mroot = new Node(rootItem, NULL, NULL, 0, 0);                             
}

BinaryTree::BinaryTree(const ItemType& rootItem,BinaryTree& leftTree, BinaryTree& rightTree){
   mroot = new Node(rootItem, NULL, NULL, 0, 0); 
   mroot-> mleftptr=leftTree.mroot;
   if (leftTree.mroot -> leftHeight > leftTree.mroot -> rightHeight)
      mroot -> leftHeight = leftTree.mroot -> leftHeight + 1;
   else
      mroot -> leftHeight = leftTree.mroot -> rightHeight + 1;
   mroot-> mrightptr=rightTree.mroot;
   if (rightTree.mroot -> leftHeight > rightTree.mroot -> rightHeight)
      mroot -> rightHeight = rightTree.mroot -> leftHeight + 1;
   else
      mroot -> rightHeight = rightTree.mroot -> rightHeight + 1;
   leftTree.mroot=NULL;
   rightTree.mroot=NULL;
}

// creates a new binary tree that is a copy of an existing tree
// post: object is a copy of rhstree
// usage: BinaryTree zags (bulldog);
BinaryTree::BinaryTree(const BinaryTree& rhstree) 
{   
   copyTree (mroot, rhstree.mroot);
}

// releases the memory of a binary tree
// pre: object exists
// post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
BinaryTree:: ~BinaryTree()
{
  destroyTree(mroot);
  
}

// ******************** member functions ********************************************
// pre: binary tree object exists
// **********************************************************************************
// post: returns true if the object is empty; else returns false
// usage: if (tree.isEmpty())
bool BinaryTree::IsEmpty() const
{
   return mroot==NULL;
}



// pre: rhstree is an assigned tree.
// post: object is a copy of rhstree
// usage: atree = btree = ctree;
BinaryTree& BinaryTree::operator=(const BinaryTree& rhstree)
{
   if (this != &rhstree)
   {
      destroyTree(mroot);
      copyTree (mroot, rhstree.mroot);
   }
   return *this;
}  


void BinaryTree::PrettyDisplay() const
{
 inorderPretty(mroot, 1, true);
}

void BinaryTree::inorderPretty (Node* treep, int tabs, bool flag) const
{
   if (treep != NULL)
   {
      inorderPretty (treep -> mrightptr, tabs + 1, false);
      string spaces = "";
      for (int i = 0; i < tabs; i++)
          spaces += "\t";
      if (flag)
      {
       cout << "root -> " << treep -> mitem << " H: " << treep -> leftHeight << treep -> rightHeight << endl;
       flag = false;
      }
      else
         cout << spaces <<  treep -> mitem << " H: " << treep -> leftHeight << treep -> rightHeight << endl;
      inorderPretty (treep -> mleftptr, tabs + 1, false);
   }
}

// *************** on the following traversals
// uses: operator<< from citem
// post: prints the objects in the tree in order specified
// usage: tree.preorderTraverse();  
// similarly for the other traversals
// *****************************************************

void BinaryTree::preorderTraverse () const
{
   preorder(mroot);
}


void BinaryTree::inorderTraverse () const
{
   inorder(mroot);
}
   
void BinaryTree::postorderTraverse() const
{
   postorder(mroot);
}


// makes a tree for testing purposes. You may add a file parameter
// post: the tree is a full tree of height 2
// usage: mytree.MakeTree();

void BinaryTree:: MakeTree() throw (exception)
{
 mroot = new Node();
 mroot -> mitem = 5;
 mroot -> mleftptr = new Node(2, NULL, NULL, 0, 0);
 mroot -> leftHeight = 1;
 mroot -> mrightptr = new Node(7, NULL, NULL, 0, 0);
 mroot -> rightHeight = 1;
}


// helper functions for coding member functions
// Copies one binary tree to another
// pre: oldtreep points to the root of a binary tree
// post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
// usage: copyTree (newptr, oldptr);
void BinaryTree::copyTree (Node*& newtreep, Node* oldtreep) 
{
   newtreep = new Node();

   if (oldtreep == NULL)
      newtreep = NULL;
   else
   {
      newtreep -> mitem = oldtreep -> mitem;
      newtreep -> mleftptr = oldtreep -> mleftptr;
      newtreep -> mrightptr = oldtreep -> mrightptr;
      newtreep -> leftHeight = oldtreep -> leftHeight;
      newtreep -> rightHeight = oldtreep -> rightHeight;
      copyTree (newtreep -> mleftptr, oldtreep -> mleftptr);
      copyTree (newtreep -> mrightptr, oldtreep -> mrightptr);
   }
}

// Releases memory for a binary tree
// pre: treep points to the root of a binary tree
// post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
// usage: destroyTree (mroot);
void BinaryTree::destroyTree (Node*& treep)
{
   // do a postorder traversal
   if (treep != NULL)
   {
      destroyTree (treep -> mleftptr);
      destroyTree (treep -> mrightptr);
      delete treep;
      treep = NULL;
   }
}

// ********** recursive helpers for the traversals ****************
// pre: treep points to the root of a binary tree to be traversed
// post: prints the objects of the nodes on the screen in the
// specified order
// usage: preorder (mroot);   
//    similarly for the others
void BinaryTree::preorder (Node* treep) const
{
   if (treep != NULL)
   {
      cout <<  treep -> mitem << "  ";
      preorder (treep -> mleftptr);
      preorder (treep -> mrightptr);
   }
}

void BinaryTree::inorder (Node* treep) const
{
   if (treep != NULL)
   {
      inorder (treep -> mleftptr);
      cout <<  treep -> mitem << "  ";
      inorder (treep -> mrightptr);
   }
}

void BinaryTree::postorder (Node* treep) const
{
   if (treep != NULL)
   {
      postorder (treep -> mleftptr);
      postorder (treep -> mrightptr);
      cout <<  treep -> mitem << "  ";
   }
}

