class Solution {
    public int uniquePathsWithObstacles(int[][] obs) {
        int m = obs.length, n = obs[0].length;
        if (obs[0][0] == 1) return 0; 
        int[] dp = new int[n];
        dp[0] = 1; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obs[i][j] == 1) {
                    dp[j] = 0; 
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; 
                }
            }
        }
        return dp[n - 1];
    }
}
