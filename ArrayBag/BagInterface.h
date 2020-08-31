/** @file BagInterface.h */
#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

template<class Item>
class BagInterface {
public:
	// Gets the current size of this bag
	virtual int getCurrentSize() const = 0;

	// Checks if this bag is empty
	virtual bool isEmpty() const = 0;

	// Adds a new entry to this bag
	// Returns true if addition was successful
	virtual bool add(const Item& entry) = 0;

	// Removes one occurrence of a given entry from this bag
	// Returns true if removal was successful
	virtual bool remove(const Item& entry) = 0;

	// Removes all entries from this bag
	virtual void clear() = 0;

	// Tests whether this bag contains a given entry
	virtual bool contains(const Item& entry) = 0;

	// Returns a vector filled with all entries that are in this bag
	virtual std::vector<Item> toVector() const = 0;

	// Destroys this bag and frees its memory
	virtual ~BagInterface() { }
};