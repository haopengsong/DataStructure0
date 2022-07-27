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

using namespace std;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// o(n)
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

/* 
Insert into Heap
1) Insert the new element at the end of the tree
2) Heapify the tree
*/
void insert( vector<int>& data, int newItem ) {
    int size = data.size();
    if ( size == 0 ) {
        data.push_back( newItem );
    } else {
        data.push_back( newItem );
        for ( int i = size / 2 - 1; i >= 0; i-- ) {
            heapify( data, i );
        } 
    }
}   

/*
Delete from Heap
1) Select the element to be deleted
2) Swap it with the last element
3) Remove the last element
4) Heapify the tree
*/
void deleteNode( vector<int>& data, int newItem ) {
    int size = data.size();
    int i;
    for ( i = 0; i < size; i++ ) {
        if ( newItem == data[ i ] ) {
            break;
        }
    }
    swap( &data[ i ], &data[ size - 1 ] );
    data.pop_back();
    for ( int i = size / 2 - 1; i >= 0; i-- ) {
        heapify( data, i );
    }
}

void printHeap( vector<int>& data ) {
    for ( int i = 0; i < data.size(); i++ ) {
        std::cout << data[ i ] << " ";
    }
    std::cout << "\n" ;
}

int main() {
    vector<int> heap;

    insert( heap, 3 );
    insert( heap, 4 );
    insert( heap, 9 );
    insert( heap, 5 );
    insert( heap, 2 );
    insert( heap, 8 );
    insert( heap, 0 );
    insert( heap, 12 );
    insert( heap, 8 );
    insert( heap, 1 );
     
    std::cout << "Max-Heap array : " ;
    printHeap( heap );
    deleteNode( heap, 9 );

    std::cout << "After deleting an element: "<< 9 << std::endl ;
    printHeap( heap );
    return 0;
}

// Reference: https://www.programiz.com/dsa/heap-data-structure









