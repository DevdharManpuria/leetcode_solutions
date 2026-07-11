class Solution {
    public int hammingWeight(int n) {
        int cnt=0;
        while(n>0){
            cnt += n%2!=0 ? 1 : 0;
            n/=2;
        }
        return cnt;
    }
}