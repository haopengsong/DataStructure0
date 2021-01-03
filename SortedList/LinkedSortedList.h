/** ADT sorted list: Implementation that use the adt list
Chpater 12
	- for compilation: g++ LinkedSortedListTester.cpp PrecondViolatedExcept.cpp -std=c++11 -o tester
*/

#ifndef LINKED_SORTED_LIST_
#define LINKED_SORTED_LIST_

#include <memory>
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType> {
private:
	std::shared_ptr<Node<ItemType>> headPtr; // pointer to the first node in chain
	int itemCount; // current count of list items

	// locates the node that is before the node that should or does contain the given entry
	// @return either a pointer to the node before the node that contains or should contain the 
	// given entry, or nullptr if no prior node exists
	std::shared_ptr<Node<ItemType>> getNodeBefore(const ItemType& entry) const;

	// locates the node at a given position within the chain
	std::shared_ptr<Node<ItemType>> getNodeAt(int position) const;

	// returns a pointer to a copy of the chain to which origChainPtr points
	std::shared_ptr<Node<ItemType>> copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr);

public:
	LinkedSortedList();
	LinkedSortedList(const LinkedSortedList<ItemType>& alist); // copy constructor
	virtual ~LinkedSortedList();
	bool insertSorted(const ItemType& entry);
	bool removeSorted(const ItemType& entry);
	int getPosition(const ItemType& entry) const;
	bool isEmpty() const;
	int getLength() const;
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const
	throw(PrecondViolatedExcept);
};
#include "LinkedSortedList.cpp" // when using template, the header file should include the 
								// implementation file, because the compiler does not compile
								// a template class until it sees the client's instantiation of the 
								// template and knows the actual data type correspoinding to the 
								// generic type 'ItemType'
#endif
