#include "LinkedQueue.h"

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& entry) {
	std::shared_ptr<Node<ItemType>> newNodePtr = std::make_shared<Node<ItemType>>(entry);
	
	// if queue is empty
	// both the front/back pointers point to the newNode
	if (isEmpty()) {
		frontPtr = newNodePtr; 
	} else {
		backPtr -> setNext(newNodePtr); // for queue not empty
	}
	backPtr = newNodePtr;
	return true;
}


// Remove from a queue of one item is a special case that sets the external pointers
// backPtr and frontPtr to nullptr
template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
	bool result = false;
	if (!isEmpty()) {
		// not empty, remove front
		std::shared_ptr<Node<ItemType>> nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr) {
			// special case: one node in queue
			// set frontPtr and backPtr to nullptr
			frontPtr.reset();
			backPtr.reset();
		} else {
			frontPtr = frontPtr -> getNext();
			
			// maintain an accurate reference count for first node 
			nodeToDeletePtr -> setNext(nullptr);
			
			// removed node will be deallocated when method ends
			result = true;
		}
	}
	return result;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const 
	throw(PrecondViolatedExcept) {
	if ( !isEmpty() ) {
		return frontPtr -> getItem();
	} else {
		throw PrecondViolatedExcept("peekFront() called with empty queue");
	}
}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
	return frontPtr == backPtr;
}


