class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n + 1, 0);        
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> maxL(n, vector<int>(n, 0));
        vector<vector<int>> maxR(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            maxL[i][i] = stoneValue[i];
            maxR[i][i] = stoneValue[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            int mid = i;   
            for(int j = i + 1; j < n; j++) {
                int totalSum = pref[j + 1] - pref[i];
                while (mid < j && (pref[mid + 1] - pref[i]) * 2 < totalSum) mid++;
                int leftSum = pref[mid + 1] - pref[i];
                bool isEqual = (leftSum * 2 == totalSum);
                int maxLeftChoices = isEqual ? mid : mid - 1;
                if (maxLeftChoices >= i) dp[i][j] = max(dp[i][j], maxL[i][maxLeftChoices]);
                if (mid < j) dp[i][j] = max(dp[i][j], maxR[mid + 1][j]);
                maxL[i][j] = max(maxL[i][j - 1], dp[i][j] + totalSum);
                maxR[i][j] = max(maxR[i + 1][j], dp[i][j] + totalSum);
            }
        }
        return dp[0][n - 1];
    }
};