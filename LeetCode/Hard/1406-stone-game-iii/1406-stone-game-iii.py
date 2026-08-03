class Solution:
    def stoneGameIII(self, A: List[int]) -> str:
        n = len(A)
        dp = [0] * (n+1)
        for i in range(n-1,-1,-1):
            dp[i] = A[i] - dp[i+1]
            if i+2<=n:
                dp[i] = max(dp[i],A[i]+A[i+1] - dp[i+2])
            if i+3<=n:
                dp[i] = max(dp[i],A[i]+A[i+1]+A[i+2] - dp[i+3])
        if dp[0]==0:
            return "Tie"
        return "Alice" if dp[0]>0 else "Bob"