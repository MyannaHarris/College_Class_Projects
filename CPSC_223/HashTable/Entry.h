/**
 * @file Entry.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-30-14
 *
 * Entry class that holds employee information.
 */

#ifndef ENTRY_H
#define ENTRY_H

#include<string>

using namespace std;

typedef string ItemType;
typedef int KeyType;

class Entry
{
 protected:

  //item held in dictionary
  ItemType item;

  //key to search for item by
  KeyType searchKey;

  /** Sets the searchKey.
    * @pre Entry exists.
    * @post searchKey is now sKey.
    * @param sKey is the new value for searchKey. */
  void setKey (const KeyType & sKey);

 public:

  /** Default constructor. */
  Entry();

  Entry(ItemType & newEntry, KeyType & Key);

  /** Destructor. */
  ~Entry();

  /** Gets the item.
    * @pre Entry exists.
    * @post item is returned.
    * @return item is the value held in the dictionary. */
  ItemType getItem () const;

  /** Gets the searchKey.
    * @pre Entry exists.
    * @post searchKey is returned.
    * @return searchKey is the value used to search in the dictionary. */
  KeyType getKey () const;

  /** Sets the item.
    * @pre Entry exists.
    * @post newEntry is now item.
    * @param newEntry is the new value for item. */
  void setItem (const ItemType & newEntry);

};

#endif
