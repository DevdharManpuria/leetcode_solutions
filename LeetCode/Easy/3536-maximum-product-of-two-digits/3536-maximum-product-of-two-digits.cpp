class Solution {
public:
    int maxProduct(int n) {
        int s = 0,ss = 0;
        while(n>0){
            int d = n%10;
            if(d > s){
                ss = s;
                s = d;
            }
            else if(d <= s && d > ss) ss = d;
            n=n/10;
        }
        return s*ss;
    }
};