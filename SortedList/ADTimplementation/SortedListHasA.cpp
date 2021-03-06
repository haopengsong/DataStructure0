#include "SortedListHasA.h"

// constructor
template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA()
	: listPtr(std::make_unique<LinkedList<ItemType>>()) 
{
}

// copy constructor
template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType>& alist)
	: listPtr(std::make_unique<LinkedList<ItemType>>())
{
	for (int position = 1; position <= alist.getLength(); position++) {
		listPtr -> insert(position, alist.getEntry(position));
	}
}

// desctructor
template<class ItemType>
SortedListHasA<ItemType>::~SortedListHasA() {
	clear();
}

template<class ItemType>
bool SortedListHasA<ItemType>::insertSorted(const ItemType& entry) {
	/*
	getPosition finds the position of an existing entry within a sorted list,
	or the position at which we should insert a new entry that does not occur
	in the sorted list; It sets the sign of the integer it returns to indicate
	whether the entry exists in the list already.
	*/
	int newPosition = std::abs(getPosition(entry));
	return listPtr -> insert(newPosition, entry);
}

template<class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType& entry) {
	int position = getPosition(entry);
	bool ableToRemove = position > 0;
	if (ableToRemove) {
		remove(position);
	}	
	return ableToRemove;
}

// Linked-based: o(n^2), Array-based: o(n)
template<class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType& entry) const {
	int position = 1;
	int length = getLength();
	while (position <= length && entry > getEntry(position)) {
		position++;
	}
	if (position > length || entry != getEntry(position)) {
		return -position;
	}
	return position;
}


template<class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const {
	return listPtr -> isEmpty();
}

template<class ItemType>
int SortedListHasA<ItemType>::getLength() const {
	return listPtr -> getLength();
}

template<class ItemType>
bool SortedListHasA<ItemType>::remove(int position) {
	return listPtr -> remove(position);
}

template<class ItemType>
void SortedListHasA<ItemType>::clear() {
	listPtr -> clear();
}

template<class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int position) const
throw(PrecondViolatedExcept)  {
	return listPtr -> getEntry(position);
}
