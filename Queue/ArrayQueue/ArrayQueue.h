/* ADT queue: Circular array-based implementation
*/
#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_
#include "QueueInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 50;
	
	ItemType items[DEFAULT_CAPACITY]; // static allocation of queue items
	
	// front and back index of queue
	int front;
	int back;
	
public:
	ArrayQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType & entry);
	bool dequeue();
	
	ItemType peekFront() const
	throw(PrecondViolatedExcept);

};
#include "ArrayQueue.cpp"
#endif

