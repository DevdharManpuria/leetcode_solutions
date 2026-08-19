class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        int mp[26] = {0};
        for(char c : s) mp[c-'a']++;
        for(char c : t) mp[c-'a']--;
        for(int i : mp) if(i!=0) return false;
        return true;
    }
};