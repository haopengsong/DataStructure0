/*
Max-Heap:
Any given node is always greater than its child node/s and the key of the root node
is the largest among all other nodes.

Min-Heap:
Any given node is always smaller than the child node/s and the key of the root node
is the smallest among all other nodes.

Heapify:
The process of creating a heap data structure from a binary tree.
1) Start from the first index of non-leaf node whose index is given by (n/2 - 1)
2) Set the current element i as largest
3) The index of left child is given by 2i + 1 and the right child is given by 2i + 2
    - If leftChild is greater than currentElement (element at ith index), set leftChildInd      ex as largest; If rightChild is greater than element in largest, set rightChildIndex      as largest;
4) Swap largest with currentElement
5) Repeat 1) - 5)
*/

#include <iostream>
#include <vector>

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify( vector<int> &data, int i ) {
    int size = data.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if ( l < size && data[ l ] > data[ largest ] ) {
        largest = l;
    } 
    if ( r < size && data[ r ] > data[ largest ] ) {
        largest = r;
    }
    if ( largest != i ) {
        swap( &data[ i ], &data[ largest ] );
        heapify( data, largest );
    }
}

void heapifyNonRecursive( vector<int>& data, int i ) {
    int size = data.size();
    while ( i < size ) { 
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if ( l < size && data[ l ] > data[ largest ] ) {
            largest = l;
        }
        if ( r < size && data[ r ] > data[ largest ] ) {
            largest = r;
        }
        if ( largest != i ) { 
            swap( &data[ i ], &data[ largest ] );
            i = largest; 
        } else {
            break;
        }
    }
}

