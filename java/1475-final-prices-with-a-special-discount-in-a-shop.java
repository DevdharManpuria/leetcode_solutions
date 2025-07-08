class Solution {
    public int[] finalPrices(int[] prices) {
        int len = prices.length;
        if(len == 0 || len == 1){
            return prices;
        }
        int[] ans = new int[len];
        for(int i=0; i<len; i++){
            ans[i] = prices[i] - findDiscount(prices, len, i+1);
        }
        return ans;
    }
    static int findDiscount(int[] a,int len, int j){
        if(j < len){
            for(int i=j; i<len; i++){
                if( a[i] <= a[j-1] ) {
                    return a[i];
                }
            }
        }
        return 0;
    }
}