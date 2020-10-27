/**	 Interface for the ADT list
@file ListInterface.h */

#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

template<class ItemType>
class ListInterface {
public:
	// check whether this list is empty
	// return True if it's empty, false otherwise
	virtual bool isEmpty() const = 0;

	// gets the current number of entries in this list
	// return the integer number of entries currently in the list
	virtual int getLength() const = 0;

	// inserts an entry into this list at a given position
	// if 1 <= position <= getLength() + 1 and the insertion is successful
	// newEntry is at the given position in the list, other entries are renumbered 
	// accordingly, and the returned value is true
	virtual bool insert(int position, const ItemType& newEntry) = 0;

	// removes the entry at a given position from this list
	// if 1 <= position <= getLength() + 1 and the removal is successful, the 
	// entry at the given position in the list is removed, other item are renumbered
	// accordingly and the returned value is true
	virtual bool remove(int position) = 0;

	// removes all entries from this list
	virtual void clear() = 0;

	// gets the entry at the given position in this list
	virtual ItemType getEntry(int position) const = 0;

	// replaces the entry at the given position in this list
	virtual ItemType replace(int position, const ItemType& newEntry) = 0;

	// destroys this list and frees its assigned memory
	virtual ~ListInterface() { } 
};
#endif