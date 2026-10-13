class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        arr = sorted(n * n for n in nums)
        return sum(arr[len(arr)//2:]) - sum(arr[:len(arr)//2])