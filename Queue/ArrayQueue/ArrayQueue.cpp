/** ADT Queue: Circular array-based implementation
*/
#include "ArrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(DEFAULT_CAPACITY - 1), count(0)
{
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const 
{
	return count == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& entry) 
{
	bool result = false;
	if (count < DEFAULT_CAPACITY) {
		// QUEUE has room for another item
		back = (back + 1) % DEFAULT_CAPACITY;
		item[back] = entry;
		count++;
		result = true;
	}
	return result;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() 
{
	bool result = false;
	if (!isEmpty()) {
		front = (front + 1) % DEFAULT_CAPACITY;
		count--;
		result = true;
	}
	return result;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() 
const throw(PrecondViolatedExcept) 
{
	if (isEmpty()) {
		throw PrecondViolatedExcept(" peekFront() called with empty queue ");
	}
	return item[front];
}

























