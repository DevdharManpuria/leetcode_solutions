class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        ma,xo = 0,0
        for i in nums:
            ma = max(ma,i)
            xo ^= i
        return 0 if ma == 0 else len(nums)-1 if xo == 0 else len(nums)