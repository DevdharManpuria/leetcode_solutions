class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(!isdiv(i,t))
            i++;
        return i;
    }
    bool isdiv(int a,int b){
        int prdt=1;
        while (a){
            prdt*=(a%10);
            a/=10;
        }
        return prdt%b==0 ? true : false;
    }
};