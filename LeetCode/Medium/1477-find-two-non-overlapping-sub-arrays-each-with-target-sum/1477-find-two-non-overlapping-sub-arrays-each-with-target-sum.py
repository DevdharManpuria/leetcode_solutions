class Solution:
    def minSumOfLengths(self, a: List[int], t: int) -> int:
        n = len(a)
        ans = n+1
        s = 0
        l = 0
        dp = [n]*(n+1)
        for r in range(0,n):
            s+=a[r]
            while s>t:
                s-=a[l]
                l+=1
            dp[r+1] = dp[r]
            if s==t:
                ans = min(ans,dp[l]+(r-l+1))
                dp[r+1] = min(dp[r],r-l+1)
        if ans != n+1:
            return ans
        return -1
