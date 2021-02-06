/** ADT Queue: Circular array-based implementation
*/
#include "ArrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(0), capacity(0)
{
}

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue( int k ) {
	capacity = k + 1;
	arr.resize( capacity );
	front = 0;
	back = 0;
}

template<class ItemType>
ArrayQueue<ItemType>::~ArrayQueue() {

}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const 
{
	return front == back;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& entry) 
{
	if (isFull()) {
		return false;
	}
	arr[back] = entry;
	back = (back + 1) % capacity;
	return true;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() 
{
	if (isEmpty()) {
		return false;
	}
	front = (front + 1) % capacity;
	return true;
}


template<class ItemType>
ItemType ArrayQueue<ItemType>::Front() const throw(PrecondViolatedExcept)  {
	return isEmpty() ? throw PrecondViolatedExcept( "Front() called with an empty queue" ) : arr[front];
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::Rear() const throw(PrecondViolatedExcept) {	
	return isEmpty() ? throw PrecondViolatedExcept( "Rear() called with an empty queue" ) : arr[(back - 1 + capacity) % capacity];
}

template<class ItemType>
bool ArrayQueue<ItemType>::isFull() const {
	return (back + 1) % capacity == front; 
}






















