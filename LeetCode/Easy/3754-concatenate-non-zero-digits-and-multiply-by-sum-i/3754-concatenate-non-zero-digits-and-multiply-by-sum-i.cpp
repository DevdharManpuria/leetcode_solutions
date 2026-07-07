class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;
        long long mul=1;
        while(n>0){
            long long d=n%10;
            sum+= d;
            if(d>0){
                num+=d*mul;
                mul*=10;
            }
            n=n/10;
        }
        return sum*num;
    }
};