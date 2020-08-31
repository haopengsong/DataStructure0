/* Implementation file ofr the class ArrayBag */
#include "ArrayBag.h"

// Constructor
/* non-resizable
template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {

}
*/

// resizable
template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {
	items = new ItemType[DEFAULT_CAPACITY];
}

// Destructor
template<class ItemType>
ArrayBag<ItemType>::~ArrayBag() {
	delete [] items;
}

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& entry) const {
	bool found = false;
	int result = -1;
	int curIndex = 0;
	while (!found && curIndex < itemCount) {
		found = items[curIndex] == entry;
		if (found) {
			result = curIndex;
			break;
		} else {
			curIndex++;
		}
	}
	return result;
}

/* non-resizable
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& entry) {
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd) {
		items[itemCount] = entry;
		itemCount++;
	}
	return hasRoomToAdd;
}
*/

// resizable add()
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& entry) {
	bool hasRoomToAdd = itemCount < maxItems;
	if (!hasRoomToAdd) {
		// expand items array
		ItemType* oldArray = items;
		items = new ItemType[2 * maxItems];
		for (int index = 0; index < maxItems; index++) {
			items[index] = oldArray[index];
		}
		delete [] oldArray;
		maxItems = 2 * maxItems;
	}
	items[itemCount] = entry;
	itemCount++;
	return true;
}

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
	std::vector<ItemType> bags;
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
	// If the order of the elements are irrelavent then we can replace the entry being 
	// removed with the last entry in the array

	// If the order is important then we copy each successive entry to the previous 
	// element in the array, begining with the entry after the removed item and ending
	// with the last entry

	int index = getIndexOf(entry);
	bool canRemove = !isEmpty() && index != -1;
	if (canRemove) {
		itemCount--;
		items[index] = items[itemCount];
	}
	return canRemove;
}

template<class ItemType>
void ArrayBag<ItemType>::clear() {
	itemCount = 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& entry) const {
	// could use return getFrequencyOf(entry) > 0;
	// but below is better:
	bool found = false;
	int curIndex = 0;
	while (!found && curIndex < itemCount) {
		if (entry == items[curIndex]) {
			found = true;
			break;
		} else {
			curIndex++;
		}
	}
	return found;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& entry) const {
	int freq = 0;
	int curIndex = 0;
	while (curIndex < itemCount) {
		if (items[curIndex] == entry) {
			freq++;
		}
		curIndex++;
	}
	return freq;
}