/** Implementation file for the class LinkedBag */
#include "LinkedBag.h"

// constructor
template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {
	// default constructor
}

// add, at the begining of the chain
/*
headPtr ________original_reference___> |"node 1"|next| _______> |"node 2"|next| ____> nullptr
			|
			|							   ^			
||		updated reference                  |
			|							   |					
			|							   |	
			|_____>						   |	
newNodePtr--------> |"new node 1"|next|____|
*/
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& entry) {
	Node<ItemType>* newNodeptr = new Node<ItemType>();
	newNodeptr -> setItem(entry);
	newNodeptr -> setNext(headPtr);
	headPtr = newNodeptr;
	itemCount++;
	return true; // always return true, since addition is always possible
}

// traverse the chain, visit each node, copy its data item into the vector
template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
	std::vector<ItemType> bagContents;
	Node<ItemType>* curr = headPtr;
	int counter = 0;
	while (curr != nullptr && counter < itemCount) {
		bagContents.push_back(curr -> getItem());
		curr = curr -> getNext();
		counter++;
	}
	return bagContents;
} 

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
	return itemCount;
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag& target) {

}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {

}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& entry) {
	return false;
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
	return;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& entry) const {
	return false;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& entry) const {
	return 1;
}
















