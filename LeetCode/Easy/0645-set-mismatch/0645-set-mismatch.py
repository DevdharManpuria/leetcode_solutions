class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        return [sum(nums) - sum(set(nums)), sum(range(1, len(nums) + 1)) - sum(set(nums))]
