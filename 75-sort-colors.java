class Solution {
    public void sortColors(int[] nums) {
        int sum0=0;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==0)
            sum0++;
            else if(nums[i]==1)
            sum1++;
            else
            sum2++;
        }
        for(int i=0;i<sum0;i++)
        nums[i]=0;
        for(int i=sum0;i<sum0+sum1;i++)
        nums[i]=1;
        for(int i=sum0+sum1;i<sum0+sum1+sum2;i++)
        nums[i]=2;
    }
}