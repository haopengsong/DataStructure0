/** ADT Binary tree: link-based implementation */

#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <memory>

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;
protected:
    // Protected utility methods
    // recursive helper methods for the public methods
    // These methods require pointers as arguments, as such, they should not be public and available to clients of the class
    // Clients should not have access to node pointers

    // helper methods for public methods
    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    int getNumberOfNOdesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    // recursively adds a new node to the tree in a left/right fashion to keep tree balanced
    auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, 
                    std::shared_ptr<BinaryNode<ItemType>> newNodePtr); 

    // removes the target value from the tree
    virtual auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                            const ItemType target, bool &isSuccessful);

    // copies values up the tree to overwrite value in current node until
    // a leaf is reached; the leaf is then removed, since its value is stored in the parent
    auto moveValuesTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

    // recursively searches for target value
    virtual auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                            const ItemType &target, bool &isSuccessful) const;

    // copies the tree rooted at treePtr and returns a pointer to the root of the copy
    auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

    // recursively deletes all nodes from the tree
    void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

    // recursive traversal helper methods
    void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
    void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
    void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
public:
    // Constructor & Destructor Section
    BinaryNodeTree();
    BinaryNodeTree(const ItemType &rootItem);
    BinaryNodeTree(const ItemType &rootItem,
                        const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                        const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
    BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>> &tree);
    virtual ~BinaryNodeTree();
    
    // Public BinaryTreeInterface methods section
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const throw(PrecondViolatedExcept);
    void setRootData() const throw(PrecondViolatedExcept);
    bool add(const ItemType &newData); // adds an item to the tree
    bool remove(const ItemType &data); // removes specified item from the tree
    void clear();
    ItemType getEntry(const ItemType &entry) const throw(NotFoundException);
    bool contains(const ItemTYpe &entry) const;

    // public traversals section
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

    // overloaded operator section
    // we may also need to overload other operators
    BinaryNodeTree& operator=(const BinaryNodeTree &rightHandSide);
}; // end BinaryNodeTree
#include "BinaryNodeTree.cpp"
#endif




























