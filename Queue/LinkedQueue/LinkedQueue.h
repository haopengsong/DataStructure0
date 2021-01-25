/* ADT queue: Linked-based implementation
A chain of linked nodes with head and tail pointers
*/

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "QueueInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:	
	// with two pointers: head, tail
	std::shared_ptr<Node<ItemType>> frontPtr;
	std::shared_ptr<Node<Itemtype>> backPtr;	
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue& q);
	~LinkedQueue();
	
	bool isEmpty() const;
	bool enqueue(const ItemType& entry);
	bool dequeue();
	
	ItemType peekFront() const
	throw(PrecondViolatedExcept);
};
#include "LinkedQueue.cpp"
#endif

