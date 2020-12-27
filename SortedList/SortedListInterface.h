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
	// in the sorted list, or the position where the entry would occur, but
	// as a negative integer
	virtual int getPosition(const ItemType& entry) const = 0;

	// whether this list is empty
	virtual bool isEmpty() const = 0;

	// get the current number of entries in this list
	virtual int getLength() const = 0;

	// removes the entry at a given position from this list
	virtual bool remove(int position) = 0;
	
	// removes all entires from this list
	virtual void clear() = 0;

	// gets the entry at the given position in this list
	virtual ItemType getEntry(int position) const = 0;

	// Destorys this sorted list and free its assigned memory
	virtual ~SortedListInterface() { }		
};

#endif