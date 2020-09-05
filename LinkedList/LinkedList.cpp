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

// locates the node at a given position by traversing the chain
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
	// debugging check of precondition
	assert(position >= 1 && position <= itemCount);
	Node<ItemType>* curPtr = headPtr;
	for (int i = 1; i < position; i++) {
		curPtr = curPtr -> getNext();
	}
	return curPtr;
}

// inserts a new node between nodes, with three processes
// 1. create a new node and store the new data in it
// 2. determine the point of insertion
// 3. connect the new node to the linked chain by changing pointers
// inserts at the end is not a special case as when curPtr becomes nullptr
// it has pasted the end of the chain, also prePtr will point at the end of the entry
template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
	bool canInsert = (newPosition >= 1 && newPosition <= itemCount + 1);
	if (canInsert) {
		// create new node
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		// attach new node to chain
		if (newPosition == 1) {
			// insert at the begining
			newNodePtr -> setNext(headPtr);
			headPtr = newNodePtr;
		} else {
			// find the node that will be before newPosition
			Node<ItemType>* prePtr = getNodeAt(newPosition - 1);
			// insert new node after node to which prePtr points
			newNodePtr -> setNext(prePtr -> getNext());
			prePtr -> setNext(newNodePtr);
		}
	}
	return canInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {

}

template<class ItemType>
void LinkedList<ItemType>::clear() {

}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {

}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
	
}


















