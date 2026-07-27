class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1, max2 = heapq.nlargest(2, nums)
        return (max1 - 1) * (max2 - 1)