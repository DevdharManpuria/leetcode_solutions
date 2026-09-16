const int MOD = 1000000007;
class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<int> dp(n),prefix(n+1);
        for(int j = 0;j<n;j++){
            dp[j] = 1;
            prefix[j+1] = (prefix[j]+dp[j]) % MOD;
        }
        for(int i=1;i<=k;i++){
            dp[0] = 0;
            for(int j = 1;j<n;j++){
                dp[j] = (dp[j-1] + prefix[j]) %MOD;
            }
            for(int j = 0;j<n;j++){
                prefix[j+1] = (prefix[j]+dp[j])%MOD;
            }
        }
        return dp[n-1];
    }
};