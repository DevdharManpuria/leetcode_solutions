class Solution:
    def uniquePathsWithObstacles(self, obs):
        m, n = len(obs), len(obs[0])
        if obs[0][0] == 1:
            return 0
        dp = [0] * n
        dp[0] = 1
        for i in range(m):
            for j in range(n):
                if obs[i][j] == 1:
                    dp[j] = 0
                elif j > 0:
                    dp[j] += dp[j - 1]
        return dp[-1]
