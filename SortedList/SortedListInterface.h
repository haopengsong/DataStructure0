/** Interface for the ADT sorted list */

#ifndef SORTED_LIST_INTERFACE_
#define SORTED_LIST_INTERFACE_

template<class ItemType>
class SortedListInterface {
public:
	// Inserts an entry into this sorted list, so that the list 
	// remains sorted
	virtual bool insertSorted(const ItemType& newEntry) = 0;

	// Removes the first or only occurrence of the given entry
	// from this sorted list
	virtual bool removeSorted(const ItemType& anEntry) = 0;

	// Gets the position of the first or only occurrence of the given
	// entry in this sorted list. If the entry is not in the list
	// determines where it should be if it were added to the list.
	// @Return Either the position of the given entry, if it occurs
	// 

};