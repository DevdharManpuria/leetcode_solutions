class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int a=sum;
        int b=0;
        if(sum > (num*9)) return "";
        while(b < num && a>0){
            b++;
            int add = a >=9 ? 9 : a;
            ans+=to_string(add);
            a-=add;
        }
        while(b < num){
            ans+="0";
            b++;
        }
        return ans;
    }
};