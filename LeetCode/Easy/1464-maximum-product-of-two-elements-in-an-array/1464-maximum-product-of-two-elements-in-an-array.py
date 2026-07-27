class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1 = 1
        max2 = 1
        
        for ele in nums:
            if max1 <= ele:
                max2 = max1
                max1 = ele
            elif max2 <= ele:
                max2 = ele
                
        return (max1 - 1) * (max2 - 1)