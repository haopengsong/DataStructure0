/* A linked-based implementation of List;
Unlike the Arraylist (array-based implementation List), a link-based
implementation does not shift items during insertion and removal, does not
impose a fixed length on the list (however, it does limit by system storage)

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
	Node<ItemType>* headPtr; // pointer to first node
	int itemCount; // current element count of list
	
	// locates a specified node in a linked list
	Node<ItemType>* getNodeAt(int position) const;
public:
	LinkedList();
	// copy constructor
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	// @throw PrecondViolatedExcept if position < 1 or position > getLength()
	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
	ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);

};
#include "LinkedList.cpp"
#endif
*/

// version 2, using shared ptr

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <cassert>
template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
	// Node<ItemType>* headPtr; // pointer to first node
	// since more than one pointer can reference a node, we must use shared_ptr
	std::shared_ptr<Node<ItemType>> headPtr;
	int itemCount; // current element count of list
	
	// locates a specified node in a linked list
	std::shared_ptr<Node<ItemType>> getNodeAt(int position) const;
	
	// copy list node 
	void copyListNode(const LinkedList<ItemType>& rhs);	
public:
	LinkedList();
	// copy constructor
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	bool operator==(const LinkedList<ItemType>& rhs) const;
	LinkedList<ItemType>& operator=(const LinkedList<ItemType>& rightHandSide);
	// + for concatenation
        //	LinkedList<ItemType>& operator+(const LinkedList<ItemType>& rightHandSide);

	template<class friendItemType>
	friend std::ostream& operator<<(std::ostream& outStream,
					 const LinkedList<friendItemType>& outputList);
	

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	// @throw PrecondViolatedExcept if position < 1 or position > getLength()
	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
	ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);

};
#include "LinkedList.cpp"
#endif
