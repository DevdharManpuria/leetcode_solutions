class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> cur;
        int ans = 0;
        int left = 0;
        for(int i=0;i<s.size();i++){
            while(cur.find(s[i]) != cur.end()){
                cur.erase(s[left]);
                left++;
            }
            cur.insert(s[i]);
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};