class Solution:
    def singleNumber(self, nums: List[int],a=0) -> int:
        return [a:= a^i for i in nums][-1]