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

// traverse the chain, visit each node, copy its data item into the vector
template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
	std::vector<ItemType> bagContents;
	Node<ItemType>* curr = headPtr;
	int counter = 0;
	while (curr != nullptr && counter < itemCount) {
		bagContents.push_back(curr -> getItem());
		curr = curr -> getNext();
		counter++;
	}
	return bagContents;
} 

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
	return itemCount;
}

// the copy constructor
// it makes a copy of an object, it is invoked implicitly when:
// 1) use the assignment operator to assign an object to a variable
// 2) pass an object to a function by value
// 3) return the object from a valued function
// 4) define and initialize an object as in:
//	LinkedBag bag2(bag1), where bag1 exists already
// if not using copy constructor, only shallow copy is used
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag& target) {

}

// must have a destructor if class allocates memory dynamically
template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
	clear();
}

// deletes one occurrence of a given entry, if the entry exists, replace the entry with with entry in the 
// first node, then delete the first node
// any time use 'new' to allocate memory, the memory must eventually be deallocated by 'delete'
template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& entry) {
	Node<ItemType>* entryNodeptr = getPointerTo(entry);
	bool canRemove = !isEmpty() && entryNodeptr != nullptr;
	if (canRemove) {
		// copy data from first node to located node
		entryNodeptr -> setItem(headPtr -> getItem());
		// disconnect the first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr -> getNext();
		// return node to the system
		// so system can resuse the memory
		nodeToDeletePtr -> setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		itemCount--;
	}
	return canRemove;
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr) {
		headPtr = headPtr -> getNext();
		nodeToDeletePtr -> setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = headPtr;
	} 
	// headPtr is nullptr; nodeToDeletePtr is nullptr
	itemCount = 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& entry) const {
	return getPointerTo(entry) != nullptr;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& entry) const {
	int freq = 0;
	int counter = 0;
	Node<ItemType>* curr = headPtr;
	while (curr != nullptr && counter < itemCount) {
		if (entry == curr -> getItem()) {
			freq++;
		}
		counter++;
		curr = curr -> getNext()
	}
	return freq;
}

template<class ItemType>
Node<ItemType> LinkedBag<ItemType>::getPointerTo(const ItemType& entry) const {
	bool found = false;
	Node<ItemType>* curr = headPtr;
	while (!found && curr != nullptr) {
		if (entry == curr -> getItem()) {
			found = true;
		} else {
			curr = curr -> getNext();
		}
	}
	return curr;
}







