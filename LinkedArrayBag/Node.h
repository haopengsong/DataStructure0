/** @file Node.h */
#ifndef NODE_
#define NODE_

template<class ItemType>
class Node {
private:
	ItemType item; // a data item
	Node<ItemType>* next; // pointer to next node
public:
	Node();
	Node(const ItemType& item);
	Node(const ItemType& item, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& item);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};
#include "Node.cpp"
#endif