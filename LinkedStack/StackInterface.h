/** @file StackInterface.h */
#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface {
public:
	// checks whether the stack is empty
	virtual bool isEmpty() const = 0;

	// adds a new entry to the top of the stack
	virtual bool push(const ItemType& entry) = 0;

	// removes the top of this stack
	virtual bool pop() = 0;

	// returns a copy of the top of this stack
	virtual ItemType peek() const = 0;

	// destroys this stack and frees its assigned memory
	virtual ~StackInterface() { }
};
#endif