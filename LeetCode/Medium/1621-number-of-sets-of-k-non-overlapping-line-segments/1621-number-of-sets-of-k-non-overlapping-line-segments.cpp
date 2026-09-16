class Solution {
public:
    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int K = 2 * k;        
        if (N < K) return 0;
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(i, K); j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
            }
        }
        return dp[N][K];
    }
};