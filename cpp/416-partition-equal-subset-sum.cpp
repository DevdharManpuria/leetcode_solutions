class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot =0;
        for(int num:nums) tot+=num;
        if(tot%2!=0) return false;
        int target =tot/2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
