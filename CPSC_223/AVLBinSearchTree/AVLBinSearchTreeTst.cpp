/**
 * @file AVLtreeTst.cpp
 * @author Myanna Harris (mharris5@ada->gonzaga->edu)
 * @date 4-14-14
 *
 * Tests the AVL tree
 */

#include <iostream>
using namespace std;

#include "AVLBinSearchTree.h"
#include "binarytree.h"

int main()
{
 //test binary tree
 cout << "binary tree"<< endl;
 cout << "bt1: "<< endl;
 BinaryTree* bt1 = new BinaryTree();

 cout << "IsEmpty: " << bt1->IsEmpty() << endl;
 cout << "Make tree "<< endl;
 bt1->MakeTree();
 cout << "IsEmpty: " << bt1->IsEmpty() << endl;

 cout << "pretty display: "<< endl;
 bt1->PrettyDisplay();
 cout << " "<< endl;

 cout << "preorder display: "<< endl;
 bt1->preorderTraverse();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 bt1->inorderTraverse();
 cout << " "<< endl;
 cout << "postorder display: "<< endl;
 bt1->postorderTraverse();
 cout << " "<< endl;

 BinaryTree* bt2 = new BinaryTree(9);
 cout << "preorder display bt2 (root: 9): "<< endl;
 bt2->preorderTraverse();
 cout << " "<< endl;

 BinaryTree* bt3 = new BinaryTree(8, *bt1, *bt2);
 cout << "preorder display bt3 (root: 8, left: bt1, right: bt2): "<< endl;
 bt3->preorderTraverse();
 cout << " "<< endl;

 BinaryTree* bt4 = new BinaryTree(*bt3);
 cout << "preorder display bt4 (copy of bt3): "<< endl;
 bt4->preorderTraverse();
 cout << " "<< endl;

 //test avl tree
 cout << ""<< endl;
 cout << "AVL binary search tree"<< endl;
 AVLBinSearchTree* avl = new AVLBinSearchTree();
 avl->Insert(5);
  cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 avl->Insert(8);
  cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 avl->Insert(6);
  cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 avl->Insert(7);
  cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 avl->Insert(10);
  cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 avl->Insert(9);
  cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 avl->Insert(11);
  cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 avl->Insert(3);
 cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 /*avl->Insert(12);
  cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;*/
 cout << "inorder display: "<< endl;
 avl->inorderTraverse();
 cout << " "<< endl;

 cout << "insert 4: "<< endl;
 avl->Insert(4);
 cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " " << endl;
 cout << "inorder display: "<< endl;
 avl->inorderTraverse();
 cout << " "<< endl;

 cout << "try to insert 4 again: "<< endl;
 avl->Insert(4);
 cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 avl->inorderTraverse();
 cout << " "<< endl;

 cout << "found 5: " << avl->Search(5) << endl;
 cout << "found 6: " << avl->Search(6) << endl;
 cout << "found 3: " << avl->Search(3) << endl;
 cout << "found 1: " << avl->Search(1) << endl;

 cout << "Find min: "<< avl->FindMin() << endl;
 cout << "Find max: "<< avl->FindMax() << endl;

 cout << "remove 0 (Not in tree): " << endl;
 avl->remove(0);
 cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 avl->inorderTraverse();
 cout << " "<< endl;

 cout << "remove 3 (leaf): " << endl;
 avl->remove(3);
 cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 avl->inorderTraverse();
 cout << " "<< endl;

 cout << "remove 4 (one child): " << endl;
 avl->remove(4);
 cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 avl->inorderTraverse();
 cout << " "<< endl;

 cout << "remove 10 (two children): " << endl;
 avl->remove(10);
 cout << "pretty display: "<< endl;
 avl->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 avl->inorderTraverse();
 cout << " "<< endl;
}
