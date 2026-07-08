class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int r = 0, m = 0;
        for (int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            if (nums[val - 1] < 0)
                r = val;
            else
                nums[val - 1] = -nums[val - 1];   
        }
        for (int i = 0; i < nums.size(); i++) 
            if (nums[i] > 0) m = i + 1; 
        return {r, m};
    }
};