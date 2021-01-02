#include "LinkedSortedList.h"

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0) {
	// default constructor
}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& alist) {
	// copy constructor
	// non-recursive approach

	// recursive approach
	headPtr = copyChain(alist.headPtr);
	itemCount = alist.itemCount;
}

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const {

}


/*
Begin by testing the pointer argument, if it contains nullptr, the original sorted list is 
empty, so the method returns nullptr. Otherwise, the method creates a new node containing the 
data from the first node of the given chain. The method then recursively inserts the new node 
into the copy of the chain. After each insertion, the method returns a pointer to the new chain
*/
template<class ItemType>
auto LinkedSortedList<ItemType>::copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr) {
	std::shared_ptr<Node<ItemType>> copiedChainPtr;
	// initial value is not nullptr
	if (origChainPtr != nullptr) {
		// build new chain from given one
		// create new node
		copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr -> getItem());
		copiedChainPtr -> setNext(copyChain(origChainPtr -> getNext()));
	}
	return copiedChainPtr;
}


/*
adding an entry to a sorted list requires that you find where in the list the new 
entry belongs. Since the entries are sorted, you compare the new entry with the entries
int the sorted list until you reach an entry that is not smaller than the new entry
*/
template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry) {
	auto newNodePtr(std::make_shared<Node<ItemType>>(newEntry));
	auto prevPtr = getNodeBefore(newEntry);
	if (isEmpty() || (prevPtr == nullptr)) {
		// add at beginning 
		newNodePtr -> setNext(headPtr);
		headPtr = newNodePtr;	
	} else {
		// add after node before
		auto afterPtr = prevPtr -> getNext();
		newNodePtr -> setNext(afterPtr);
		prevPtr -> setNext(newNodePtr);
	}
	itemCount++;
	return true;
}

// the performance of insertSorted depends on the efficiency of the method getNodeBefore
// need a pointer to the current node so we can [[[compare]]] its entry to the desired entry
// also must retain a pointer to the previous node
template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& entry) const {
	auto curPtr = headPtr;
	std::shared_ptr<Node<ItemType>> prevPtr;
	while (curPtr != nullptr && entry > curPtr -> getItem()) {
		prevPtr = curPtr;
		curPtr = curPtr -> getNext();
	}
	return prevPtr;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& entry) {

}

template<class ItemType>
bool LinkedSortedList<ItemType>::getPosition(const ItemType& entry) {

}


template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {

}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const {

}

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position) {

}

template<class ItemType>
void LinkedSortedList<ItemType>::clear() {

}

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const 
throw(PrecondViolatedExcept) {

}




























