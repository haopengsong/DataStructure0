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
protected:
    // Protected utility methods
    // recursive helper methods for the public methods
    // These methods require pointers as arguments, as such, they should not be public and available to clients of the class
    // Clients should not have access to node pointers
public:
    BinaryNode(); // define a tree that is empty: BinaryNodeTree<std::string> tree1;
    BinaryNode(const ItemType& anitem); // auto tree2 = std::make_shared<BinaryNodeTree<std::string>>("A");
    BinaryNode(const ItemType& anitem, std::shared_ptr<BinaryNode<ItemType>> leftPtr,
                                       std::shared_ptr<BinaryNode<ItemType>> rightPtr);
                                        // auto tree3 = std::make_shared<BinaryNodeTree<std::string>>("B")i;
                                        // auto tree4 = std::make_shared<BinaryNodeTree<std::string>>("C");
                                        // auto tree1 = std::make_shared<BinaryNodeTree<std::string>>("C", tree3, tree4); 
    
    
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
