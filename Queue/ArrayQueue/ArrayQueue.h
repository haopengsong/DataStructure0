/* ADT queue: Circular array-based implementation
*/
#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_
#include "QueueInterface.h"
#include "PrecondViolatedExcept.h"
#include <vector>

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
	// static const int DEFAULT_CAPACITY = 50;	
	// ItemType items[DEFAULT_CAPACITY]; // static allocation of queue items
	std::vector<ItemType> arr;
	// front and back index of queue
	int front;
	int back;
	int capacity;
public:
	ArrayQueue( );
	ArrayQueue( int k );
	~ArrayQueue();
	bool isEmpty() const;
	bool isFull() const;
	bool enqueue(const ItemType & entry);
	bool dequeue();
	ItemType Front() const throw(PrecondViolatedExcept);
	ItemType Rear() const throw(PrecondViolatedExcept);

};
#include "ArrayQueue.cpp"
#endif

