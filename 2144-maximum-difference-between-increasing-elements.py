class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        max_diff = -1
        min_val = nums[0]
        for j in range(1,len(nums)):
            if nums[j] > min_val:
                max_diff = max(max_diff, nums[j]-min_val)
            else:
                min_val = nums[j]
        return max_diff
