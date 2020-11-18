/* Implementation of selection sort
Sorts the items in an array into ascending order.
main idea: select the largest item */

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
