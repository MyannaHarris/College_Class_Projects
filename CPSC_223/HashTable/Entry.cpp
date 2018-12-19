/**
 * @file Entry.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-30-14
 *
 * Entry class that holds employee information.
 */

using namespace std;

#include "Entry.h"

Entry::Entry()
{
 item = "";
 searchKey = 0;
}

void Entry::setKey (const KeyType & sKey)
{
 searchKey = sKey;
}

Entry::Entry(ItemType & newEntry, KeyType & Key)
{
 item = newEntry;
 searchKey = Key;
}

Entry::~Entry()
{
}

ItemType Entry::getItem () const
{
 return item;
}

KeyType Entry::getKey () const
{
 return searchKey;
}

void Entry::setItem (const ItemType & newEntry)
{
 item = newEntry;
}
