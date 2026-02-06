class Solution {
    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums);
        int n=nums.length;
        int right = 0,ans=n;
        for(int i=0;i<n;i++){
            while(right<n && (long)nums[i]*k >= nums[right]) right++;
            ans=Math.min(ans,n-(right-i));
        }
        return ans;
    }
}