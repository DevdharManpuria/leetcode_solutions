class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        m = len(nums)
        for i,num in enumerate(nums):
            m ^= i ^ num
        return m