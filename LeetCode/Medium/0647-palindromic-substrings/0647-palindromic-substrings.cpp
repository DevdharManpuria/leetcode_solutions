class Solution {
public:
    int expand(string &s,int l ,int r){
        int ans=0;
        while(l>=0 && r <s.size() && s[l] == s[r]){
            ans++;
            l--;
            r++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans += expand(s,i,i);
            ans += expand(s,i,i+1);
        }
        return ans;
    }
};