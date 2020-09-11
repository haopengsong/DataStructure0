/* ArrayStack.cpp */

#include <cassert>
#include "ArrayStack.h"

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1) {
	// end default constructor
}

// copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const {
	return top < 0;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& entry) {
	bool result = false;
	if (top < DEFAULT_CAPACITY - 1) {
		top++;
		items[top] = entry;
		result = true;
	}
	return result;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop() {
	bool result = false;
	if (!isEmpty()) {
		top--;
		result = true;
	}
	return result;
}

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const {
	assert(!isEmpty())
	// not empty return top
	return items[pop];
}