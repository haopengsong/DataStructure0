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
LinkedSortedList<ItemType>::~LinkedSortedList() {
	clear();
}

template<class ItemType>
std::shared_ptr<Node<ItemType>> LinkedSortedList<ItemType>::getNodeAt(int position) const {
	assert(position >= 1 && position <= itemCount);
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;
	for (int i = 1; i < position; i++) {
		curPtr = curPtr -> getNext();
	}
	return curPtr;
}


/*
Begin by testing the pointer argument, if it contains nullptr, the original sorted list is 
empty, so the method returns nullptr. Otherwise, the method creates a new node containing the 
data from the first node of the given chain. The method then recursively inserts the new node 
into the copy of the chain. After each insertion, the method returns a pointer to the new chain
*/
template<class ItemType>
std::shared_ptr<Node<ItemType>> LinkedSortedList<ItemType>::copyChain(const std::shared_ptr<Node<ItemType>>& origChainPtr) {
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
	std::shared_ptr<Node<ItemType>> newNodePtr(std::make_shared<Node<ItemType>>(newEntry));
	std::shared_ptr<Node<ItemType>> prevPtr = getNodeBefore(newEntry);
	if (isEmpty() || (prevPtr == nullptr)) {
		// add at beginning 
		newNodePtr -> setNext(headPtr);
		headPtr = newNodePtr;	
	} else {
		// add after node before
		std::shared_ptr<Node<ItemType>> afterPtr = prevPtr -> getNext();
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
std::shared_ptr<Node<ItemType>> LinkedSortedList<ItemType>::getNodeBefore(const ItemType& entry) const {
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;
	std::shared_ptr<Node<ItemType>> prevPtr;
	while (curPtr != nullptr && entry > curPtr -> getItem()) {
		prevPtr = curPtr;
		curPtr = curPtr -> getNext();
	}
	return prevPtr;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& entry) {
	int position = getPosition(entry);
	bool ableToRemove = position > 0;
	if (ableToRemove) {
		remove(position);
	}
	return ableToRemove;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& entry) const {
	int position = 1;
	int length = getLength();
	while (position <= length && entry > getEntry(position)) {
		position++;
	}
	if (position > length || entry != getEntry(position)) {
		position = -position;
	}
	return position;
}


template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const {
	return itemCount;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position) {
	bool canRemove = (position >= 1) && (position <= itemCount);
	if (canRemove) {
		if (position == 1) {
			headPtr = headPtr -> getNext();
		} else {
			std::shared_ptr<Node<ItemType>> prePtr = getNodeAt(position - 1);
			std::shared_ptr<Node<ItemType>> curPtr = prePtr -> getNext();
			prePtr -> setNext(curPtr -> getNext());
		}
		itemCount--;
	}
	return canRemove;
}

template<class ItemType>
void LinkedSortedList<ItemType>::clear() {
	headPtr = nullptr;
	itemCount = 0;
}

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const 
throw(PrecondViolatedExcept) {
	bool canGet = (position >= 1) && (position <= itemCount);
	if (canGet) {
		std::shared_ptr<Node<ItemType>> nodePtr = getNodeAt(position);
		return nodePtr -> getItem();
	} else {
		std::string message = "getEntry() called with an empty list or ";
		message += "invalid position";
		throw(PrecondViolatedExcept(message)); 
	}
}




























