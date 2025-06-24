class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
    int helper(vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) {
            return currentXOR;
        }
        int with = helper(nums, index + 1, currentXOR ^ nums[index]);
        int without = helper(nums, index + 1, currentXOR);
        return with + without;
    }
};
