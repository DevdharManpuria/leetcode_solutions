class Solution {
    public int findNumbers(int[] nums) {
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(countdig(nums[i])%2==0) cnt++;
        }
        return cnt;
    }
    public int countdig(int i){
        int a=0;
        while(i>0){
            a++;
            i=i/10;
        }
        return a;
    }
}