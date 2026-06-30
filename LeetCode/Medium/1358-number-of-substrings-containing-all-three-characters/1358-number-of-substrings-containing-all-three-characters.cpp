class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int left = 0;
        int cnt=0;
        mp={{'a',0},{'b',0},{'c',0}};
        for(int r=0;r<=s.length();r++){
            mp[s[r]]++;
            while(mp['a']>0 && mp['b'] > 0 && mp['c'] > 0){
                cnt+=s.length()-r;
                mp[s[left]]--;
                left++;
            }
        }
        return cnt;
    }
};