/* Implementation file ofr the class ArrayBag */
#include "ArrayBag.h"

// Constructor
template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {

}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& entry) {
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd) {
		items[itemCount] = entry;
		itemCount++;
	}
	return hasRoomToAdd;
}

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const {
	vector<ItemType> bags;
	for (int i = 0; i < itemCount; i++) {
		bags.push_back(items[i]);
	}
	return bags;
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
	return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& entry) {
	return false;
}

template<class ItemType>
void ArrayBag<ItemType>::clear() {
	
}