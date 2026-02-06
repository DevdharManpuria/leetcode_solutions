class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        n,right,ans=len(nums),0,len(nums)
        for i in range(n):
            while right<n and nums[i]*k>=nums[right]:
                right+=1
            ans=min(ans,n-(right-i))
        return ans