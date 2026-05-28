class Solution {
public:
    int binarySearch(const vector<int>& arr, int start, int end, int target) {
        int low = start;
        int high = end;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) 
                return mid; 
            if (arr[mid] < target) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1; 
    }
    int rot(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();   
        if(n == 1) return nums[0] == target ? 0 : -1; 
        int pivotIndex = rot(nums);
        if(target > nums.back()) 
            return binarySearch(nums, 0, pivotIndex - 1, target); 
        else 
            return binarySearch(nums, pivotIndex, n - 1, target); 
    }
};