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
	bool canGet = (position >= 1) && (position <= itemCount);
	if (canGet) {
		auto nodePtr = getNodeAt(position);
		return nodePtr -> getItem();
	} else {
		std::string message = "getEntry() called with an empty list or ";
		message += "invalid position";
		throw(PrecondViolatedExcept(message));
	}
}

// locates the node at a given position by traversing the chain
/*
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
*/
// version 2 with shared ptr
template<class ItemType>
std::shared_ptr<Node<ItemType>> LinkedList<ItemType>::getNodeAt(int position) const {
	// debugging check of precondition
	assert(position >= 1 && position <= itemCount);
	auto curPtr = headPtr;
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

// using smart pointer: when insert terminates, all nodes in the linked
// 
template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
	bool canInsert = (newPosition >= 1 && newPosition <= itemCount + 1);
	if (canInsert) {
		// create new node
		// Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);
		// attach new node to chain
		if (newPosition == 1) {
			// insert at the begining
			newNodePtr -> setNext(headPtr);
			headPtr = newNodePtr;
		} else {
			// find the node that will be before newPosition
			// Node<ItemType>* prePtr = getNodeAt(newPosition - 1);
			auto prevPtr = getNodeAt(newPosition - 1);
			// insert new node after node to which prePtr points
			newNodePtr -> setNext(prevPtr -> getNext());
			prevPtr -> setNext(newNodePtr);
		}
		itemCount++;
	}
	return canInsert;
}


// 1. locate the node that you want to remove
// 2. disconnect this node from the linked chain by changing pointers
// 3. return the node to the system
template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
	bool canRemove = (position >= 1 && position <= itemCount);
	if (canRemove) {
		// Node<ItemType>* curPtr = nullptr;	
		if (position == 1) {
			// remove the first node
			// curPtr = headPtr;
			headPtr = headPtr -> getNext();
 		} else {
 			// find the node that is before the one to remove
 			// Node<ItemType>* prev = getNodeAt(position - 1);
 			auto prevPtr = getNodeAt(position - 1);
 			// point to node to remove
 			// curPtr = prev -> getNext();
 			auto curPtr = prevPtr -> getNext();
 			// disconnect indicated node from chain by connecting the prior
 			// node with the one after
 			prevPtr -> setNext(curPtr -> getNext());
 		}
 		// curPtr -> setNext(nullptr);
 		// delete curPtr;
 		// curPtr = nullptr;
 		itemCount--;
	}
	return canRemove;
}

// invoke remove(1) repeatedly until the list is empty
template<class ItemType>
void LinkedList<ItemType>::clear() {
	// while (!isEmpty()) {
	// 	remove(1);
	// }
	headPtr = nullptr;
	itemCount = 0;
	std::cout << "clear called" << std::endl;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
	clear();
}

template<class ItemType>
void LinkedList<ItemType>::copyListNode(const LinkedList<ItemType>& rhs) {	
	std::shared_ptr<Node<ItemType>> originalChainPtr = rhs.headPtr;
	if (originalChainPtr == nullptr) {
		// empty so is the copy
		headPtr = nullptr;
	} else {
		// copy head node
		headPtr = std::make_shared<Node<ItemType>>();
		headPtr -> setItem(originalChainPtr -> getItem());
		// copy rest nodes
		Node<ItemType>* newChainPtr = headPtr;
		originalChainPtr = originalChainPtr -> getNext();
		while (originalChainPtr != nullptr) {
			// get and copy the next item
			ItemType nextItem = originalChainPtr -> getItem();
			// create a node contains the next item
			Node<ItemType>* copy = new Node<ItemType>(nextItem);
			// link
			newChainPtr -> setNext(copy);
			// advance
			newChainPtr = newChainPtr -> getNext();
			originalChainPtr = originalChainPtr -> getNext();
		}
		newChainPtr -> setNext(nullptr);
	}
}

// reference to p147, chapter link-based arrayBag
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& rhs) {
	itemCount = rhs.itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
throw(PrecondViolatedExcept) {
	bool canReplace = (position >= 1 && position <= itemCount);
	if (canReplace) {
		auto NodeToReplace = getNodeAt(position);
		ItemType oldEntry = NodeToReplace -> getItem();
		NodeToReplace -> setItem(newEntry);
		return oldEntry;
	} else {
		std::string message = "replace() called with an empty list or ";
		message += "invalid position";
		throw(PrecondViolatedExcept(message));
	}
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const {
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& rhs) const {
	bool isEqual = true;
	// first check whether the number of items is the same
	if (itemCount != rhs.getLength( ) ) {
		isEqual = false;
	} else {
		std::shared_ptr<Node<ItemType>> leftSidePtr = headPtr;
		std::shared_ptr<Node<ItemType>> rightSidePtr = rhs.headPtr; 	
		while ( (leftSidePtr != nullptr) && (rightSidePtr != nullptr) && isEqual) {
			ItemType leftItem = leftSidePtr -> getItem();
			ItemType rightItem = rightSidePtr -> getItem();
			// the operator == must be defined for ItemType
			isEqual = (leftItem == rightItem);
			leftSidePtr = leftSidePtr -> getNext();
			rightSidePtr = rightSidePtr -> getNext();
		}
	}
	return isEqual;
}

/*
template<class ItemType>
ItemType LinkedList<ItemType>::operator+(const LinkedList<ItemType>& rhs) {
	
} 
*/

// if you declare and initialize an object in the same statement, the compiler will invoke the copy constructor
// not the = operator:
// 	LinkedList<string> l1 = l2;
// this is equivalent to:
// 	LinkedList<string> l1(l2)

template<class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType>& rhs) {
	if (this != &rhs) {
		this -> clear(); // deallocate left-hand side
	        copyListNode( rhs ); // copy list nodes
		itemCount = rhs.itemCount; // copy size of list		
	}	
	return *this;
}

template<class friendItemType>
std::ostream& operator<<(std::ostream& outStream,
			const LinkedList<friendItemType>& outputList)
{
	int position = 1;
	std::shared_ptr<Node<friendItemType>> curPtr = outputList.headPtr;
	while ( curPtr != nullptr ) {
		outStream << position << "\t" << curPtr -> getItem() << std::endl;
		curPtr = curPtr -> getNext();
		position++;
	}
	return outStream;
}





