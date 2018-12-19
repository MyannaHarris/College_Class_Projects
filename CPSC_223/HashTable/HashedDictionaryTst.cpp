/**
 * @file HashedDictionary.h
 * @author Myanna Harris (mharris5@ada.gonzaga.edu)
 * @date 4-30-14
 *
 * Tests HashedDictionary class that uses a hash table to sort data.
 */

#include <iostream>
using namespace std;

#include"HashedDictionary.h"

int main()
{
 HashedDictionary* hd = new HashedDictionary();

 //check isEmpty
 cout << "isEmpty : " << hd->isEmpty() <<endl;

 //add
 cout << "Add" << endl;
 cout << "add : 27, Jason Keller" << endl;
 hd->add(27, "Jason Keller");
 cout << "add : 135, Nick Duncan" << endl;
 hd->add(135, "Nick Duncan");
 cout << "add : 1021, Mike Black" << endl;
 hd->add(1021, "Mike Black");
 cout << "add : 101, Dan Harvey" << endl;
 hd->add(101, "Dan Harvey");
 cout << "add : 202, Jacque Lee" << endl;
 hd->add(202, "Jacque Lee");

 //contains
 cout << "contains 27 : " << hd-> contains(27) << endl;
 cout << "contains 107 : " << hd-> contains(107) << endl;

 //get
 cout << "get 27 : " << hd-> getItem(27) << endl;
 cout << "get 101 : " << hd-> getItem(101) << endl;

 //number of items
 cout << "# of items : " << hd-> getNumberOfItems() << endl;

 //remove
 cout << "get 135 : " << hd-> getItem(135) << endl;
 cout << "contains 135 : " << hd-> contains(135) << endl;
 cout << "remove 135" << endl;
 hd-> remove(135);
 cout << "contains 135 : " << hd-> contains(135) << endl;

 cout << "get 202 : " << hd-> getItem(202) << endl;
 cout << "contains 202 : " << hd-> contains(202) << endl;
 cout << "remove 202" << endl;
 hd-> remove(202);
 cout << "contains 202 : " << hd-> contains(202) << endl;
 cout << "get 202 : " << hd-> getItem(202) << endl;

 //clear
 cout << "clear table" << endl;
 hd-> clear();
 cout << "# of items : " << hd-> getNumberOfItems() << endl;
}
