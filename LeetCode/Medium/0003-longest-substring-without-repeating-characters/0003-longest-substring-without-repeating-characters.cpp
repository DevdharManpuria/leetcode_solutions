class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> mp;
        int ans = 0;
        int left = 0;
        for(int right=0;right<s.size();right++){
            while(mp.find(s[right]) != mp.end()){
                mp.erase(mp.find(s[left]));
                left++;
            }
            mp.insert(s[right]);
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};