/** Interface for the ADT binary tree **/

#ifndef BINARY_TREE_INTERFACE_
#define BINARY_TREE_INTERFACE_
#include "NotFoundException.h"

template<class ItemType>
class BinaryTreeInterface {
public:
    // whether the tree is empty 
    virtual bool isEmpty() const = 0;

    // gets the height of this binary tree
    virtual int getHeight() const = 0;

    // gets the number of nodes in this binary tree
    virtual int getNumberOfNodes() const = 0;

    // gets the data that is in the root of this binary tree
    // 1) the binary tree is not empty. 2) the root's data has been returned, the binary tree is unchanged
    virtual ItemType getRootData() const = 0;

    // replaces the data in the root of this binary tree with the given data, if the tree is not empty
    // if the tree is empty, inserts a new root node containing the given data into the tree
    virtual void setRootData(const ItemType& newData) = 0;
    
    // adds the given data to this binary tree
    virtual bool add(const ItemType& newData) = 0;

    // removes the specified data from this binary tree
    virtual bool remove(const ItemType& target) = 0;

    // removes all data from this binary tree
    virtual void clear() = 0;
    
    // retrieves the specified data from this binary tree
    virtual ItemType getEntry(const ItemType& target) const = 0;

    // tests whether the specified data occurs in this binary tree
    virtual bool contains(const ItemType& target) const = 0;

    // traverses this binary tree in preorder, inorder, postorder and calls the function visit once for each node
    virtual void preorderTraverse(void visit(ItemType&)) const = 0;
    virtual void inorderTraverse(void visit(ItemType&)) const = 0;
    virtual void postorderTraverse(void visit(ItemType&)) const = 0;

    // destroys this tree and frees its assigned memory
    virtual ~BinaryTreeInterface() { }
};
#endif
