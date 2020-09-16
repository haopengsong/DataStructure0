/*@file Node.h */

#ifndef NODE_
#define NODE_

template<class ItemType>
class Node {
private:
	Node<ItemType>* next;
	ItemType item;
public:
	Node();
	Node(const ItemType& item);
	Node(const ItemType& item, Node<ItemType>* nextPtr);
	void setItem(const ItemType& item);
	void setNext(Node<ItemType>* nextPtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};
#include "Node.cpp"
#endif