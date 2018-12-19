/**
 * @file Node.cpp
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 3-2-14
 *
 * A node that holds an item and a pointer to the next node.
 */

using namespace std;

#include "Node.h"

Node::Node()
{
 item = 0;
 next = 0;
}

Node::~Node()
{
 delete next;
 next = 0;
}

Node* Node::getNext()
{
 return next;
}

itemType Node::getItem()
{
 return item;
}

void Node::setNext(Node* nextIn)
{
 next = nextIn;
}

void Node::setItem(itemType newItem)
{
 item = newItem;
}
