class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> prefix(n+1);
        prefix[0] = 0;
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i]+stoneValue[i];
        }
        int lsum=0;
        int rsum =0;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                int end = i+j-1;
                for(int k = j;k<=end-1;k++){
                    lsum = prefix[k+1] - prefix[j];
                    rsum = prefix[end+1] - prefix[k+1];
                    if(lsum<rsum) dp[j][end]=max(dp[j][end],lsum+dp[j][k]);
                    else if(lsum>rsum) dp[j][end] = max(dp[j][end],rsum+dp[k+1][end]);
                    else dp[j][end] = max(dp[j][end],lsum+max(dp[j][k],dp[k+1][end]));
                }
            }
        }
        return dp[0][n-1];
    }
};