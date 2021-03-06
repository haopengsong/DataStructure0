/** Header file for an array-based implementation of the ADT bag 
ArrayBag: adt bag that uses an array to store its entries
*/
#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType> {
private:

	// Small size to test for a full bag
	static const int DEFAULT_CAPACITY = 20;

	// Array of bag items
	// non-resizable, this array will be allocated during compilation
	// ItemType items[DEFAULT_CAPACITY];

	// resizable
	// this way the array is able to resize during execution
	ItemType* items;

	int itemCount; // current count of items

	int maxItems; // max capacity of the bag

	/*
	Returns either the index of the element in the array items that contains the given target
	Or -1, if the array does not contain the target
	*/
	int getIndexOf(const ItemType& target) const;

public:
	ArrayBag();
	// virtual ensure that future descendants of the object can deallocate themselves correctly
	virtual ~ArrayBag(); 
	int getCurrentSize() const;
	int getFrequencyOf(const ItemType& entry) const;
	bool isEmpty() const;
	bool add(const ItemType& entry);
	bool remove(const ItemType& entry);
	void clear();
	bool contains(const ItemType& entry) const;
	std::vector<ItemType> toVector() const;
};
#include "ArrayBag.cpp"
#endif
