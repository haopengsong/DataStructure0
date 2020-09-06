/** @file BagInterface.h */
#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

/*
Abstract class:
	- base type can still define an implementation
	- no objects of the abstract type are allowed to be instantiated
	- pure virtual functions
	- functions that are not implememnted by the base class must be implemented by the 
		derived class
*/

template<class Item>
class BagInterface {
public:
	// Gets the current size of this bag
	virtual int getCurrentSize() const = 0;

	// Counts the number of times a given entry appears in this bag
	virtual int getFrequencyOf(const Item& entry) const = 0;

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
	virtual bool contains(const Item& entry) const = 0;

	// Returns a vector filled with all entries that are in this bag
	virtual std::vector<Item> toVector() const = 0;

	// Destroys this bag and frees its memory
	// virtual ensure that future descendants of the object can deallocate themselves correctly
	virtual ~BagInterface() { }


};
#endif