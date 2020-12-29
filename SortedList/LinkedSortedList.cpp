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

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& entry) {

}

// the performance of insertSorted depends on the efficiency of the method getNodeBefore
// need a pointer to the current node so we can [[[compare]]] its entry to the desired entry
template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& entry) const {

}

