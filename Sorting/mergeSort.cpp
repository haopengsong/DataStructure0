class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return nums;
        }
        int n = nums.size();
        vector<int> res(n, 0);
        mergeSort(nums, res, 0, n - 1);
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, vector<int>& res, int l, int r) {
        if (l >= r) {
            return;
        } 
        int mid = l + ((r - l) >> 1);
        mergeSort(nums, res, l, mid);
        mergeSort(nums, res, mid + 1, r);
        merge(nums, res, l, mid, r);
    }
    void merge(vector<int>& nums, vector<int>& res, int start, int mid, int end) {
        int leftIndex = start;
        int rightIndex = mid + 1;
        int index = start;
        
        while (leftIndex <= mid && rightIndex <= end) {
            if (nums[leftIndex] > nums[rightIndex]) {
                res[index++] = nums[rightIndex++];
            } else {
                res[index++] = nums[leftIndex++];
            }
        }
        while (leftIndex <= mid) {
            res[index++] = nums[leftIndex++];
        }
        while (rightIndex <= end) {
            res[index++] = nums[rightIndex++];
        }
        for (int i = start; i <= end; i++) {
            nums[i] = res[i];
        }
    }
};