class Solution:
    def maxRotateFunction(self, nums):
        n = len(nums)
        total_sum = sum(nums)
        F = sum(i * num for i, num in enumerate(nums))
        result = F
        for k in range(1, n):
            F = F + total_sum - n * nums[n - k]
            result = max(result, F)
        return result