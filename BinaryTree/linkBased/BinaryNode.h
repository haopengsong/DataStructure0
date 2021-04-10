/** A class of nodes for a link-based binary tree
@file BinaryNode.h
*/

#ifndef BINARY_NODE_
#define BINARY_NODE_
#include <memory>

template<class ItemType>
class BinaryNode
{
private:
    ItemType item; // data portion
    std::shared_ptr<BinaryNode<ItemType>> leftChildPtr; // pointer to left child
    std::shared_ptr<BinaryNode<ItemType>> rightChildPtr; // pointer to right child
public:
    BinaryNode();
    BinaryNode(const ItemType& anitem);
    BinaryNode(const ItemType& anitem, std::shared_ptr<BinaryNode<ItemType>> leftPtr,
                                       std::shared_ptr<BinaryNode<ItemType>> rightPtr);
    
    void setItem(const ItemType& anitem);
    ItemType getItem() const;
    bool isLeaf() const;
    
    auto getLeftChildPtr() const;
    auto getRightChildPtr() const;

    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
}; // end BinaryNode
#include "BinaryNode.cpp"
#endif

// Given this BinaryNode, a class of link-based binary trees will declare one data member -- a pointer rootPtr -- to point
// to the tree's root node
