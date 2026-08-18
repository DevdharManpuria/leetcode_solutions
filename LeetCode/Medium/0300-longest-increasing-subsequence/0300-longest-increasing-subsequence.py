class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [nums[0]]
        for i in range(1,len(nums)):
            if dp[-1] < nums[i]:
                dp.append(nums[i])
                continue
            j = bisect.bisect_left(dp, nums[i])
            dp[j] = nums[i]
        return len(dp)