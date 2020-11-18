/* Implementation of selection sort
Sorts the items in an array into ascending order.
main idea: select the largest item 
Analysis:
	- Time:
		- Total possible looping: (n - 1) + (n - 2) + ... + 1 = n * (n - 1) / 2 => O(n^2)
		- Each of the n - 1 calls to swap requires 3 assignments or data moves, so calls to 
		swap require 3 * (n - 1) moves

	- Algorithms requires o(n^2) comparisons, but only o(n) data moves
	- A good choice when data moves are costly but comparisons are not, such as
	when each data item is large but the sort key is short or an integer

*/

#include <iostream>

using namespace std;

template<class ItemType>
class SelectionSort {
private:
	int findIndexOfLargest(ItemType inputs[], int size) {
		int indexOfLargestSoFar = 0;
		for (int i = 1; i < size; i++) {
			if (inputs[i] > inputs[indexOfLargestSoFar]) {
				indexOfLargestSoFar = i;
			}
		}
		return indexOfLargestSoFar;
	}
	void selectionSort(ItemType inputs[], int size) {
		// last = index of the last item in the subarray of items yet to be sorted
		// largest = index of the largest item found
		for (int last = size - 1; last >= 1; last--) {
			// select the largest entry in inputs[0...last]
			int largest = findIndexOfLargest(inputs, last + 1);
			// swap the largest and last entry 
			std::swap(inputs[last], inputs[largest]);
		}
	}
public:
	void sort(ItemType inputs[], int size) {
		selectionSort(inputs, size);
	}
};

int main() {
	SelectionSort<int> ss;
	int inputs[] = {1,9,5,0,200,-2};
	int size = sizeof(inputs) / sizeof(int);
	ss.sort(inputs, size);
	for (int i : inputs) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
