// constructors
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{

}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{

}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                        const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                                        const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, copyTree(leftTreePtr->rootPtr),
                                                               copyTree(rightTreePtr->rootPtr))
{

}

// copy constructor
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr) 
{
    rootPtr = copyTree(treePtr.rootPtr); 
}

// copy tree using PREORDER traversal
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
    std::shared_ptr<BinaryNode<ItemType>> newRoot;
    // copy tree node during preorder traversal
    
    if (oldTreeRootPtr != nullptr) {
        // copy node
        newRoot = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(),
                                                        nullptr, nullptr);
        newRoot->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        newRoot->setLeftChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
    }
    return newRoot;
}

// delete tree using POSTORDER traversal
// because you can delete a node only after you have first traversed and deleted both of its subtrees
template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if (subTreePtr != nullptr) {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        subTreePtr.reset();     // Decrement reference count to node
    }
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const 
{
    return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if (subTreePtr == nullptr) {
        return 0;
    } else {
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                            getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {
    auto nNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = balancedAdd(rootPtr, nNodePtr);
    return true;
} // end add

// The recursive call to balancedAdd adds the new node and returns a pointer to the revised subtree
// Then we need to link this subtree to the rest of the tree by setRight/LeftChildPtr .
template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                            std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    if (subTreePtr == nullptr) {
        return newNodePtr;
    } else {
        auto leftPtr = subTreePtr->getLeftChildPtr();
        auto rightPtr = subTreePtr->getRightChildPtr();
        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
            rightPtr = balancedAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        } else {
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        }
        return subTreePtr;
    }
}





















