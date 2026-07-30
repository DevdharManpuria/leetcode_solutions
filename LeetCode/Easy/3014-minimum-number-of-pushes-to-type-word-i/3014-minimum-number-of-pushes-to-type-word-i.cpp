class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans=0;
        int mult = 1;
        while(n>0){
            ans+= (n-8)>=0 ? (mult*8) : (mult*n);
            n-=8;
            mult++;
        }
        return ans;
    }
};