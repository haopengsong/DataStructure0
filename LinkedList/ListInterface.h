/*	Interface for the ADT list 	*/
#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

template<class ItemType>
class ListInterface {
public:
	// check whether this list is empty
	// returns true if list is empty
	virtual bool isEmpty() const = 0;

	// gets the current number of entries in this list
	virtual int getLength() const = 0;

	// inserts an entry into this list at a given position, possible renumbering
	virtual bool insert(int newPos, const ItemType& entry) = 0;

	// removes the entry at a given position from this list, possible renumbering
	virtual bool remove(int position) = 0;

	// removes all entries from this list
	virtual void clear() = 0;

	// gets the entry at the given position in this list
	virtual ItemType getEntry(int position) const = 0;

	// replaces the entry at the given position in this list
	// returns the replaced entry
	virtual ItemType replace(int position, const ItemType& entry) = 0;

	// destroy this list and frees its assigned memory
	virtual ~ListInterface() { }

	// make all implementations of ListInterface to provide an implementation of the operator == 
	virtual bool operator==( const LinkedList<ItemType>& rhs ) const = 0;

	// 
}; // end ListInterface
#endif
