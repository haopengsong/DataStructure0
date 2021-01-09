#include "SortedListIsA.h"

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA()
{
}

// the copy constructor invokes LinkedList's copy constructor by using initializer
template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA(const SortedListIsA<ItemType>& list)
		 : LinkedList<ItemType>(list)
{
}

template<class ItemType>
SortedListIsA<ItemType>::~SortedListIsA()
{
}

template<class ItemType>
bool SortedListIsA<ItemType>::insertSorted(const ItemType& entry) {
	int position = std::abs(getPosition(entry));
	
	// call the LinkedList version of insert, since the 
	// SortedListIsA version does nothing but return false
	// can also use this -> insert(position, entry);
	return LinkedList<ItemType>::insert(position, entry);
} 

template<class ItemType>
bool SortedListIsA<ItemType>::removeSorted(const ItemType& entry) {
	int position = getPosition(entry);
	bool ableToRemove = position > 0;
	if (ableToRemove) {
		ableToRemove = LinkedList<ItemType>::remove(position);
	}
	return ableToRemove;
}

template<class ItemType>
int SortedListIsA<ItemType>::getPosition(const ItemType& entry) const {
	int position = 1;
	int length = LinkedList<ItemType>::getLength();
	while (position <= length && entry > LinkedList<ItemType>::getEntry(position)) {
		position++;
	}
	if (position > length || entry != LinkedList<ItemType>::getEntry(position)) {
		return -position;
	}
	return position;
}

template<class ItemType>
bool SortedListIsA<ItemType>::insert(int position, const ItemType& entry) {
	return false;
}

template<class ItemType>
void replace(int position, const ItemType& entry) throw(PrecondViolatedExcept) {
	return;
}
