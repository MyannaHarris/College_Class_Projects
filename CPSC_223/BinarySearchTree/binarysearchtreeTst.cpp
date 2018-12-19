/**
 * @file binarysearchtreeTst->cpp
 * @author Myanna Harris (mharris5@ada->gonzaga->edu)
 * @date 3-25-14
 *
 * Tests the binary search tree->
 */

#include <iostream>
using namespace std;

#include "binarysearchtree.h"
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

 //test binary search tree
 cout << ""<< endl;
 cout << "binary search tree"<< endl;
 BinarySearchTree* bst = new BinarySearchTree();
 bst->Insert(5);
 bst->Insert(8);
 bst->Insert(6);
 bst->Insert(7);
 bst->Insert(10);
 bst->Insert(9);
 bst->Insert(11);
 bst->Insert(3);
 cout << "pretty display: "<< endl;
 bst->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 bst->inorderTraverse();
 cout << " "<< endl;

 cout << "insert 4: "<< endl;
 bst->Insert(4);
 cout << "pretty display: "<< endl;
 bst->PrettyDisplay();
 cout << " " << endl;
 cout << "inorder display: "<< endl;
 bst->inorderTraverse();
 cout << " "<< endl;

 cout << "try to insert 4 again: "<< endl;
 bst->Insert(4);
 cout << "pretty display: "<< endl;
 bst->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 bst->inorderTraverse();
 cout << " "<< endl;

 cout << "found 5: " << bst->Search(5) << endl;
 cout << "found 6: " << bst->Search(6) << endl;
 cout << "found 3: " << bst->Search(3) << endl;
 cout << "found 1: " << bst->Search(1) << endl;

 cout << "Find min: "<< bst->FindMin() << endl;
 cout << "Find max: "<< bst->FindMax() << endl;

 cout << "remove 0 (Not in tree): " << endl;
 bst->remove(0);
 cout << "pretty display: "<< endl;
 bst->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 bst->inorderTraverse();
 cout << " "<< endl;

 cout << "remove 4 (leaf): " << endl;
 bst->remove(4);
 cout << "pretty display: "<< endl;
 bst->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 bst->inorderTraverse();
 cout << " "<< endl;

 cout << "remove 6 (one child): " << endl;
 bst->remove(6);
 cout << "pretty display: "<< endl;
 bst->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 bst->inorderTraverse();
 cout << " "<< endl;

 cout << "remove 10 (two children): " << endl;
 bst->remove(10);
 cout << "pretty display: "<< endl;
 bst->PrettyDisplay();
 cout << " "<< endl;
 cout << "inorder display: "<< endl;
 bst->inorderTraverse();
 cout << " "<< endl;
}
