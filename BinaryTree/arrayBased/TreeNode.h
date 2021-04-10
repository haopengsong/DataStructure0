/*
An array-based implementation of a tree uses an array of nodes,
so a class of such trees could have the following data members:
    TreeNode<ItemType> tree[MAX_NODES]; // array of tree nodes
    int root; // index of root
    int free; // index of free list
The variable root is an index to the tree's root node within the array tree,
if the tree is empty, root is -1. 

As the tree changes due to additions and removals of its data, its nodes may not be in contiguous
elements of the array. Therefore, this implementation requires you to establish a collection of available nodes
which is called a 'free list'

To insert a new node into the tree, you first obtain an available node from the free list.
If you remove a node from the tree, you place it into the free list so that you can reuse the node at a later time.

An array-based implementation of a binary tree is much more attractive when the tree is complete
Priority-Queue
*/


template<class ItemType>
class TreeNode
{
private:
    ItemType item; // data portion
    int leftChild; // index to left child
    int rightChild; // index to right child
public:
    TreeNode();
    TreeNode(const ItemType& nodeItem, int left, int right);

    // declaration of the methods: setItem, getItem, setLeft, getLeft, setRight, and getRight
};
// end TreeNode
