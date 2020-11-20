/* Partition the array into two regions: sorted and un-sorted
	- At each step, the insertion sort takes the first item of the unsorted
	region and places it into its correct position in the sorted region
	- Items in the sorted region are sorted among themselves
Main idea: take each item from the unsorted region and insert it into its
		   correct order in the sorted region.

*/