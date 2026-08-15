class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i]>dp.back()){
                dp.push_back(nums[i]);
                continue;
            }
            int j = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
            dp[j] = nums[i];
        }
        return dp.size();
    }
};