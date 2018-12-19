/**
 * @file HashedDictionary.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-30-14
 *
 * HashedDictionary class that uses a hash table to sort data.
 */

#include <iostream>
using namespace std;

#include "HashedDictionary.h"

HashedDictionary::HashedDictionary()
{
 itemCount = 0;
 hashTableSize = 0;
}

int HashedDictionary::hashFunc(KeyType searchKey) const
{
 // modulo: searchKey%DEFAULT_SIZE
 return (searchKey % DEFAULT_SIZE);
}

HashedDictionary::~HashedDictionary()
{
 clear();
}

bool HashedDictionary::isEmpty() const
{
 if (itemCount == 0)
    return true;
 else
    return false;
}

int HashedDictionary::getNumberOfItems() const
{
 return itemCount;
}

bool HashedDictionary::add(const KeyType & searchKey, const ItemType & newItem)
{
 HashedEntry* hEntry = new HashedEntry(newItem, searchKey);
 int hashNum = hashFunc(searchKey);

 if (hashTable[hashNum] == NULL)
 {
  hashTable[hashNum] = hEntry;
  itemCount++;
  hashTableSize++;
  return true;
 }
 else
 {
  hEntry -> setNext(hashTable[hashNum]);
  hashTable[hashNum] = hEntry;
  itemCount++;
  return true;
 }
}

bool HashedDictionary::remove(const KeyType & searchKey)
{
 if (contains(searchKey))
 {
  int hashNum = hashFunc(searchKey);
  HashedEntry* tempPtr = hashTable[hashNum];

  if (tempPtr -> getKey() == searchKey)
  {
   delete hashTable[hashNum];
   hashTable[hashNum] = tempPtr -> getNext();
  }
  else
  {
   while (tempPtr -> getNext() != NULL)
   {
    if (tempPtr -> getNext() -> getKey() == searchKey)
    {
     HashedEntry* tempPtr2 = tempPtr -> getNext();
     tempPtr -> setNext(tempPtr2 -> getNext());

     delete tempPtr2;
     tempPtr2 = NULL;
    }
    else
       tempPtr = tempPtr -> getNext();
   }
  }

  itemCount--;
  if (hashTable[hashNum] == NULL)
     hashTableSize--;
  return true;
 }
 else
    return false;
}

void HashedDictionary::clear()
{
 int index = 0;
 while (hashTableSize > 0)
 {
  while (hashTable[index] != NULL)
        remove(hashTable[index] -> getKey());

  index++;
 }

 itemCount = 0;
}

ItemType HashedDictionary::getItem(const KeyType & searchKey) const
{
 if (contains(searchKey))
 {
  int hashNum = hashFunc(searchKey);
  HashedEntry* tempPtr = hashTable[hashNum];
  while (tempPtr != NULL)
  {
   if (tempPtr -> getKey() == searchKey)
      return tempPtr -> getItem();
   else
      tempPtr = tempPtr -> getNext();
  }
 }
 else
    return "Item not found";
}

bool HashedDictionary::contains(const KeyType & searchKey) const
{
 int hashNum = hashFunc(searchKey);
 if (hashTable[hashNum] != NULL)
 {
  HashedEntry* tempPtr = hashTable[hashNum];
  bool found = false;
  while (tempPtr != NULL && !found)
  {
   if (tempPtr -> getKey() == searchKey)
      return true;
   else
      tempPtr = tempPtr -> getNext();
  }
  return false;
 }
 else
    return false;
}
