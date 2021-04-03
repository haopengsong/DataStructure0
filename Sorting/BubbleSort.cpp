/* Bubble sort: compares adjacent items and exchanges them if they are out of order.
When you order successive pairs of items, the largest item bubbles to the top(end) of the array.

Although the array is not sorted after the first pass, the largest item has "bubbled" to its
proper position at the end of the array. During the second pass of the bubble sort, you return 
to the begining of the array and consider pairs of items in exactly the same manner as the first

Can terminate the process if no exchanges occur during any pass.

Analysis:
	- In the worst case, bubble sort will require a total of:
		(n - 1) + (n - 2) + ... + 1 = n * (n - 1) / 2 => O(n^2) comparisons and 
		Same number of exchanges. Each exchange requires 3 data moves => O(n^2)
	- The best case occurs when the original data is already sorted => O(n)
*/

#include <iostream>

using namespace std;

template<class ItemType>
class BubbleSort {
public:
    void bubbleSort(ItemType inputs[], int n) {
        bool sorted = false; // false when swaps occur
        int pass = 1;
        while (!sorted && (pass < n)) {
            // inputs[n + 1 - pass ... n - 1] is sorted
            // and all of its entries are > the entries in inputs[0 ... n - pass]
            sorted = true;
            for (int i = 0; i < n - pass; i++) {
                // at this point, all entries in inputs[0 ... i - 1]
                // are <= inputs[i]
                if (inputs[i] > inputs[i + 1]) {
                    // exchange entries
                    std::swap(inputs[i], inputs[i + 1]);
                    sorted = false; // signal exchange
                }
            }
            pass++;
        }
    }
};


int main(int argc, char const *argv[]) {
    BubbleSort<int> bs;
    int inputs[] = {1,9,5,0,200,-2};
    int size = sizeof(inputs) / sizeof(int);
    bs.bubbleSort(inputs, size);
    for (int i : inputs) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


















