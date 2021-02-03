/*
1) Chapter 13-1
2) C++ interface for queues
3) Simple queue applications:
	- queue can retain characters in the order in which you type them
	- recognizing Palindromes:
		- stack for reverse the order of occurrences
		- queue to preserve the order of occurrences
		- compare
4) Simulation: a technique for modeling the behavior of both natural and human-made systems.
	- The goal of a simulation is to generate statistics that summarize the performance of an 
	existing system or to predict the performance of a proposed system.  
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
