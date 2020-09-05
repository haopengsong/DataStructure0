/* A linked-based implementation of List;
Unlike the Arraylist (array-based implementation List), a link-based
implementation does not shift items during insertion and removal, does not
impose a fixed length on the list (however, does limit by system storage)
*/
#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PreCondViolatedExcept.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
	Node<ItemType>* headPtr; // pointer to first node
	int itemCount; // current element count of list
	
	// locates a specified node in a linked list
	Node<ItemType>* getNodeAt(int position) const;
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	// @throw PrecondViolatedExcept if position < 1 or position > getLength()
	ItemType getEntry(int position) const throw(PreCondViolatedExcept);
	ItemType replace(int position, const ItemType& newEntry) throw(PreCondViolatedExcept)

};
#include "LinkedList.cpp"
#endif