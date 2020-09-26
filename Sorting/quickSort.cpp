// worst case : when each selected pivot is the 'greatest' or 'smallest' element and this pattern repeats 
// because in this case the algorithm will only have
// one group to sort with everything in that group other than the original pivot
// this will give n groups and each needs to iterate n times, thus n^2 complexity

// The most common reason for this occurring is if the pivot is chosen to be 
// the first or last element in the list in the quicksort implementation.
class Solution {
public:
	void sort(vector<int>& nums) {
		if (nums.size() == 0) return;
		quickSort(nums, 0, nums.size() - 1);
	}
private:
	void quickSort(vector<int>& nums, int l, int r) {
		if (l >= r) {
			return;
		}

		int start = l, end = r;
		int pivot = nums[(l + r) >> 1];

		while (start <= end) {
			// 遍历pivot左边，直到找到第一个比pivot大的数
			while (start <= end && nums[start] < pivot) {
				start++;
			}
			// 遍历pivot右边，直到找到第一个比pivot小的数
			while (start <= end && nums[end] > pivot) {
				end--;
			}
			// 交换这两个数
			if (start <= end) {
				int temp = nums[start];
				nums[start] = nums[end];
				nums[end] = temp;
				start++;
				end--;
			}
		}
		quickSort(nums, l,   end);
		quickSort(nums, start, r);
	}
}
