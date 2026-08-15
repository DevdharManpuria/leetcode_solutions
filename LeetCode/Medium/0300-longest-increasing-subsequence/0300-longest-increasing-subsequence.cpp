class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    dp[i] = max(1+dp[j],dp[i]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};