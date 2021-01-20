/* List Queue implementation

*/

#include "ListQueue.h"
#include <memory>

template<class ItemType>
ListQueue<ItemType>::ListQueue() : listPtr(std::make_unique<LinkedList<ItemType>>()) {
	// default constructor
}

template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& q) : listPtr(q.listPtr) {
	// copy constructor
}

template<class ItemType>
ListQueue<ItemType>::~ListQueue() {

}

template<class ItemType>
ListQueue<ItemType>::isEmpty() const {
	return listPtr -> isEmpty();
}

template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& entry) {
	return listPtr -> insert(listPtr -> getLength() + 1, entry);
}

template<class ItemType>
bool ListQueue<ItemType>::dequeue() {
	return listPtr -> remove(1);
}

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const 
throw(PrecondViolatedExcept) {
	if (isEmpty()) {
		throw PrecondViolatedExcept("peekFront() called with empty queue");
	}
	return listPtr -> getEntry(1);
}

