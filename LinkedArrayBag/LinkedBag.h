/** ADT bag: link-based implementation 
LinkedBag: adt bag that uses linked list to store entries which does not
has a fixed size
*/
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

/*

Need to implement operations in BagInterface int public methods

*/
template<class ItemType>
class LinkedBag : public BagInterface<ItemType> {
private:
	Node<ItemType>* headPtr; // Pointer to first node
	int itemCount; // Current count of bag items
	/*
	Returns either a pointer to the node containing a given entry or the null
	pointer if the entry is not in the bag
	*/
	Node<ItemType>* getPointerTo(const ItemType& target) const;
public:
	LinkedBag(); // default constructor
	LinkedBag(const LinkedBag<ItemType>& bag); // copy constructor
	virtual ~LinkedBag(); // virtual destructor
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& entry);
	bool remove(const ItemType& entry);
	void clear();
	bool contains(const ItemType& entry) const;
	int getFrequencyOf(const ItemType& entry) const;
	std::vector<ItemType> toVector() const;
};
#include "LinkedBag.cpp"
#endif