/* LIFO, Linked-based implementation of stack. It grows and shrink dynamically. 
Careful when implementing the deep copy constructor
			----
topPtr --> | 10 |
		    ----
		   |next|
		    ----
			|
			|
			v
			----
		   | 19 |
		    ----
		   |next|
		    ----
			|
			|
			v
			----
		   | 19 |
		    ----
		   |next|
		    ----
		    |
		    |
		    v
		    ----
		   | 50 |
		    ----
		   |next|
		    ----
		    |
		    |
		    v
		   ...

*/

#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
	Node<ItemType>* topPtr; // pointer to first node in the chain, this node contains
							// stack's top
public:
	LinkedStack(); // constructors and destructor
	LinkedStack(const LinkedStack<ItemType>& aStack) // copy constructor
	virtual ~LinkedStack();
	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();
	ItemType peek() const;
};
#include "LinkedStack.cpp"
#endif