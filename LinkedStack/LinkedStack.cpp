/**	@file LinkedStack.cpp */
#include <cassert>
#include "LinkedStack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {

}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {
	// pointer to nodes in the original chain
	Node<ItemType>* originalChainPtr = aStack.topPtr;
	if (originalChainPtr == nullptr) {
		topPtr = nullptr; // original stack is empty
	} else {
		// copy first node
		topPtr = new Node<ItemType>();
		topPtr -> setItem(originalChainPtr -> getItem());
		// point to first node in new chain
		Node<ItemType>* newChainPtr = topPtr;

		// advance the original chain pointer
		originalChainPtr = originalChainPtr -> getNext();

		while (originalChainPtr != nullptr) {
			// get next item from original chain
			ItemType nextItem = originalChainPtr -> getItem();
			// create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			newChainPtr -> setNext(newNodePtr);
			newChainPtr = newChainPtr -> getNext();

			originalChainPtr = originalChainPtr -> getNext();
		}
		newChainPtr -> setNext(nullptr);
	}
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
	while (!isEmpty()) {
		pop();
	}
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& item) {
	Node<ItemType>* newNodePtr = new Node<ItemType>(item, topPtr);
	topPtr = newNodePtr;
	newNodePtr = nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
	bool result = false;
	if (!isEmpty()) {
		// stack is not empty; delete top
		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr -> getNext();

		// return deleted memory to system
		nodeToDeletePtr -> setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		return true;
	}
	return result;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() {
	// enforce precondition during debugging
	assert(!isEmpty());

	// stack is not empty
	return topPtr -> getItem();
}

template<class ItemType> 
bool LinkedStack<ItemType>::isEmpty() const {
	return topPtr == nullptr;
}
