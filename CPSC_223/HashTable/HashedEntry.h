/**
 * @file HashedEntry.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-30-14
 *
 * HashedEntry class that holds employee information as a pointer.
 */

#ifndef HASHEDENTRY_H
#define HASHEDENTRY_H

#include "Entry.h"

class HashedEntry : public Entry
{
 private:

  //pointer to the next entry in the dictionary
  HashedEntry * nextPtr;

 public:

  /** Default constructor. */
  HashedEntry();

  /** Destructor. */
  ~HashedEntry();

  /** Constructor.
    * @pre None
    * @post a new HashedEntry object is made with parameter values.
    * @param newEntry is the new value for item.
    *        searchKey is the new value for searchKey. */
  HashedEntry(ItemType newEntry, KeyType sKey);

  /** Constructor.
    * @pre None
    * @post a new HashedEntry object is made with parameter values.
    * @param newEntry is the new value for item.
    *        searchKey is the new value for searchKey.
    *        nextEntryPtr is the new value for nextPtr. */
  HashedEntry(ItemType newEntry, KeyType sKey, HashedEntry *nextEntryPtr);

  /** Sets the nextPtr.
    * @pre HashedEntry exists.
    * @post nextPtr is now nextEntryPtr.
    * @param nextEntryPtr is the new value for nextPtr. */
  void setNext(HashedEntry *nextEntryPtr);

  /** Gets the nextPtr.
    * @pre HashedEntry exists.
    * @post nextPtr is returned.
    * @return nextPtr is the pointer to the next entry in the dictionary. */
  HashedEntry* getNext() const;

}; // end HashedEntry

#endif
