/** Implementation file for the class LinkedBag */
#include "LinkedBag.h"

// constructor
template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {
	// default constructor
}

// add, at the begining of the chain
/*
headPtr ________original_reference___> |"node 1"|next| _______> |"node 2"|next| ____> nullptr
			|
			|							   ^			
||		updated reference                  |
			|							   |					
			|							   |	
			|_____>						   |	
newNodePtr--------> |"new node 1"|next|____|
*/
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& entry) {
	Node<ItemType>* newNodeptr = new Node<ItemType>();
	newNodeptr -> setItem(entry);
	newNodeptr -> setNext(headPtr);
	headPtr = newNodeptr;
	itemCount++;
	return true; // always return true, since addition is always possible
}

template<class ItemType>
bool 


