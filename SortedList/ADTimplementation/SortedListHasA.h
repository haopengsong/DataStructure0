/* A sorted list can maintain its entries within a list;
 * Use a list as a data field within the class that implements the sorted list;
 * This is called Composition => illustrates has-a relationshiop between the class of 
 * 	sorted lists and the class of lists;
 * ADT sorted list using the ADT list
 * Chapter 12-3
 * Must use the list's operations to access the sorted list's entries, instead of accessing them
 * directly. Such implementation of the sorted list is easy to write but is inefficient when the
 * underlying list uses a chain of linked nodes to store its entries
 */

#ifndef SORTED_LIST_HAS_A_
#define SORTED_LIST_HAS_A_

#include <memory>
#include "SortedListInterface.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class SortedListHasA : public SortedListInterface<ItemType> {
private:
	std::unique_ptr<ListInterface<ItemType>> listPtr;

public:
	SortedListHasA();
	SortedListHasA(const SortedListHasA<ItemType>& alist);
	virtual ~SortedListHasA();
	bool insertSorted(const ItemType& entry);
	bool removeSorted(const ItemType& entry);
	int getPosition(const ItemType& entry) const;
	
	// followings are the same as those described in ch8 - listInterface
	bool isEmpty() const;
	int getLength() const;
	bool remove(int postiion);
	void clear();
	ItemType getEntry(int position) const 
	throw(PrecondViolatedExcept);
};
#include "SortedListHasA.cpp"
#endif
