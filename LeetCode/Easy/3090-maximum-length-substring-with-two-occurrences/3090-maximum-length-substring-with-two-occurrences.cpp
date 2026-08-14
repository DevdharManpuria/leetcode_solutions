class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,ans=0;
        unordered_map<char,int> fm;
        for(int i=0;i<s.size();i++){
            fm[s[i]]++;
            while(fm[s[i]]>2){
                fm[s[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};