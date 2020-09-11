/**	ADT stack: LIFO, array-based implementation */
#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackInterface.h"

template<class ItemType>
class ArrayStack : public StackInterface<ItemType> {
private:
	static const int DEFAULT_CAPACITY;
	ItemType items[DEFAULT_CAPACITY]; // array of stack items
	int top; // index of top of stack
public:
	ArrayStack();
	bool isEmpty() const;
	bool push(const ItemType& entry);
	bool pop();
	ItemType peek() const;

};
#include "ArrayStack.cpp"
#endif
