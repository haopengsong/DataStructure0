/* Partition the array into two regions: sorted and un-sorted
	- At each step, the insertion sort takes the first item of the unsorted
	region and places it into its correct position in the sorted region
	- Items in the sorted region are sorted among themselves
Main idea: take each item from the unsorted region and insert it into its
		   correct order in the sorted region.
Analysis:
	Outer for loop in the function executes n - 1 times
		Inner while loop executes at most unsorted times for values range from 1 to n - 1
			worst case total comparsion occurs: 1 + 2 + ... + (n - 1) = n * (n - 1) / 2
	Outer loop moves data items twice per iteration = 2 * (n - 1)
	=> O(n^2)
*/

#include <iostream>

using namespace std;

template<class ItemType>
class InsertionSort {
public:
	void insertionSort(ItemType inputs[], int n) {
		/*
		unsorted = first index of the unsorted region
		loc = index of insertion in the sorted region
		nextItem = next item in the unsorted region
		initially, sorted region is inputs[0], unsorted region is inputs[0...n-1]
		in general, sorted region is inputs[0...unsorted-1], unsorted region inputs[unsorted...n-1]
		*/
		for (int unsorted = 1; unsorted < n; unsorted++) {
			/*
			At this point, inputs[0...unsorted-1] is sorted
			Find the right position (loc) in inputs[0...unsorted] for inputs[unsorted], which is the first entry in the unsorted region; shift, if
			necessary, to make room
			*/
			ItemType nextItem = inputs[unsorted]; // copy item
			int loc = unsorted;
			while ((loc > 0) && (inputs[loc - 1] > nextItem)) {
				/* shift inputs[loc - 1] to the right */
				inputs[loc] = inputs[loc - 1];
				loc--;
			}
			inputs[loc] = nextItem;
		}
	}
};


int main(int argc, char const *argv[]) {
	InsertionSort<int> is;
	int inputs[] = {1,9,5,0,200,-2};
	int size = sizeof(inputs) / sizeof(int);
	is.insertionSort(inputs, size);
	for (int i : inputs) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
