class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int m = nums.size();
        for(int i=0;i<nums.size();++i)
            m ^= i^nums[i];
        return m;
    }
};