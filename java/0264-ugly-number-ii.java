class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        int i2=0,i3=0,i5=0; 
        dp[0] = 1;
        for(int i=1 ;i<n;i++){
            dp[i] = Math.min(2*dp[i2],3*dp[i3]);
            dp[i] = Math.min(dp[i], 5*dp[i5]);
            if(dp[i] == 2*dp[i2]) i2++;
            if(dp[i] == 3*dp[i3]) i3++;
            if(dp[i] == 5*dp[i5]) i5++;
        }
        return dp[n-1];
    }
}