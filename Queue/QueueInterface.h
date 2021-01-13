/*
1) Chapter 13-1
2) C++ interface for queues
*/

#ifndef QUEUE_INTERFACE_
#define QUEUE_INTERFACE_

template<class ItemType>
class QueueInterface {
public:
	virtual bool isEmpty() const = 0;
	
	// adds a new entry to the back of this queue
	virtual bool enqueue(const ItemType& entry) = 0;
	
	// removes the front of this queue
	virtual bool dequeue() = 0;

	// returns the front of this queue
	virtual ItemType peekFront() const = 0;
	
	virtual ~QueueInterface() { }
};
#endif
