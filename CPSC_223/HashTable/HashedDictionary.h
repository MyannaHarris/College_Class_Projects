/**
 * @file HashedDictionary.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-30-14
 *
 * HashedDictionary class that uses a hash table to sort data.
 */

#ifndef HASHEDDICTIONARY_H
#define HASHEDDICTIONARY_H

#include "HashedEntry.h"

class HashedDictionary
{
 private:

  //pointer to start of hashtable
  HashedEntry * hashTable[101];

  //number of entries in hash table
  int itemCount;

  //number of occupied indices in the hash table
  int hashTableSize;

  //total # of indexes in hash table
  static const int DEFAULT_SIZE = 101;

  /** Hashes the keys.
    * @pre Hash table exists.
    * @post searchKey is hashed.
    * @param searchKey is a key to an item in the dictionary.
    * @return index that the key is hashed to. */
  int hashFunc(KeyType searchKey) const; // modulo: searchKey%DEFAULT_SIZE

 public:

  /** Default constructor. */
  HashedDictionary();

  /** Destructor. */
  ~HashedDictionary();

  /** Checks if the table is empty.
    * @pre None
    * @post if empty return true, else false.
    * @return true if empty, else false. */
  bool isEmpty() const;

  /** Gets the itemCount.
    * @pre Hash table exists.
    * @post itemCount is returned.
    * @return itemCount which is the number of items. */
  int getNumberOfItems() const;

  /** Adds an entry.
    * @pre Hash table exists.
    * @post entry is added.
    * @param searchKey is a key to an item.
             newItem is an item to be added.
    * @return true if entry is added. */
  bool add(const KeyType & searchKey, const ItemType & newItem);

  /** Removes an entry.
    * @pre Hash table exists.
    * @post entry is removed if it exists, else return false.
    * @param searchKey is a key to an item that is to be deleted.
    * @return true if entry is removed. */
  bool remove(const KeyType & searchKey);

  /** Empties the hash table.
    * @pre Hash table exists.
    * @post Hash table is empty. */
  void clear();

  /** Gets the item.
    * @pre Hash table exists.
    * @post item is returned if it exists.
    * @param searchKey is a key to an item.
    * @return item that is attached to searchKey. */
  ItemType getItem(const KeyType & searchKey) const;

  /** Searches for an entry.
    * @pre Hash table exists.
    * @post return true if entry exists, else return false.
    * @param searchKey is a key to an item that is to be found.
    * @return true if entry exists, else return false. */
  bool contains(const KeyType & searchKey) const;

};

#endif
