/* 
1) SortedListIsA inherits LinkedList's members, adds the method getPosition, and revises the 
insertion and removal operations
2) An is-a relationship implies public inheritance
3) Some methods (insert, replace) must be overriden to prevent a client from calling them which avoids destroying the list order
3) chapter 12-3-2
*/
#ifndef SORTED_LIST_IS_A_
#define SORTED_LIST_IS_A_

#include <memory>
#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class SortedListIsA : public LinkedList<ItemType> {
public:
	SortedListIsA();
	SortedListIsA(const SortedListIsA<ItemType>& list);
	virtual ~SortedListIsA();
	
	bool insertSorted(const ItemType& entry);
	bool removeSorted(const ItemType& entry);
	int getPosition(const ItemType& entry) const;
	
	// remove, clear, getEntry, isEmpty, getLength have the same specs as given
	// in LinkedList

	// Following methods must be overridden to disable their effect on a sorted list
	bool insert(int position, const ItemType& entry) override;
	void replace(int position, const ItemType& entry)
		throw(PrecondViolatedExcept) override;	
};
#include "SortedListIsA.cpp"
#endif
