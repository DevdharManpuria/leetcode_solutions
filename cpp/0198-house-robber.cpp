class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n);
        dp[0]=a[0];
        if(n>1) dp[1]=max(a[0],a[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        }
        return dp[n-1];
    }
};