class Solution:
    def findMissingElements(self, nums: list[int]) -> list[int]:
        if not nums:
            return []
        mn, mx = min(nums), max(nums)
        has = set(nums)
        return [x for x in range(mn + 1, mx) if x not in has]
