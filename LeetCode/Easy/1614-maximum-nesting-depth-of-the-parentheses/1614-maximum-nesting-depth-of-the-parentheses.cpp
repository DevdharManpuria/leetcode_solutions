class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int cur=0;
        for(char c:s){
            if(c =='('){
                cur++;
                ans = max(ans,cur);
            }
            else if(c==')'){
                cur--;
                if(cur<0) return -1;
            }
        }
        return cur == 0 ? ans : -1;
    }
};