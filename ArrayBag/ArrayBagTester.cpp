//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

void displayBag(ArrayBag<std::string>& bag)
{
   cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << endl;
   std::vector<std::string> bagItems = bag.toVector();
   
   int numberOfEntries = (int)bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
   cout << endl << endl;
}  // end displayBag

void bagTester(ArrayBag<std::string>& bag)
{
   cout << "isEmpty: returns " << bag.isEmpty()
        << "; should be 1 (true)" << endl;
   displayBag(bag);
   
   std::string items[] = {"one", "two", "three", "four", "five", "one"};
   cout << "Add 6 items to the bag: " << endl;
   for (int i = 0; i < 6; i++)
   {
      bag.add(items[i]);
   }  // end for
   
   displayBag(bag);
   
   cout << "isEmpty: returns " << bag.isEmpty()
        << "; should be 0 (false)" << endl;
   
   cout << "getCurrentSize: returns " << bag.getCurrentSize()
        << "; should be 6" << endl;
   
   cout << "Try to add another entry: add(\"extra\") returns "
        << bag.add("extra") << endl;
} // end bagTester

int main()
{
   ArrayBag<std::string> bag;
   cout << "Testing the Array-Based Bag:" << endl;
   cout << "The initial bag is empty." << endl;
   bagTester(bag);
   cout << "All done!" << endl;

   cout << "contains(\"three\"): returns " << bag.contains("three")
        << "; should be 1 (true)" << endl;
   cout << "contains(\"ten\"): returns " << bag.contains("ten")
        << "; should be 0 (false)" << endl;
   cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 2" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" << endl;
   cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 1" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 0 (false)" << endl;
   cout << endl;
   
   displayBag(bag);
   
   cout << "After clearing the bag, ";
   bag.clear();
   cout << "isEmpty: returns " << bag.isEmpty()
        << "; should be 1 (true)" << endl;
   
   return 0;
} // end main

