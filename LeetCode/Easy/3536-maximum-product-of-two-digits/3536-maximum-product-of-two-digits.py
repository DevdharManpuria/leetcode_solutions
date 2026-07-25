class Solution:
    def maxProduct(self, n: int) -> int:
        return int(sorted(str(n))[-1]) * int(sorted(str(n))[-2]) 
        
