/** 
chapter 7, 7.1
ADT list: Array-based implementation
@file ArrayList.h
*/

#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

#include "ListInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType> {
private:
	static const int DEFAULT_CAPACITY = 100; // Default capacity of the list
	ItemType items[DEFAULT_CAPACITY];
	int itemCount; // current count of list items also
				   //  count of the last entry in the array
	int maxItems;  // maximum capacity of the list
public:
	ArrayList(); // copy constructor and destructor are supplied by compiler
	bool isEmpty() const;
	int getLength() const;
	bool insert(int nPosition, const ItemType& nEntry);
	bool remove(int position);
	void clear();

	/** @throw PrecondViolatedExcept if position < 0 or position > getLength() */
	ItemType getEntry(int position) const
	throw(PrecondViolatedExcept);

	/** @throw PrecondViolatedExcept if postion < 0 or position > getLength() */
	ItemType replace(int position, const ItemType& nEntry)
	throw(PrecondViolatedExcept);
};
#include "ArrayList.cpp"
#endif