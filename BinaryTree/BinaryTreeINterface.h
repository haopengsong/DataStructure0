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
	
} 
