class Solution {
public:
    bool hasValidPath(vector<vector<char>>& a) {
        int m = a.size();
        int n = a[0].size();
        if((m+n-1)%2!=0 || a[0][0] == ')' || a[m-1][n-1] == '(') 
            return false;
        vector<bitset<105>> dp(n);
        dp[0].set(1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                bitset<105> cur;
                if(i>0) cur |= dp[j];
                if(j>0) cur |= dp[j-1];
                dp[j] = (a[i][j] == '(') ? (cur << 1) : (cur >> 1);
            }
        }
        return dp[n-1].test(0);
    }
};