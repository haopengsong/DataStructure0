/** Implementation file for LinkedList.h */

#include "LinkedList.h"

// use initializers to set up data fields
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {
	// end default constructor
}

// throw exceptions if position is out of bounds
template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const 
throw(PrecondViolatedExcept) {
	// enfore precondition, position starts at 1
	bool canGet = (position > 1) && (position <= itemCount);
	if (canGet) {
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr -> getItem();
	} else {
		std::string message = "getEntry() called with an empty list or ";
		message += "invalid position";
		throw(PrecondViolatedExcept(message));
	}
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
	// debugging check of precondition
	
}

