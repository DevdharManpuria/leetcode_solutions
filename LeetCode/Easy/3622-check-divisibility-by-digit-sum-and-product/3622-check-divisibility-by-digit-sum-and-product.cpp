class Solution {
public:
    bool checkDivisibility(int n) {
        int su = 0, prdt=1, copy = n;
        while(n>0){
            su+=(n%10);
            prdt*=(n%10);
            n/=10;
        }
        return copy % (su+prdt) == 0;
    }
};