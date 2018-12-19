/**
 * @file HashedEntry.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-30-14
 *
 * HashedEntry class that holds employee information as pointer.
 */

using namespace std;

#include "HashedEntry.h"

HashedEntry::HashedEntry()
{
 nextPtr = NULL;
}

HashedEntry::~HashedEntry()
{
 delete nextPtr;
 nextPtr = NULL;
}

HashedEntry::HashedEntry(ItemType newEntry, KeyType sKey)
{
 item = newEntry;
 searchKey = sKey;
 nextPtr = NULL;
}

HashedEntry::HashedEntry(ItemType newEntry, KeyType sKey, HashedEntry *nextEntryPtr)
{
 item = newEntry;
 searchKey = sKey;
 nextPtr = nextEntryPtr;
}

void HashedEntry::setNext(HashedEntry *nextEntryPtr)
{
 nextPtr = nextEntryPtr;
}

HashedEntry* HashedEntry::getNext() const
{
 return nextPtr;
}
