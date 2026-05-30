class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        set<char> se;
        int left=0;
        for(int right=0;right<s.length();right++){
            while(se.find(s[right])!=se.end()){
                se.erase(s[left]);
                left++;
            }
            se.insert(s[right]);
            ans=max(ans,(right-left+1));
        }
        return ans;
    }
};