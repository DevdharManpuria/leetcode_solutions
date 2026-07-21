class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), cnt1 = count(s.begin(),s.end(),'1'), i = 0, best = 0, prev = INT_MIN, cur = 0;
        while(i<n){
            int start = i;
            while(i<n && s[i] == s[start])
                ++i;
            if(s[start] == '0'){
                cur = i - start;
                best = max(best,prev+cur);
                prev = cur;
            }
        }
        return cnt1 + best;
    }
};