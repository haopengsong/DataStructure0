/** ADT queue: ADT list implementation
1. if the item in position 1 of a list represents the front of the queue:
	1) dequeue => remove(1)
	2) peekFront => getEntry(1)
2. if the item at the end of the list represent the back of the queue:
	1) enqueue(newEntry) => insert(getLength() + 1, newEntry)
*/
#ifndef LIST_QUEUE_
#define LIST_QUEUE_

#include "QueueInterface.h"
#include "LinkedList.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class ListQueue : public QueueInterface<ItemType> {
private:
	std::unique_ptr<LinkedList<ItemType>> listPtr;
	// pointer to list of queue items
public:
	ListQueue();
	ListQueue(const ListQueue& q);
	~ListQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& entry);
	bool dequeue();
	ItemType peekFront() const
		throw(PrecondViolatedExcept);
};
#include "ListQueue.cpp"
#endif

