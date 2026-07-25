class Solution:
    def maxProduct(self, n: int) -> int:
        return int(s[-1]) * int(s[-2]) if len(s := sorted(str(n))) >= 2 else 0
