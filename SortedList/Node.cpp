/** Node.cpp 
#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {
	// default constructor
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& item) : item(item), next(nullptr) {
	// constructor
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType>* nextNodePtr) : 
item(item), next(nextNodePtr) {
	// construtor
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& item) {
	this -> item = item;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
	this -> next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
	return this -> item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
	return this -> next;
}
*/

/** Node.cpp */
// version 2, using shared_ptr
#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {
	// default constructor
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& item) : item(item), next(nullptr) {
	// constructor
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& item, std::shared_ptr<Node<ItemType>> nextNodePtr) : 
item(item), next(nextNodePtr) {
	// construtor
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& item) {
	this -> item = item;
}

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) {
	this -> next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
	return this -> item;
}

template<class ItemType>
std::shared_ptr<Node<ItemType>> Node<ItemType>::getNext() const {
	return this -> next;
}
